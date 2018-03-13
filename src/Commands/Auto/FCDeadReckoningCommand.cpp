/*
 * FCDeadReckoning.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: jcopi
 */

#include <Commands/Auto/FCDeadReckoningCommand.h>
#include <iostream>

FCDeadReckoningCommand::FCDeadReckoningCommand(double duration, double magnitude, double angle, double rotation) : frc::TimedCommand("FCDeadReckoning", duration)
{
	Requires(Robot::DriveTrainSubsystem.get());
	m_magnitude = magnitude;
	m_angle = angle;
	m_rotation = rotation;
}

FCDeadReckoningCommand::~FCDeadReckoningCommand() {

}

void FCDeadReckoningCommand::Initialize()
{
	std::cout << "Starting field centric dead reckoning: <" << m_magnitude << "," << m_angle << "," << m_rotation << ">\n";
}

void FCDeadReckoningCommand::Execute()
{
	Robot::DriveTrainSubsystem->FieldCentricDrive(m_magnitude, m_angle, m_rotation);
}

void FCDeadReckoningCommand::End()
{
	Robot::DriveTrainSubsystem->FieldCentricDrive(0,0,0);
	std::cout << "Field centric dead reckoning complete.\n";
}

void FCDeadReckoningCommand::Interrupted()
{
	End();
}

