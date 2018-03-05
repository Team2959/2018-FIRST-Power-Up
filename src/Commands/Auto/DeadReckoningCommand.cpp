/*
 * DeadReckoning.cpp
 *
 *  Created on: Mar 3, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/Auto/DeadReckoningCommand.h>
#include "Robot.h"
#include <iostream>

DeadReckoningCommand::DeadReckoningCommand(double driveTime, double magnitude, double angle, double rotation)
	: frc::TimedCommand("DeadReckoning", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
	m_magnitude = magnitude;
	m_angle = angle;
	m_rotation = rotation;
}

void DeadReckoningCommand::Initialize()
{
	std::cout << "Start Dead Reckoning: magnitude" << m_magnitude << "; angle" << m_angle << "; rotation " << m_rotation << "\n";
}

void DeadReckoningCommand::Execute()
{
	Robot::DriveTrainSubsystem->Drive(m_magnitude, m_angle, m_rotation);
}

void DeadReckoningCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
	std::cout << "Finished Dead Reckoning\n";
}

void DeadReckoningCommand::Interrupted()
{
	End();
}
