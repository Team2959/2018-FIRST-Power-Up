/*
 * DriveTrain.h
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#pragma once

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include <memory>
#include <WPILib.h>

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

	void InitDefaultCommand() override;

	void XDrive(double magnitude, double totalAngle, double rotation);
};
