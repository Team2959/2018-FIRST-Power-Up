/*
 * GrabCubeCommand.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Kevin
 */

#include <Commands/GrabCubeCommand.h>
#include "Robot.h"


GrabCubeCommand::GrabCubeCommand() : frc::Command("GrabCube")
{
	Requires(Robot::CubeArmsSubsystem.get());
}

GrabCubeCommand::~GrabCubeCommand()
{

}

void GrabCubeCommand::Execute()
{
	Robot::CubeArmsSubsystem->RaiseHooksUp();
}

bool GrabCubeCommand::IsFinished()
{
	return Robot::CubeArmsSubsystem->AtTop();
}

void GrabCubeCommand::End()
{
	Robot::CubeArmsSubsystem->StopHooks();
}

void GrabCubeCommand::Interrupted()
{
	End();
}

