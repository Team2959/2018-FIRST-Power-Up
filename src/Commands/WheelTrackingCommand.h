/*
 * WheelTracking.h
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_WHEELTRACKINGCOMMAND_H_
#define SRC_COMMANDS_WHEELTRACKINGCOMMAND_H_

#include <Commands/Command.h>

class WheelTrackingCommand: public frc::Command
{
public:
	WheelTrackingCommand();
	virtual ~WheelTrackingCommand();

	void Execute();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_WHEELTRACKINGCOMMAND_H_ */
