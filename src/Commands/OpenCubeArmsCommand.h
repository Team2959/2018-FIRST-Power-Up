/*
 * GrabCubeCommand.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_OPENCUBEARMSCOMMAND_H_
#define SRC_COMMANDS_OPENCUBEARMSCOMMAND_H_

#include <Commands/Command.h>

class OpenCubeArmsCommand: public frc::Command
{
public:
	OpenCubeArmsCommand();
	~OpenCubeArmsCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_OPENCUBEARMSCOMMAND_H_ */
