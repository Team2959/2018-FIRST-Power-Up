/******************************************************************************
*																			  *
*	PixyCam/Block.cpp - Definition of class PixyCam::Block.					  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-28													  *
*																			  *
******************************************************************************/

#include "Block.h"

using namespace PixyCam;

// Constructor
Block::Block(uint16_t sync, uint16_t checksum, uint16_t number, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle) :
	_sync{ sync }, _checksum{ checksum }, _number{ number }, _x{ x }, _y{ y }, _width{ width }, _height{ height }, _angle{ angle } { }
