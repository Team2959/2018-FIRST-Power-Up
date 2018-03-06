/*
 * FarLeftAndRightCommand.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Kevin
 */

#include <Commands/Auto/FarLeftAndRightCommand.h>
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/FindDriveTarget.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <SmartDashboard/SmartDashboard.h>

FarLeftAndRightCommand::FarLeftAndRightCommand()
{
	bool startFarLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Far Left?", true);

	if (startFarLeft)
	{

	}
}

FarLeftAndRightCommand::~FarLeftAndRightCommand()
{
	// TODO Auto-generated destructor stub
}

