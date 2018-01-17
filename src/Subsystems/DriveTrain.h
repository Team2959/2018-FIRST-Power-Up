/*
 * DriveTrain.h
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include <memory>

class DriveTrain: public frc::Subsystem
{
private:
	std::shared_ptr<WPI_TalonSRX> m_FrontLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_BackLeftMotor;
	std::shared_ptr<WPI_TalonSRX> m_FrontRightMotor;
	std::shared_ptr<WPI_TalonSRX> m_BackRightMotor;

public:
	DriveTrain();
	virtual ~DriveTrain();
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
