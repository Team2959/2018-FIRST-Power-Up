/*
 * DriveToVisionTargetCommand.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#ifndef SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_
#define SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_

#include <Commands/Command.h>

class DriveToVisionTargetCommand: public frc::Command
{
public:
	DriveToVisionTargetCommand();
	~DriveToVisionTargetCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double	FindTarget();
	constexpr static double NoTarget = -1;
	constexpr static double AtTarget = -2;
	constexpr static int TapeColor = 0;
	constexpr static double TargetSize = .25;
	bool m_AtTarget = false;
};

#endif /* SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_ */
