/******************************************************************************
*																			  *
*	PixyCam/Block.h - Declaration of class PixyCam::Block.					  *
*																			  *
*	PixyCam::Block holds information on a single block returned by the 		  *
*	camera.																	  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-28													  *
*																			  *
******************************************************************************/

#ifndef SRC_BLOCK_H_
#define SRC_BLOCK_H_

#include <cstdint>

namespace PixyCam
{
	class Block
	{
	public:
		Block(uint16_t sync, uint16_t checksum, uint16_t number, uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t angle = 0);	// Constructor
		uint16_t Angle() const { return _angle; }		// All these getters simply retrieve the fields
		uint16_t Checksum() const { return _checksum; }
		uint16_t Height() const { return _height; }
		uint16_t Number() const { return _number; }
		uint16_t Sync() const { return _sync; }
		uint16_t Width() const { return _width; }
		uint16_t X() const { return _x; }
		uint16_t Y() const { return _y; }

	private:
		uint16_t	_sync;	// All of our fields
		uint16_t	_checksum;
		uint16_t	_number;
		uint16_t	_x;
		uint16_t	_y;
		uint16_t	_width;
		uint16_t	_height;
		uint16_t	_angle;
	};
}

#endif /* SRC_BLOCK_H_ */
