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
	virtual void Initialize() override;
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;

private:
	constexpr static double NoTarget = -1.0;
	constexpr static double AtTarget = -2.0;
	constexpr static double TargetSize = 0.6;

	double FindTarget();
	void Drive(double angle);

	std::vector<double>	m_history;
	double				m_lastAngle;
	double				m_speed;
	bool				m_atTarget;
};

#endif /* SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_ */
