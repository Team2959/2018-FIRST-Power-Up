/*
 * OpenOrCloseCubeArmsCommand.h
 *
 *  Created on: Feb 20, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_OPENORCLOSECUBEARMSCOMMAND_H_
#define SRC_COMMANDS_OPENORCLOSECUBEARMSCOMMAND_H_

#include <Commands/Command.h>

class OpenOrCloseCubeArmsCommand: public frc::Command
{
public:
	OpenOrCloseCubeArmsCommand();
	~OpenOrCloseCubeArmsCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_OPENORCLOSECUBEARMSCOMMAND_H_ */
