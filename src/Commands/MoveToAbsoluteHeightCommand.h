/*
 * MoveToAbsoluteHeightCommand.h
 *
 *  Created on: Feb 20, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_MOVETOABSOLUTEHEIGHTCOMMAND_H_
#define SRC_COMMANDS_MOVETOABSOLUTEHEIGHTCOMMAND_H_

#include <Commands/Command.h>

class MoveToAbsoluteHeightCommand: public frc::Command
{
private:
	double m_startHeight;
	double m_targetHeight;
	int m_count;

public:
	MoveToAbsoluteHeightCommand(double height = 0);

	virtual void Initialize() override;
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_MOVETOABSOLUTEHEIGHTCOMMAND_H_ */
