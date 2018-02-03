/******************************************************************************
*																			  *
*	PixyCam/LookAheadChannel.h - Declaration of class						  *
*	PixyCam::LookAheadChannel.												  *
*																			  *
*	PixyCam::LookAheadChannel is an implementation of PixyCam::Channel, that  *
*	adds the ability to peek at upcoming bytes.								  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-28													  *
*																			  *
******************************************************************************/

#ifndef SRC_LOOK_AHEAD_CHANNEL_H_
#define SRC_LOOK_AHEAD_CHANNEL_H_

#include <deque>
#include <memory>
#include "Channel.h"

namespace PixyCam
{
	class LookAheadChannel : public Channel
	{
	public:
		LookAheadChannel(std::unique_ptr<Channel> source) : _source{ std::move(source) } { }							// Constructor
		virtual size_t Write(const uint8_t* buffer, size_t count) override { return _source->Write(buffer, count); }	// Write bytes.  Just delegate to source
		size_t Peek(uint8_t* buffer, size_t count);						// Peek bytes
		virtual size_t Read(uint8_t* buffer, size_t count) override;	// Read bytes

	private:
		std::unique_ptr<Channel>	_source;							// Source channel
		std::deque<uint8_t>			_inputBuffer;						// Our input buffer
	};
};

#endif /* SRC_LOOK_AHEAD_CHANNEL_H_ */
