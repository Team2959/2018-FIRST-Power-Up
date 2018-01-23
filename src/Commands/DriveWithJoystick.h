/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#pragma once

#include <Commands/Command.h>
#include <Utilities/JoystickConditioning.h>

class DriveWithJoystick: public frc::Command
{
private:
	JoystickConditioning m_conditioningMagnitude{};
	JoystickConditioning m_conditioningTwist {};

public:
	DriveWithJoystick();
	virtual ~DriveWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};
