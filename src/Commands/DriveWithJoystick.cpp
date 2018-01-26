/*
 * DriveWithJoystick.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#include <Commands/DriveWithJoystick.h>
#include "Robot.h"
#include "RobotMap.h"
#include <math.h>
#include <SmartDashboard/SmartDashboard.h>


DriveWithJoystick::DriveWithJoystick() : Command("DriveWithJoystick")
{
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveWithJoystick::Execute()
{
	double xAxis = Robot::oi->GetDriverJoystick()->GetX();
	// Invert Y-axis for flight stick joystick controller
	double yAxis = -Robot::oi->GetDriverJoystick()->GetY();
	double rotation = Robot::oi->GetDriverJoystick()->GetTwist();
	rotation = m_conditioningTwist.Conditioned(rotation);

	double magnitude = fmax(fabs(yAxis), fabs(xAxis));

	double angle = atan2(yAxis,xAxis);
	if (angle < 0)
		angle = angle + Pi*2;

	magnitude = m_conditioningMagnitude.Conditioned(magnitude);

	SmartDashboard::PutNumber("Magnitude", magnitude);
	SmartDashboard::PutNumber("Total Angle", angle);
	SmartDashboard::PutNumber("Rotation", rotation);

	Robot::DriveTrainSubsystem->Drive(magnitude, angle, rotation);
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
