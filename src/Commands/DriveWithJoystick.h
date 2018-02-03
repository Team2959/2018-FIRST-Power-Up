/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#ifndef SRC_DRIVE_WITH_JOYSTICK_H_
#define SRC_DRIVE_WITH_JOYSTICK_H_

#include <Commands/Command.h>
#include <Utilities/JoystickConditioning.h>

class DriveWithJoystick: public frc::Command
{
private:
	JoystickConditioning m_conditioningMagnitude{};
	JoystickConditioning m_conditioningTwist {};

public:
	DriveWithJoystick();
	~DriveWithJoystick() override = default;

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_DRIVE_WITH_JOYSTICK_H_ */
