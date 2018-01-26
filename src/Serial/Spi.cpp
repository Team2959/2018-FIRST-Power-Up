/******************************************************************************
*																			  *
*	Serial/Spi.cpp - Definition of class Spi.								  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#include <stdexcept>
#include "Spi.h"

// Constructor
Spi::Spi(frc::SPI::Port port) : _spi{ port } { }

// Send bytes
size_t Spi::Send(const char* buffer, size_t count) { return Transact(buffer, nullptr, count); }

// Receive bytes
size_t Spi::Receive(char* buffer, size_t count) { return Transact(nullptr, buffer, count); }

// Transact over SPI
size_t Spi::Transact(const char* sendBuffer, char* receiveBuffer, size_t count)
{
	// Whenever we send an SPI byte, we receive a byte.  So, we have to keep things in balance...
	size_t	result{ 0U };					// Will accumulate our return value
	uint8_t	b;								// Will hold the answer byte
	while (result < count)					// While we have work to do
	{
		if (sendBuffer != nullptr)			// If we have a send buffer
			b = *sendBuffer++;				// Store the next byte
		else								// Otherwiuse if no send buffer
			b = 0x00;						// Use a zero byte.
		if (_spi.Write(&b, 1) != 1)			// If we can't send the next byte
			break;							// Break out
		if (_spi.Read(false, &b, 1) != 1)	// If we can't receive the next byte
			break;							// Break out
		if (receiveBuffer != nullptr)		// If we have a receive buffer
			*receiveBuffer++ = b;			// Store the byte
		++result;							// We have processed an additional byte
	}
	return result;							// Done
}
