/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#include <Subsystems/DriveTrain.h>
#include "Commands/DriveWithJoystick.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	m_xDrive.reset(new XDrive());
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveWithJoystick());
}

void DriveTrain::Drive(double magnitude, double totalAngle, double rotation)
{
	m_xDrive->Drive(magnitude, totalAngle, rotation);
}
