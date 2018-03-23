/*
 * VerticalButtonCommand.h
 *
 *  Created on: Mar 23, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_
#define SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_

#include <Commands/Command.h>

class VerticalButtonCommand: public frc::Command
{
public:
	VerticalButtonCommand();

	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_ */
