/*
 * PlaceOnLeftSwitch.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/PlaceOnLeftSwitchCommandGroup.h>
#include <Subsystems/VerticalArmMovment.h>
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>

PlaceOnLeftSwitchCommandGroup::PlaceOnLeftSwitchCommandGroup()
{
	//AddParallel(new DriveToLeftSwitchCommand());
	AddParallel(new MoveToVerticalCubePositionCommand(Switch));
	AddParallel(new FoldArmsDownCommand());
	AddSequential(new DeliverCubeCommand());
}

PlaceOnLeftSwitchCommandGroup::~PlaceOnLeftSwitchCommandGroup()
{
}

