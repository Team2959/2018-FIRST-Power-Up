/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#include "Subsystems/DriveTrain.h"
#include "Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain(std::shared_ptr<XDrive> xDriveSystem) : frc::Subsystem("DriveTrain")
{
	m_xDrive = xDriveSystem;
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::Drive(double magnitude, double totalAngle, double rotation)
{
	m_xDrive->Drive(magnitude, totalAngle, rotation);
}
