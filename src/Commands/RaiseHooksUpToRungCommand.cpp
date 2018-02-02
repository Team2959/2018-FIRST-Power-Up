/*
 * RaiseHooksUpToRungCommand.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include <Commands/RaiseHooksUpToRungCommand.h>
#include "Robot.h"

RaiseHooksUpToRungCommand::RaiseHooksUpToRungCommand() : frc::Command("RaiseHooksUp")
{
	Requires(Robot::ClimbSubsystem.get());
}

RaiseHooksUpToRungCommand::~RaiseHooksUpToRungCommand()
{
}

void RaiseHooksUpToRungCommand::Execute()
{
	Robot::ClimbSubsystem->RaiseHooksUp();
}

bool RaiseHooksUpToRungCommand::IsFinished()
{
	return Robot::ClimbSubsystem->AtTop();
}

void RaiseHooksUpToRungCommand::End()
{
	Robot::ClimbSubsystem->StopHooks();
}

void RaiseHooksUpToRungCommand::Interrupted()
{
	End();
}
