/*
 * TwoWheelDriveCommand.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: CW
 */

#include <Commands/Auto/TwoWheelDriveCommand.h>
#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>
#include <cmath>

TwoWheelDriveCommand::TwoWheelDriveCommand(double dist, double speed, bool frontLeftBackRight) : frc::Command("TwoWheelTrive"),
	m_dist{ dist }, m_speed{ speed }, m_startDist{ 0.0 }
{
	Requires(Robot::DriveTrainSubsystem.get());
	if( frontLeftBackRight )
	{
		m_motor1 = "frontLeft";
		m_motor2 = "backRight";
		m_driveAngle = QuarterPi;
	}
	else
	{
		m_motor1 = "frontRight";
		m_motor2 = "backLeft";
		m_driveAngle = 3.0 * QuarterPi;
	}


	if (speed < 0)
	{
		speed = fabs(speed);
		m_driveAngle+= Pi;
	}
}

void TwoWheelDriveCommand::Initialize()
{
	std::cout << "Drive Straight\n";
	m_disp = 0.0;
	m_wheelDiff = 0.0;
	m_startDist = ((-Robot::MotionTrackingSubsystem->m_motors[m_motor1].displacement+Robot::MotionTrackingSubsystem->m_motors[m_motor2].displacement)/2);
}

void TwoWheelDriveCommand::Execute()
{
	// The robot should drive until the average of the displacements of the driving wheels is greater than or equivalent to the distance provided.
	// This command will drive for the distance provided in the direction (sign) provided, negative distances will have no effect.
	// If the two wheels being monitored during the driving differ by to great of an amount an execution shall be added to compensate for the angular drift.
	double	rotCorrection{ 0.0 };
	double	speed{ 0.0 };
	// To reduce strafing drift this module shall implement a linearly ramping acceleration profile.

	// The fist step of executing the command is to calculate the current total displacement since starting.


	m_disp = ((-Robot::MotionTrackingSubsystem->m_motors[m_motor1].displacement + Robot::MotionTrackingSubsystem->m_motors[m_motor2].displacement)/2) - m_startDist;

	// The difference in displacement of the wheel should be calculated next.
	m_wheelDiff = (-Robot::MotionTrackingSubsystem->m_motors[m_motor1].displacement - Robot::MotionTrackingSubsystem->m_motors[m_motor2].displacement);

	if (fabs(m_disp) >= fabs(m_dist))
	{
		speed = 0;
	}
	else if (fabs(m_disp) <= TWO_WHL_RAMP_DIST)
	{
		// Apply the linear ramp up
		speed = ((m_speed - TWO_WHL_LOW_RAMP_SPEED) / TWO_WHL_RAMP_DIST) * m_disp + TWO_WHL_LOW_RAMP_SPEED;
	}
	else if (fabs(m_dist - m_disp) <= TWO_WHL_RAMP_DIST)
	{
		// Apply the linear ramp down
		speed = -((m_speed - TWO_WHL_LOW_RAMP_SPEED) / TWO_WHL_RAMP_DIST) * (m_disp - m_dist) + TWO_WHL_LOW_RAMP_SPEED;
	}
	else
	{
		speed = m_speed;
	}

	if (fabs(m_wheelDiff) > TWO_WHL_MAX_ACCEPT_ROT)
	{
		rotCorrection = (TWO_WHL_FULL_TURN_SPEED / (TWO_WHL_FULL_TURN_DIFF - TWO_WHL_MAX_ACCEPT_ROT)) * (-m_wheelDiff - TWO_WHL_MAX_ACCEPT_ROT);
	}

	Robot::DriveTrainSubsystem->Drive(speed, m_driveAngle, rotCorrection);
}

void TwoWheelDriveCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0.0, 0.0, 0.0);
	std::cout << "Drive Straight Finished\n";
}

void TwoWheelDriveCommand::Interrupted()
{
	End();
}

bool TwoWheelDriveCommand::IsFinished()
{
	return fabs(m_disp) >= fabs(m_dist);
}
