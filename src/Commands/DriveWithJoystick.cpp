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

DriveWithJoystick::~DriveWithJoystick()
{
}

void DriveWithJoystick::Execute()
{
	// maybe forgo our own calculations, for these existing functions
		//	double jDirectionR = Robot::oi->GetDriverJoystick()->GetDirectionRadians();
		//	double jDirectionD = Robot::oi->GetDriverJoystick()->GetDirectionDegrees();
		//	double jMagnitude = Robot::oi->GetDriverJoystick()->GetMagnitude();
//	Robot::DriveTrainSubsystem->XDrive(
//		Robot::oi->GetDriverJoystick()->GetMagnitude(),
//		Robot::oi->GetDriverJoystick()->GetDirectionRadians(),
//		Robot::oi->GetDriverJoystick()->GetTwist());

	double xAxis = Robot::oi->GetDriverJoystick()->GetX();
	double yAxis = -Robot::oi->GetDriverJoystick()->GetY();
	double rotation = Robot::oi->GetDriverJoystick()->GetTwist();

	double magnitude = fmax(fabs(yAxis), fabs(xAxis));

	double angle = atan2(yAxis,xAxis);
	if (angle < 0)
		angle = angle + Pi*2;

	SmartDashboard::PutNumber("Magnitude", magnitude);
	SmartDashboard::PutNumber("Total Angle", angle);
	SmartDashboard::PutNumber("Rotation", rotation);

	Robot::DriveTrainSubsystem->XDrive(magnitude, angle, rotation);
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
