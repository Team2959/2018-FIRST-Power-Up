/*
 * DriveStraightCommand.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Andrew
 */

#include <Commands/DriveStraightCommand.h>
#include "Robot.h"
#include "RobotMap.h"

DriveStraightCommand::DriveStraightCommand(double driveTime) : TimedCommand("DriveStraight", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveStraightCommand::Initialize()
{
	Robot::DriveTrainSubsystem->XDrive(1, HalfPi, 0);
}

void DriveStraightCommand::End()
{
	Robot::DriveTrainSubsystem->XDrive(0, 0, 0);
}

void DriveStraightCommand::Interrupted()
{
	End();
}
