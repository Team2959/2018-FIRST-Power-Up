/******************************************************************************
*																			  *
*	Serial/SerialInterface.h - Declaration of class SerialInterface.		  *
*																			  *
*	SerialInterface is an abstract interface implemented by various			  *
*	other serial interfaces.												  *
*																			  *
*	The idea is that other classes can use a class which implements the		  *
*	functions declared in this class, without knowing or carrying about the	  *
*	details of that implementation.											  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#pragma once

#include <cstddef>

class SerialInterface
{
public:
	virtual ~SerialInterface() = default;						// Destructor
	virtual size_t Send(const char* buffer, size_t count) = 0;	// Send bytes
	virtual size_t Receive(char* buffer, size_t size) = 0;		// Receive bytes
};
