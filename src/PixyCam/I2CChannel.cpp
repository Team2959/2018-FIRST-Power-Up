/******************************************************************************
*																			  *
*	PixyCam/I2C.cpp - Definition of class PixyCam::I2C.						  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Feb-1														  *
*																			  *
******************************************************************************/

#include <PixyCam/I2CChannel.h>

// Read bytes
size_t PixyCam::I2CChannel::Read(uint8_t* buffer, size_t count) { return _i2c.ReadOnly(count, buffer) ? 0 : count; }

// Write bytes
size_t PixyCam::I2CChannel::Write(const uint8_t* buffer, size_t count) { return _i2c.WriteBulk(const_cast<uint8_t*>(buffer), count) ? 0 : count; }

