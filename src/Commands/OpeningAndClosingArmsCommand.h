/*
 * GrabCubeCommand.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_OPENINGANDCLOSINGARMSCOMMAND_H_
#define SRC_COMMANDS_OPENINGANDCLOSINGARMSCOMMAND_H_

#include <Commands/TimedCommand.h>

class OpeningAndClosingArmsCommand: public frc::TimedCommand
{
public:
	OpeningAndClosingArmsCommand();
	~OpeningAndClosingArmsCommand() override = default;

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_OPENINGANDCLOSINGARMSCOMMAND_H_ */
