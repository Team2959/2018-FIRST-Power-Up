/******************************************************************************
*																			  *
*	PixyCam/PixyCam.h - Declaration of class PixyCam.						  *
*																			  *
*	PixyCam supports all required functionality of the PixyCam hardware.	  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-25													  *
*																			  *
******************************************************************************/

#pragma once

#include <memory>
#include "..\Serial\SerialInterface.h"

class PixyCam
{
public:
	PixyCam(std::unique_ptr<SerialInterface> serialInterface);	// Constructor
	bool SetServos(unsigned s0, unsigned s1);					// Set servo positions from [0,65535]
	bool SetBrightness(unsigned brightness);					// Set camera brightness from [0,255]
	bool SetLED(unsigned red, unsigned green, unsigned blue);	// Set LED colors.  Each channel is in [0,255]

private:
	std::unique_ptr<SerialInterface>	_serialInterface;		// Our serial interface
};
