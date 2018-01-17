/*
 * DriveWithJoystick.h
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_DRIVEWITHJOYSTICK_H_
#define SRC_COMMANDS_DRIVEWITHJOYSTICK_H_

#include <Commands/Command.h>

class DriveWithJoystick: public frc::Command
{
public:
	DriveWithJoystick();
	virtual ~DriveWithJoystick();

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_DRIVEWITHJOYSTICK_H_ */
