/*
 * OpenOrCloseCubeArmsCommand.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Kevin
 */

#include <Commands/OpenOrCloseCubeArmsCommand.h>
#include "Robot.h"

OpenOrCloseCubeArmsCommand::OpenOrCloseCubeArmsCommand() : frc::Command("OpenOrCloseCubeArms")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void OpenOrCloseCubeArmsCommand::Initialize()
{
	if (Robot::CubeDeliverySubsystem->ArmsAreOpen())
	{
		Robot::CubeDeliverySubsystem->CloseArms();
	}
	else
	{
		Robot::CubeDeliverySubsystem->OpenArms();
	}
}

bool OpenOrCloseCubeArmsCommand::IsFinished()
{
	return true;
}
