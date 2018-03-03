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
	DriveToVisionTargetCommand(DriveTrain& driveTrain, Vision& vision);
	~DriveToVisionTargetCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted () override;

private:
	constexpr static double NoTarget = -1.0;
	constexpr static double AtTarget = -2.0;
	constexpr static double TargetSize = 0.25;

	double FindTarget();
	void StopDrive();
	void Drive(double angle);


	DriveTrain&	m_driveTrain;
	Vision& 	m_vision;
	bool		m_atTarget;
	double		m_lastAngle;
	double		m_speed;
};

#endif /* SRC_COMMANDS_AUTO_DRIVETOVISIONTARGETCOMMAND_H_ */
