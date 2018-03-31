/*
 * VerticalInchDownCommand.h
 *
 *  Created on: Mar 30, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_VERTICALINCHDOWNCOMMAND_H_
#define SRC_COMMANDS_VERTICALINCHDOWNCOMMAND_H_

#include <Commands/Command.h>

class VerticalInchDownCommand: public frc::Command
{
public:
	VerticalInchDownCommand();

	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_VERTICALINCHDOWNCOMMAND_H_ */
