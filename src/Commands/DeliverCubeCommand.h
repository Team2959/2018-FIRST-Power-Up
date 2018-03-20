/*
 * SpinArmWheelsInCommand.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_DELIVERCUBECOMMAND_H_
#define SRC_COMMANDS_DELIVERCUBECOMMAND_H_

#include <Commands/Command.h>

class DeliverCubeCommand: public frc::Command
{
public:
	DeliverCubeCommand();
	virtual void Initialize() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_DELIVERCUBECOMMAND_H_ */
