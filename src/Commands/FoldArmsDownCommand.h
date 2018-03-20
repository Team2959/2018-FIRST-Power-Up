/*
 * FoldArmsDown.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_FOLDARMSDOWNCOMMAND_H_
#define SRC_COMMANDS_FOLDARMSDOWNCOMMAND_H_

#include <Commands/Command.h>

class FoldArmsDownCommand: public frc::Command
{
public:
	FoldArmsDownCommand();
	virtual void Initialize() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_FOLDARMSDOWNCOMMAND_H_ */
