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

DriveStraightCommand::DriveStraightCommand(double driveTime) : frc::TimedCommand("DriveStraight", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
	m_origSpeed = 0.5;
	m_speed = 0.0;
	m_dist = 0.0;
}

void DriveStraightCommand::Initialize()
{
	m_origSpeed = frc::SmartDashboard::GetNumber("Auton Speed", 0.5);
	m_dist = frc::SmartDashboard::GetNumber("Auton BD Dist", 10);
	std::cout << "Drive Straight\n";
}

void DriveStraightCommand::Execute()
{

	double disp = ((-Robot::MotionTrackingSubsystem->m_motors["frontRight"].displacement+Robot::MotionTrackingSubsystem->m_motors["backLeft"].displacement)/2);

	if (disp >= m_dist) {
		m_speed = 0;
	}
	else if (disp < 2)
	{
		m_speed = fmin(m_origSpeed, 0.25);
	}
	else if (disp < m_dist && m_dist - disp <= 2) {
		m_speed = fmin(m_origSpeed, 0.25);
	}

	else {
		m_speed = fmin(m_origSpeed, m_speed + 0.05);
	}

	Robot::DriveTrainSubsystem->Drive(m_speed, 3 * QuarterPi, 0);
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
