/*
 * FarLeftAndRightCommandGroup.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#include "SlideToTapeVisibleCommand.h"
#include "PlaceInitialCubeOnSwitchCommandGroup.h"
#include "FarLeftAndRightCommandGroup.h"

FarLeftAndRightCommandGroup::FarLeftAndRightCommandGroup(Side nearSwitchSide)
{
	AddSequential(new SlideToTapeVisibleCommand(nearSwitchSide));
	AddSequential(new PlaceInitialCubeOnSwitchCommandGroup(nearSwitchSide));
}
