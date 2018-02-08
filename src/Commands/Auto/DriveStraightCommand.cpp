/*
 * DriveStraightCommand.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Andrew
 */

#include "DriveStraightCommand.h"
#include "Robot.h"
#include "RobotMap.h"

DriveStraightCommand::DriveStraightCommand(double driveTime) : frc::TimedCommand("DriveStraight", driveTime)
{
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveStraightCommand::Execute()
{
	Robot::DriveTrainSubsystem->Drive(1, HalfPi, 0);
}

void DriveStraightCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
}

void DriveStraightCommand::Interrupted()
{
	End();
}
