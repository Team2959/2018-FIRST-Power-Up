/*
 * PlaceOnLeftSwitch.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#include <Commands/Auto/PlaceOnLeftSwitchCommandGroup.h>
#include <Commands/DeliverCubeCommand.h>
#include <Commands/Auto/MoveToVerticalCubePositionCommand.h>
#include <Commands/FoldArmsDownCommand.h>
#include <Subsystems/VerticalArmMovement.h>

PlaceOnLeftSwitchCommandGroup::PlaceOnLeftSwitchCommandGroup()
{
	//AddParallel(new DriveToLeftSwitchCommand());
	AddParallel(new MoveToVerticalCubePositionCommand(VerticalArmMovement::Switch));
	AddParallel(new FoldArmsDownCommand());
	AddSequential(new DeliverCubeCommand());
}
