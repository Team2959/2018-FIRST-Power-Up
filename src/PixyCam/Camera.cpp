/******************************************************************************
*																			  *
*	PixyCam/Camera.cpp - Definition of class PixyCam::Camera.				  *
*																			  *
*	The code here is adapted from:											  *
*	http://cmucam.org/projects/cmucam5/wiki/Porting_Guide					  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#include <array>
#include "Camera.h"

using namespace PixyCam;
using namespace std;

const uint16_t BlockSync{ 0xAA55 };		// Sync word for a block
const uint16_t ColorCodeSync{ 0xAA56 };	// Sync word for a color code block

// See if start of frame
bool Camera::IsStartOfFrame(const array<uint16_t, 2>& words) { return (words[0] == BlockSync) && ((words[1] == BlockSync) || (words[1] == ColorCodeSync)); }	// Test for appropriate words

// Peek a word
bool Camera::PeekWord(uint16_t& word) { return _channel.Peek(reinterpret_cast<uint8_t*>(&word), sizeof(word)) == sizeof(word); }	// Success iff we can peek a word

// Read a word
bool Camera::ReadWord(uint16_t& word) { return _channel.Read(reinterpret_cast<uint8_t*>(&word), sizeof(word)) == sizeof(word); }	// Success iff we can read a word

// Write the buffer
bool Camera::Write(const initializer_list<uint8_t>& buffer) { return _channel.Write(buffer.begin(), buffer.size()) == buffer.size(); }	// Succcess iff we write the entire buffer

// Get blocks for a frame
vector<Block> Camera::ReadFrameBlocks()
{
	if (!SyncStartOfFrame())												// If we can't sync to start of frame
		return vector<Block>();												// Done.  Return empty vector
	array<uint16_t, 2>	words;												// Will hold words for reading
	if (!ReadWord(words[0]) || (words[0] != BlockSync))						// If we can't read the frame sync word
		return vector<Block>();												// Done.  Return empty vector
	vector<Block>	blocks;													// Will hold the blocks that we read
	// Continue the while forever...will drop out when we can't peek at the initial bytes, if we find a start of frame, or if we can't read a block word
	while (true)
	{
		if (!PeekWords(words) || IsStartOfFrame(words))						// If we can't peek the next two words, or the next two words are start of frame
			return blocks;													// Then we are done
		switch (words[0])													// See what kind of block
		{
		case BlockSync:														// If a standard block
		{
			array<uint16_t, 7>	blockWords;									// Will hold all the words for our block
			for (auto i = blockWords.begin(); i != blockWords.end(); ++i)	// Iterate over the block words
				if (!ReadWord(*i))											// If can't read it
					return blocks;											// Done
			blocks.emplace_back(blockWords[0], blockWords[1], blockWords[2], blockWords[3], blockWords[4], blockWords[5], blockWords[6]);	// Add the block to the vector
		}
		continue;
		case ColorCodeSync:													// If a color code block, same as above but with an additional word
		{
			array<uint16_t, 8>	blockWords;									// Will hold all the words for our block
			for (auto i = blockWords.begin(); i != blockWords.end(); ++i)	// Iterate over the block words
				if (!ReadWord(*i))											// If can't read it
					return blocks;											// Done
			blocks.emplace_back(blockWords[0], blockWords[1], blockWords[2], blockWords[3], blockWords[4], blockWords[5], blockWords[6], blockWords[7]);	// Add the block to the vector
		}
		continue;
		default:															// Anything else, we don't recognize
			return blocks;													// Done
		}
	}
}

// Set camera brightness
bool Camera::SetBrightness(uint8_t brightness)
{
	const uint16_t BrightnessSync{ 0xFE };	// Sync word indicating brightness byte follows
	return Write({ GetLowByte(BrightnessSync), GetHighByte(BrightnessSync), brightness });	// Form and write the buffer
}

// Set LED colors
bool Camera::SetLED(uint8_t red, uint8_t green, uint8_t blue)
{
	const uint16_t LEDSync{ 0xFD };	// Sync word indicating three LED color channel bytes follow
	return Write({ GetLowByte(LEDSync), GetHighByte(LEDSync), red, green, blue });	// Form and write the buffer
}

// Set servo positions
bool Camera::SetServos(uint16_t s0, uint16_t s1)
{
	const uint16_t ServoSync{ 0xFF };	// Sync word indicating two servo position words follow
	return Write({ GetLowByte(ServoSync), GetHighByte(ServoSync), GetLowByte(s0), GetHighByte(s0), GetLowByte(s1), GetHighByte(s1) });	// Form and write the buffer
}

// Sync to the start of frame
bool Camera::SyncStartOfFrame()
{
	array<uint16_t, 2>	words;							// Will hold words for testing start of frame
	if (!PeekWords(words))								// If we can't peek enough words for the start of frame
		return false;									// Then unsuccessful
	while (!IsStartOfFrame(words))						// While not start of frame
	{
		if(!ReadWord(words[0])||!PeekWords(words))		// If we can't read a word, nor peek the next pair
			return false;								// Then unsuccessful
	}
	return true;										// If we get here, then we are at the start of frame
}

