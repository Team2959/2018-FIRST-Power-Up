/*
 * TestPixyCam.h
 *
 *  Created on: Jan 29, 2018
 *      Author: JWB
 */

#ifndef SRC_TEST_PIXY_COMMAND_H_
#define SRC_TEST_PIXY_COMMAND_H_

#include <memory>
#include <Commands/Command.h>
#include "PixyCam/Camera.h"

class TestPixyCam : public frc::Command
{
public:
	TestPixyCam();

	virtual void Execute() override;
	virtual bool IsFinished() override;

private:
	static std::unique_ptr<PixyCam::Camera>	_camera;
};

#endif /* SRC_TEST_PIXY_COMMAND_H_ */
