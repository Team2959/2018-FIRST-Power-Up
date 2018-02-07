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
	~DropHooksDownCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_DROPHOOKSDOWNCOMMAND_H_ */
