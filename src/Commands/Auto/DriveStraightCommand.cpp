/*
 * DriveStraightCommand.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Andrew
 */

#include "DriveStraightCommand.h"
#include "Robot.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>
#include <cmath>

DriveStraightCommand::DriveStraightCommand(double driveTime, double speed) : frc::TimedCommand("DriveStraight", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
	m_startAngle = 0.0;
	m_speed = speed;
}

void DriveStraightCommand::Initialize()
{
	std::cout << "Drive Straight\n";
	m_startAngle = Robot::MotionTrackingSubsystem->RawAngle();
}

void DriveStraightCommand::Execute()
{
	double rotation = Robot::MotionTrackingSubsystem->RotationMagnitudeCorrection(m_startAngle, m_speed >= 0.0);

	Robot::DriveTrainSubsystem->Drive(m_speed, HalfPi, rotation);
}

void DriveStraightCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
	std::cout << "Drive Straight Finished\n";
}

void DriveStraightCommand::Interrupted()
{
	End();
}
