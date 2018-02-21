/*
 * CloseCubeArmsCommand.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author:
 */

#include <Commands/CloseCubeArmsCommand.h>
#include "Robot.h"

CloseCubeArmsCommand::CloseCubeArmsCommand() : frc::Command("CloseCubeArms")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void CloseCubeArmsCommand::Initialize()
{
	Robot::CubeDeliverySubsystem->CloseArms();
}

bool CloseCubeArmsCommand::IsFinished()
{
	return true;
}
