/*
 * SpinArmWheelsInCommand.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#include <Commands/SpinArmWheelsInCommand.h>
#include "Robot.h"

SpinArmWheelsInCommand::SpinArmWheelsInCommand() : frc::Command("SpinArmWheelsIn")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void SpinArmWheelsInCommand::Initialize()
{
	Robot::CubeDeliverySubsystem->SpinWheelsIn();
}

bool SpinArmWheelsInCommand::IsFinished()
{
	return true;
}
