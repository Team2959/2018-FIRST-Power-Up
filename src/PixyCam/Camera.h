/******************************************************************************
*																			  *
*	PixyCam/Camera.h - Declaration of class PixyCam::Camera.				  *
*																			  *
*	PixyCam::Camera supports the functionality of the PixyCam hardware over	  *
*	a provided serial interface.											  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#pragma once

#include <memory>
#include <vector>
#include "Block.h"
#include "LookAheadChannel.h"

namespace PixyCam
{
	class Camera
	{
	public:
		Camera(std::unique_ptr<Channel> channel) : _channel{ std::move(channel) } { }	// Constructor
		std::vector<Block> ReadFrameBlocks();								// Read blocks for a frame
		bool SetServos(uint16_t s0, uint16_t s1);							// Set servo positions
		bool SetBrightness(uint8_t brightness);								// Set camera brightness
		bool SetLED(uint8_t red, uint8_t green, uint8_t blue);				// Set LED colors

	private:
		static constexpr uint8_t GetLowByte(uint16_t value) { return value & 0xFF; }			// Get the low byte of the 16-bit value
		static constexpr uint8_t GetHighByte(uint16_t value) { return (value >> 8) & 0xFF; }	// Get the high byte of the 16-bit value

		static bool IsStartOfFrame(const std::array<uint16_t, 2>& words);	// See if start of frame
		template<size_t N> bool PeekWords(std::array<uint16_t, N>& words);	// Peek N words
		bool PeekWord(uint16_t& word);										// Peek a word
		bool ReadWord(uint16_t& word);										// Read a word
		bool Write(const std::initializer_list<uint8_t>& buffer);			// Write the buffer
		bool SyncStartOfFrame();											// Sync to the start of frame

		LookAheadChannel	_channel;										// Our comm channel
	};

	// Peek N words
	template<size_t N> bool Camera::PeekWords(std::array<uint16_t, N>& words)
	{
		return _channel.Peek(reinterpret_cast<uint8_t*>(&words[0]), sizeof(uint16_t) * words.size()) == (sizeof(uint16_t) * words.size());	// Success iff we can peek enough bytes
	}
}
