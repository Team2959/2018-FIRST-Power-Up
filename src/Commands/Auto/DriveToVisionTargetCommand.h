/*
 * DriveToVisionTargetCommand.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#ifndef SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_
#define SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_

#include <Commands/Command.h>
#include "../../Subsystems/DriveTrain.h"
#include "../../Subsystems/Vision.h"

class DriveToVisionTargetCommand: public frc::Command
{
public:
	DriveToVisionTargetCommand();
	~DriveToVisionTargetCommand() override = default;

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	constexpr static double NoTarget = -1.0;
	constexpr static double AtTarget = -2.0;
	constexpr static double TargetSize = 0.6;

	double FindTarget();
	void Drive(double angle);

	bool		m_atTarget;
	double		m_lastAngle;
	double		m_speed;
};

#endif /* SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_ */
