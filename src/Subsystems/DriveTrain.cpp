/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#include "Subsystems/DriveTrain.h"
#include "Commands/DriveWithJoystick.h"
#include "Subsystems/MotionTracking.h"
#include "RobotMap.h"
#include "Robot.h"

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

void DriveTrain::FieldCentricDrive(double magnitude, double totalAngle, double rotation)
{
	totalAngle = (90 + Robot::MotionTrackingSubsystem->GetAngle() - totalAngle);
	if (totalAngle < 0)
		totalAngle = (2 * Pi) + totalAngle;

	Drive(magnitude, totalAngle, rotation);
}
