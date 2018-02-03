/*
 * DropHooksDown.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include <Commands/DropHooksDownCommand.h>
#include "Robot.h"

DropHooksDownCommand::DropHooksDownCommand() : frc::Command("DropHooksDown")
{
	Requires(Robot::ClimbSubsystem.get());
}

DropHooksDownCommand::~DropHooksDownCommand()
{
}

void DropHooksDownCommand::Execute()
{
	Robot::ClimbSubsystem->DropHooksDown();
}

bool DropHooksDownCommand::IsFinished()
{
	return false;
}

void DropHooksDownCommand::End()
{
	Robot::ClimbSubsystem->StopHooks();
}

void DropHooksDownCommand::Interrupted()
{
	End();
}
