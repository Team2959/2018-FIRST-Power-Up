/*
 * StopVerticalCommand.h
 *
 *  Created on: Mar 10, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_STOPVERTICALCOMMAND_H_
#define SRC_COMMANDS_STOPVERTICALCOMMAND_H_

#include <Commands/Command.h>

class StopVerticalCommand: public frc::Command
{
public:
	StopVerticalCommand();
	virtual void Execute() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_STOPVERTICALCOMMAND_H_ */
