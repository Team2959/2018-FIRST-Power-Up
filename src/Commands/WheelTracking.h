/*
 * WheelTracking.h
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_WHEELTRACKING_H_
#define SRC_COMMANDS_WHEELTRACKING_H_

#include <Commands/Command.h>

class WheelTracking: public frc::Command {
public:
	WheelTracking();
	virtual ~WheelTracking();
	void Initialize();
	void Execute();
	bool IsFinished();
};

#endif /* SRC_COMMANDS_WHEELTRACKING_H_ */
