/*
 * StopArmWheels.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_
#define SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_

#include <Commands/Command.h>

class StopArmWheelsCommand: public frc::Command
{
public:
	StopArmWheelsCommand();
	~StopArmWheelsCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_ */
