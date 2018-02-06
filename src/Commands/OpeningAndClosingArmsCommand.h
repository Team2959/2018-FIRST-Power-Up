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
	virtual ~OpeningAndClosingArmsCommand();

	void Initialize() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_OPENINGANDCLOSINGARMSCOMMAND_H_ */
