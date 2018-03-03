/*
 * DeadReckoning.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/Auto/DeadReckoning.h>
#include "Robot.h"
#include "Subsystems/DriveTrain.h"
#include <iostream>

DeadReckoning::DeadReckoning(double driveTime, double magnitude, double angle, double rotation)
	: frc::TimedCommand("DeadReckoning", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
	m_magnitude = magnitude;
	m_angle = angle;
	m_rotation = rotation;
}

void DeadReckoning::Execute()
{
	Robot::DriveTrainSubsystem->Drive(m_magnitude , m_angle, m_rotation);
	std::cout << "Drive Straight\n";
}

void DeadReckoning::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
}

void DeadReckoning::Interrupted()
{
	End();
}
