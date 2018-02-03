/*
 * GrabCubeCommand.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_GRABCUBECOMMAND_H_
#define SRC_COMMANDS_GRABCUBECOMMAND_H_

#include <Commands/Command.h>

class GrabCubeCommand: public frc::Command
{
public:
	GrabCubeCommand();
	virtual ~GrabCubeCommand();

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_GRABCUBECOMMAND_H_ */
