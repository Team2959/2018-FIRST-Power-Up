/*
 * StopArmWheels.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#include <Commands/StopArmWheelsCommand.h>
#include "Robot.h"

StopArmWheelsCommand::StopArmWheelsCommand() : frc::Command("StopArmWheels")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void StopArmWheelsCommand::Initialize()
{
	Robot::CubeDeliverySubsystem->StopWheels();
}

bool StopArmWheelsCommand::IsFinished()
{
	return true;
}
