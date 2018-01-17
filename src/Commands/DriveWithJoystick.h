/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#pragma once

#include <Commands/Command.h>

class DriveWithJoystick: public frc::Command
{
public:
	DriveWithJoystick();
	virtual ~DriveWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};
