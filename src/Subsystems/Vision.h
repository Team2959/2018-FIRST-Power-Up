/*
 * Vision.h
 *
 *  Created on: Feb 10, 2018
 *      Author: JWB
 */

#ifndef SRC_VISION_H_
#define SRC_VISION_H_

#include <Commands/Subsystem.h>
#include "../PixyCam/Camera.h"

// All values are in [0,1] and refer to the image frame.  0 = left/top edge, 1 = right/bottom edge.
// For width/height, these are percentages of full frame.
class VisionObject
{
public:
	VisionObject(double left, double top, double width, double height) : _left{left}, _top{top},_width{width}, _height{height} { }
	double CenterX() const { return _left + _width / 2.0; }
	double CenterY() const { return _top + _height / 2.0; }
	double Left() const { return _left; }
	double Top() const { return _top; }
	double Width() const { return _width;}
	double Height() const { return _height; }
	double Right() const { return _left + _width; }
	double Bottom() const { return _top + _height; }

private:
	double	_left;
	double	_top;
	double	_width;
	double	_height;
};

// This handles vision processing.  Since PixyCam does most of this for us, not much here.
class Vision : public frc::Subsystem
{
public:
	Vision();

	std::vector<VisionObject> GetObjects(int signature);

	void TestPixyCam();

private:
	constexpr static const int FrameWidth{320};
	constexpr static const int FrameHeight{240};
	PixyCam::Camera	_camera;
};

#endif /* SRC_VISION_H_ */
