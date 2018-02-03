/******************************************************************************
*																			  *
*	PixyCam/I2C.h - Declaration of class PixyCam::I2C.						  *
*																			  *
*	PixyCam::I2C implements PixyCam::Channel for use on an I2C link.		  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Feb-1														  *
*																			  *
******************************************************************************/

#ifndef SRC_I2C_H_
#define SRC_I2C_H_

#include <I2C.h>
#include "Channel.h"

namespace PixyCam
{
	class I2CChannel : public Channel
	{
	public:
		I2CChannel(frc::I2C::Port port, int deviceAddress) : _i2c{ port, deviceAddress } { }	// Constructor
		size_t Read(uint8_t* buffer, size_t count) override;		// Read bytes
		size_t Write(const uint8_t* buffer, size_t count) override;	// Write bytes

	private:
		frc::I2C	_i2c;											// Library provided I2C object
	};
}

#endif /* SRC_I2C_H_ */
