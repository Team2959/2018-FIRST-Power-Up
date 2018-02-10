/*
 * DriveToVisionTargetCommand.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#ifndef SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_
#define SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_

#include <Commands/Command.h>

class DriveToVisionTargetCommand: public frc::Command {
public:
	DriveToVisionTargetCommand();
	~DriveToVisionTargetCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;
};

#endif /* SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_ */
