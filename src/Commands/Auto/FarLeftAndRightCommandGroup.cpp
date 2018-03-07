/*
 * FarLeftAndRightCommandGroup.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#include "Commands/Auto/FarLeftAndRightCommandGroup.h"
#include "Commands/Auto/SlideToTapeVisibleCommand.h"
#include "Commands/Auto/PlaceInitialCubeOnSwitchCommandGroup.h"
#include "Commands/Auto/DriveStraightCommand.h"
#include <SmartDashboard/SmartDashboard.h>

FarLeftAndRightCommandGroup::FarLeftAndRightCommandGroup(Side nearSwitchSide)
{
	bool startLeft = frc::SmartDashboard::GetBoolean("Is Auton Starting Left?", true);

	if ((startLeft && nearSwitchSide == Side::Left) ||
		(startLeft == false && nearSwitchSide == Side::Right))
	{
		AddSequential(new SlideToTapeVisibleCommand(nearSwitchSide));
		AddSequential(new PlaceInitialCubeOnSwitchCommandGroup(nearSwitchSide));
	}
	else
	{
		// Drive along wall
		AddSequential(new DriveStraightCommand(3.0));
		// Do something else! Go for Scale
	}
}
