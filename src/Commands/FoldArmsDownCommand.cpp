/*
 * FoldArmsDown.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#include <Commands/FoldArmsDownCommand.h>
#include "Robot.h"
#include "Subsystems/CubeArms.h"

FoldArmsDownCommand::FoldArmsDownCommand() : frc::Command("FoldArmsDown")
{
	Requires(Robot::CubeArmsSubsystem.get());
}

void FoldArmsDownCommand::Initialize()
{
	Robot::CubeArmsSubsystem->FoldDown();
}

bool FoldArmsDownCommand::IsFinished()
{
	return true;
}
