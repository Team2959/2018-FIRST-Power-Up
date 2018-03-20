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
public:
	MoveToAbsoluteHeightCommand();
	virtual void Initialize() override;
	virtual bool IsFinished() override;
};

#endif /* SRC_COMMANDS_MOVETOABSOLUTEHEIGHTCOMMAND_H_ */
