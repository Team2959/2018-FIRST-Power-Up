/*
 * GrabCubeCommand.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#include "Commands/GrabCubeCommand.h"
#include "Robot.h"

GrabCubeCommand::GrabCubeCommand() : frc::Command("GrabCube")
{
	Requires(Robot::CubeDeliverySubsystem.get());
}

GrabCubeCommand::~GrabCubeCommand()
{

}

void GrabCubeCommand::Execute()
{
	//Robot::CubeDeliverySubsystem->();
}

bool GrabCubeCommand::IsFinished()
{
	return true;
}

void GrabCubeCommand::End()
{
	Robot::CubeDeliverySubsystem->StopWheels();
}

void GrabCubeCommand::Interrupted()
{
	End();
}
