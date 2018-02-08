/*
 * SpinArmWheelsInCommand.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_SPINARMWHEELSINCOMMAND_H_
#define SRC_COMMANDS_SPINARMWHEELSINCOMMAND_H_

#include <Commands/Command.h>

class SpinArmWheelsInCommand: public frc::Command
{
public:
	SpinArmWheelsInCommand();
	~SpinArmWheelsInCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_SPINARMWHEELSINCOMMAND_H_ */
