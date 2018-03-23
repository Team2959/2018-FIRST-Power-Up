/*
 * VerticalButtonCommand.h
 *
 *  Created on: Mar 23, 2018
 *      Author:
 */

#ifndef SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_
#define SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_

#include <Commands/Command.h>

class VerticalButtonCommand: public frc::Command
{
private:
	double m_targetHeight;
	double m_decrement;

public:
	VerticalButtonCommand();

	virtual void Execute() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_VERTICALBUTTONCOMMAND_H_ */
