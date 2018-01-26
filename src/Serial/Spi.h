/******************************************************************************
*																			  *
*	Serial/Spi.h - Declaration of class Spi.								  *
*																			  *
*	Spi implements the abstract SerialInterface class to communicate over	  *
*	an SPI link.															  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#pragma once

#include <memory>
#include <SPI.h>
#include "SerialInterface.h"

class Spi : public SerialInterface
{
public:
	Spi(frc::SPI::Port port);								// Constructor
	virtual size_t Send(const char* buffer, size_t count);	// Send bytes
	virtual size_t Receive(char* buffer, size_t count);		// Receive bytes

private:
	size_t Transact(const char* sendBuffer, char* receiveBuffer, size_t count);	// Transact over SPI

	frc::SPI	_spi;										// Library provided SPI object
};
