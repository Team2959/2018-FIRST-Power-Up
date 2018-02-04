/*
 * FoldArmsUp.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include "Commands/FoldArmsUpCommand.h"
#include "Robot.h"

FoldArmsUpCommand::FoldArmsUpCommand() : frc::Command("FoldArmsUp")
{
	Requires(Robot::CubeArmsSubsystem.get());
}

void FoldArmsUpCommand::Initialize()
{
	Robot::CubeArmsSubsystem->FoldUp();
}

bool FoldArmsUpCommand::IsFinished()
{
	return true;
}
