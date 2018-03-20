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
	virtual void Initialize() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_OPENORCLOSECUBEARMSCOMMAND_H_ */
