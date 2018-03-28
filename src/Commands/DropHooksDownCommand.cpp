/*
 * DropHooksDown.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include "Commands/DropHooksDownCommand.h"
#include "Robot.h"

DropHooksDownCommand::DropHooksDownCommand() : frc::Command("DropHooksDown")
{
	Requires(Robot::ClimbSubsystem.get());
}

void DropHooksDownCommand::Execute()
{
	if (!Robot::ClimbSubsystem->AtBottom())
	{
		Robot::ClimbSubsystem->DropHooksDown();
	}
}

bool DropHooksDownCommand::IsFinished()
{
	return Robot::ClimbSubsystem->AtBottom();
}

void DropHooksDownCommand::End()
{
	if (Robot::ClimbSubsystem->AtBottom())
	{
		Robot::ClimbSubsystem->StopHooks();
	}
	else
	{
		Robot::ClimbSubsystem->HoldHooks();
	}
}

void DropHooksDownCommand::Interrupted()
{
	Robot::ClimbSubsystem->StopHooks();
}
