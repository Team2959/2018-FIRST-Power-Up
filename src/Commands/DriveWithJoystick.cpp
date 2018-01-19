/*
 * DriveWithJoystick.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#include <Commands/DriveWithJoystick.h>
#include "Robot.h"

DriveWithJoystick::DriveWithJoystick() : Command("DriveWithJoystick")
{
	Requires(Robot::DriveTrainSubsystem.get());
}

DriveWithJoystick::~DriveWithJoystick()
{
}

void DriveWithJoystick::Execute()
{
	double xAxis = Robot::oi->GetDriverJoystick()->GetAxis(frc::Joystick::AxisType::kXAxis);
	double yAxis = Robot::oi->GetDriverJoystick()->GetAxis(frc::Joystick::AxisType::kYAxis);
	double rotation = Robot::oi->GetDriverJoystick()->GetAxis(frc::Joystick::AxisType::kTwistAxis);

	double magnitude = 0;
	double totalAngle = 0;

	Robot::DriveTrainSubsystem->XDrive(magnitude, totalAngle, rotation);
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
