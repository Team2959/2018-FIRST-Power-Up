/*
 * CloseCubeArmsCommand.h
 *
 *  Created on: Feb 11, 2018
 *      Author:
 */

#ifndef SRC_COMMANDS_AUTO_CLOSECUBEARMSCOMMAND_H_
#define SRC_COMMANDS_AUTO_CLOSECUBEARMSCOMMAND_H_

#include <Commands/Command.h>

class CloseCubeArmsCommand: public frc::Command
{
public:
	CloseCubeArmsCommand();
	~CloseCubeArmsCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_AUTO_CLOSECUBEARMSCOMMAND_H_ */
