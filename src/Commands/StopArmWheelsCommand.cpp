/*
 * StopArmWheels.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: Andrew
 */

#include <Commands/StopArmWheelsCommand.h>
#include "Robot.h"

StopArmWheelsCommand::StopArmWheelsCommand(double time) : frc::TimedCommand("StopArmWheels", time)
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void StopArmWheelsCommand::End()
{
	Robot::CubeDeliverySubsystem->StopWheels();
}
