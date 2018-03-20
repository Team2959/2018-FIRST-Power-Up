/*
 * DropHooksDown.h
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_DROPHOOKSDOWNCOMMAND_H_
#define SRC_COMMANDS_DROPHOOKSDOWNCOMMAND_H_

#include <Commands/Command.h>

class DropHooksDownCommand: public frc::Command
{
public:
	DropHooksDownCommand();
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_DROPHOOKSDOWNCOMMAND_H_ */
