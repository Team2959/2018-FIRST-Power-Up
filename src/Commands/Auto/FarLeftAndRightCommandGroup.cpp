/*
 * FarLeftAndRightCommandGroup.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#include <Commands/Auto/FarLeftAndRightCommandGroup.h>
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/FindDriveTarget.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <Commands/Auto/DriveStraightCommand.h>
#include <SmartDashboard/SmartDashboard.h>

FarLeftAndRightCommandGroup::FarLeftAndRightCommandGroup()
{
	bool startFarLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Far Left?", true);

	if (startFarLeft)
	{

	}
}
