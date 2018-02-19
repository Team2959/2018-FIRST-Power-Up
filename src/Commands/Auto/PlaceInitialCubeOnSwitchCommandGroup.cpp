/*
 * AutoPlaceInitialCubeOnSwitch.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: JWB
 */

#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>
#include <Commands/Auto/FindDriveTarget.h>
#include <Commands/Auto/DriveToVisionTargetCommand.h>

PlaceInitialCubeOnSwitchCommandGroup::PlaceInitialCubeOnSwitchCommandGroup() :	frc::CommandGroup("PlaceInitialCubeOnSwitch")
{
	AddSequential(new FindDriveTarget());
	AddSequential(new DriveToVisionTargetCommand());
	AddSequential(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	AddSequential(new FoldArmsDownCommand());
	AddSequential(new DeliverCubeCommand());
}
