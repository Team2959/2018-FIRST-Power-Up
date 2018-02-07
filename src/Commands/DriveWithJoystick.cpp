/*
 * DriveWithJoystick.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: CW
 */

#include "Commands/DriveWithJoystick.h"
#include "Robot.h"
#include "RobotMap.h"
#include <math.h>
//#include <SmartDashboard/SmartDashboard.h>

DriveWithJoystick::DriveWithJoystick() : frc::Command("DriveWithJoystick"),
	m_conditioningMagnitude {-0.1, 0.1, -0.05, 0.05, 1.0, 1.0},
	m_conditioningTwist {-0.2, 0.2, 0.0, 0.0, 1.0, 1.0}
{
	Requires(Robot::DriveTrainSubsystem.get());
	Requires(Robot::MotionTrackingSubsystem.get());
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

	if (Robot::oi->GetDriverJoystick()->GetThrottle() > 0) {
		angle = Robot::MotionTrackingSubsystem->GetAngle() - angle;
		if (angle < 0)
			angle = 360 - angle;
	}

	magnitude = m_conditioningMagnitude.Conditioned(magnitude);

//	frc::SmartDashboard::PutNumber("Magnitude", magnitude);
//	frc::SmartDashboard::PutNumber("Total Angle", angle);
//	frc::SmartDashboard::PutNumber("Rotation", rotation);

	Robot::DriveTrainSubsystem->Drive(magnitude, angle, rotation);
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
