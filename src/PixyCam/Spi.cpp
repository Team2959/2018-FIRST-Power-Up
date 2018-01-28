/******************************************************************************
*																			  *
*	PixyCam/Spi.cpp - Definition of class PixyCam::Spi.						  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#include <iterator>
#include "Spi.h"

using namespace PixyCam;
using namespace std;

// Get the next word to write so that we can read a word
uint16_t Spi::GetNextWordToWrite()
{
	const uint8_t	SyncByte{ 0x5A };		// Sync byte with no data payload following
	const uint8_t	SyncDataByte{ 0x5B };	// Sync byte with data payload following
	if (_writeQueue.empty())				// If no data to write
		return (SyncByte | (0x00 << 8));	// Write a sync byte (low) and zero (high)
	uint16_t result{ static_cast<uint16_t>(SyncDataByte | (_writeQueue.front() << 8)) };	// Write data sync byte (low) and data (high)
	_writeQueue.pop();						// Remove the byte we are writing
	return result;							// Done
}

// Read bytes
size_t Spi::Read(uint8_t* buffer, size_t count)
{
	// SPI is a bit complicated...
	// - SPI reads & writes at the same time...to read we must write.
	// - Every-other byte sent must be a sync byte
	// - It reads/writes only 16-bit big-endian words.
	if ((count % 2) == 1)							// If an odd number of bytes
		--count;									// Decrement so that we have an even number of bytes (and thus an integral number of words) to write
	auto result{ 0U };								// Our result value
	while (count >= 2)								// While we have space for a word
	{
		auto	word{ GetNextWordToWrite() };		// Get a word to write
		if (_spi.Transaction(reinterpret_cast<uint8_t*>(&word), buffer, sizeof(word)) != sizeof(word))	// If don't read/write the right number of bytes
			return result;							// Done
		swap(buffer[0], buffer[1]);					// Swap bytes (go from big-endian to little-endian)
		count -= sizeof(word);						// Decrement our count
		result += sizeof(word);						// Increment our result
	}
	return result;									// Done
}

// Write bytes
size_t Spi::Write(const uint8_t* buffer, size_t count)
{
	copy(buffer, buffer + count, back_inserter(_writeQueue));	// Copy to the write queue
	return count;												// Done
}
