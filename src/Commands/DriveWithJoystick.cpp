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

	double magnitude = std::max(abs(yAxis), abs(xAxis));

	double beta = 0;
	if (magnitude > 0)
	{
		double alpha = asin(yAxis / magnitude);
		if (xAxis >= 0 && yAxis >= 0)
		{
			// Quadrant I
			beta = alpha;
		}
		else if (xAxis < 0 && yAxis >= 0)
		{
			// Quadrant 2
			beta = Pi - alpha;
		}
		else if (xAxis < 0 && yAxis < 0)
		{
			// Quadrant 3
			beta = Pi + alpha;
		}
		else
		{
			// Quadrant 4
			beta = Pi + Pi - alpha;
		}
	}

	Robot::DriveTrainSubsystem->XDrive(magnitude, beta, rotation);
}

bool DriveWithJoystick::IsFinished()
{
	return false;
}
