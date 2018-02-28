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

PlaceInitialCubeOnSwitchCommandGroup::PlaceInitialCubeOnSwitchCommandGroup(DriveTrain& driveTrain, Vision& vision, Side nearSwitchSide) :
  frc::CommandGroup("PlaceInitialCubeOnSwitch")
{
	AddSequential(new FindDriveTarget(driveTrain, vision, nearSwitchSide));
	AddSequential(new DriveToVisionTargetCommand(driveTrain, vision));
	//AddSequential(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	//AddSequential(new FoldArmsDownCommand());
	AddSequential(new DeliverCubeCommand());
}
