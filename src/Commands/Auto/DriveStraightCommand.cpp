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

DriveStraightCommand::DriveStraightCommand(double driveTime) : frc::TimedCommand("DriveStraight", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveStraightCommand::Execute()
{
	double speed = frc::SmartDashboard::GetNumber("Auton Speed", 0.1);
	Robot::DriveTrainSubsystem->Drive(speed, HalfPi, 0);
	std::cout << "Drive Straight\n";
}

void DriveStraightCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
}

void DriveStraightCommand::Interrupted()
{
	End();
}
