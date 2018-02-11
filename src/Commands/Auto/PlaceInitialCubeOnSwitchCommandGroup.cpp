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
#include <Commands/Auto/CloseCubeArmsCommand.h>

PlaceInitialCubeOnSwitchCommandGroup::PlaceInitialCubeOnSwitchCommandGroup(bool switchOnLeft) :	frc::CommandGroup("PlaceInitialCubeOnSwitch")
{
	AddParallel(new CloseCubeArmsCommand());

	// Identify centroid of block pyramid
	// Turn toward direction of switchOnLeft until the reflective tape is centered in field of view
	// Drive until we are close enough.  By:  identified tape block(s) are large enough or proximity sensor trips.
	// Drop the cube on switch
	//AddParallel(new DriveToSwitchTargetCommand(switchOnLeft));

	AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	AddParallel(new FoldArmsDownCommand());
	AddSequential(new DeliverCubeCommand());
}
