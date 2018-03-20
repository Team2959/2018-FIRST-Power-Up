/*
 * StopArmWheels.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_
#define SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_

#include <Commands/TimedCommand.h>

class StopArmWheelsCommand: public frc::TimedCommand
{
public:
	StopArmWheelsCommand(double time = 0.0);
	virtual void End() override;
};

#endif /* SRC_COMMANDS_STOPARMWHEELSCOMMAND_H_ */
