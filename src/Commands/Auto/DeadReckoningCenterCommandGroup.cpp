/*
 * DeadReckoningCenterCommandGroup.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: CW
 */

#include <Commands/Auto/DeadReckoningCenterCommandGroup.h>
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <Commands/TimedCommand.h>
#include <Commands/StopArmWheelsCommand.h>
#include <Commands/Auto/DeadReckoningCommand.h>
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

DeadReckoningCenterCommandGroup::DeadReckoningCenterCommandGroup(Side nearSwitchSide)
{
	double speed = frc::SmartDashboard::GetNumber("Auton Speed", 0.5);
	double time = frc::SmartDashboard::PutNumber("Auton Center Time", 3.5);
	double angle = QuarterPi;
	if (nearSwitchSide == Side::Left)
	{
		angle *= 3;
		time += 0.5;
	}
	AddSequential(new DeadReckoningCommand(time, speed, angle));
	AddSequential(new DriveStraightCommand(1.75));
	AddSequential(new DeliverCubeCommand());
	AddSequential(new TimedCommand(0.5));
	AddSequential(new StopArmWheelsCommand());
}
