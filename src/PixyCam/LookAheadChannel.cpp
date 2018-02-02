/******************************************************************************
*																			  *
*	Serial/LookAheadChannel.cpp - Definition of class						  *
*	PixyCam::LookAheadChannel.												  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#include <algorithm>
#include <array>
#include "LookAheadChannel.h"

using namespace PixyCam;
using namespace std;

// Peek bytes
size_t LookAheadChannel::Peek(uint8_t* buffer, size_t count)
{
	// If our input buffer doesn't have enough bytes to cover to peek size, try to populate it.
	// Read fragments sequentially until our _inputBuffer is big enough
	while (_inputBuffer.size() < count)	
	{
		array<uint8_t, 16>		fragment;								// Will hold the fragment
		auto					fragmentRead{ _source->Read(fragment.data(), min(count - _inputBuffer.size(),fragment.size())) };	// Read the fragment
		if (fragmentRead <= 0)											// If no fragment data read
			break;														// Drop out
		_inputBuffer.insert(_inputBuffer.end(), fragment.begin(), fragment.begin() + fragmentRead);	// Add to the input buffer
	}
	auto	result{ min(_inputBuffer.size(), count) };					// Figure out how much data we will copy
	copy(_inputBuffer.begin(), _inputBuffer.begin() + result, buffer);	// Copy the data
	return result;														// Done
}

// Read bytes
size_t LookAheadChannel::Read(uint8_t* buffer, size_t count)
{
	auto	inputBufferCount{ min(_inputBuffer.size(), count) };						// The number of bytes to copy from the input buffer.
	copy(_inputBuffer.begin(), _inputBuffer.begin() + inputBufferCount, buffer);		// Copy from input buffer to target buffer.
	_inputBuffer.erase(_inputBuffer.begin(), _inputBuffer.begin() + inputBufferCount);	// Remove copied bytes from the input buffer
	buffer += inputBufferCount;															// Move the caller buffer forward
	count -= inputBufferCount;															// Decrement the remaining count
	return inputBufferCount + ((count != 0) ? _source->Read(buffer, count) : 0);		// Get the rest from our source if needed
}
