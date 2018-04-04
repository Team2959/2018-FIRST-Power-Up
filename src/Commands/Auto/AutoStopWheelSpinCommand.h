/*
 * AutoStopWheelSpinCommand.h
 *
 *  Created on: Apr 3, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_AUTOSTOPWHEELSPINCOMMAND_H_
#define SRC_COMMANDS_AUTO_AUTOSTOPWHEELSPINCOMMAND_H_

#include <Commands/Command.h>

class AutoStopWheelSpinCommand: public frc::Command {
public:
	AutoStopWheelSpinCommand();


	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_AUTO_AUTOSTOPWHEELSPINCOMMAND_H_ */
