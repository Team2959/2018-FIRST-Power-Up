/******************************************************************************
*																			  *
*	PixyCam/Channel.h - Declaration of class PixyCam::Channel.				  *
*																			  *
*	PixyCam::Channel is an abstract class that declares the I/O functions	  *
*	that PixyCam::Camera requires.											  *
*																			  *
*	Author:  JWB															  *
*	Date:	 2018-Jan-28													  *
*																			  *
******************************************************************************/

#ifndef SRC_CHANNEL_H_
#define SRC_CHANNEL_H_

#include <cstdint>

namespace PixyCam
{
	class Channel
	{
		public:
			// We have a virtual destructor so that owners of descendant class objects
			// correctly destroy those objects when they hold a base Channel pointer.
			virtual ~Channel() = default;

			// The remaining functions are abstract virtual...this class doesn't
			// implement them, but depends on descendant classes to provide these
			// specific to that serial transfer method.

			// Read bytes.  Accept a destination buffer to use, and the count to read.  Return the number of bytes read.
			virtual size_t Read(uint8_t* buffer, size_t size) = 0;

			// Write bytes.  Accept a source buffer to use, and the count to write.  Return the number of bytes written.
			virtual size_t Write(const uint8_t* buffer, size_t count) = 0;
	};
}

#endif /* SRC_CHANNEL_H_ */
