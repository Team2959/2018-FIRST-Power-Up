/*
 * RaiseHooksUpToRungCommand.h
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_RAISEHOOKSUPTORUNGCOMMAND_H_
#define SRC_COMMANDS_RAISEHOOKSUPTORUNGCOMMAND_H_

#include <Commands/Command.h>

class RaiseHooksUpToRungCommand: public frc::Command
{
public:
	RaiseHooksUpToRungCommand();
	~RaiseHooksUpToRungCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_RAISEHOOKSUPTORUNGCOMMAND_H_ */
