/*
 * FoldArmsUp.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: Andrew
 */

#include <Commands/FoldArmsUp.h>
#include "Robot.h"
#include "Subsystems/CubeArms.h"

FoldArmsUp::FoldArmsUp() : frc::Command("FoldArmsUp")
{
	Requires(Robot::CubeArmsSubsystem.get());
}

void FoldArmsUp::Initialize()
{
	//make Solenoids go out
}

bool FoldArmsUp::IsFinished()
{
	return true;
}
