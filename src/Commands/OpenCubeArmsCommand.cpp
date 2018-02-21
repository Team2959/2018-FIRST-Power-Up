/*
 * GrabCubeCommand.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#include <Commands/OpenCubeArmsCommand.h>
#include "Robot.h"

OpenCubeArmsCommand::OpenCubeArmsCommand() : frc::Command("OpenCubeArms")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

void OpenCubeArmsCommand::Initialize()
{
	Robot::CubeDeliverySubsystem->OpenArms();
}

bool OpenCubeArmsCommand::IsFinished()
{
	return true;
}
