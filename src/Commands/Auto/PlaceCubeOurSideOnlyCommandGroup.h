/*
 * PlaceCubeOurSideOnlyPlaceCubeOurSideOnlyCommandGroup.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#ifndef SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_
#define SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_

#include <Commands/CommandGroup.h>
#include "../../Autonomous.h"

class PlaceCubeOurSideOnlyCommandGroup : public frc::CommandGroup
{
public:
	PlaceCubeOurSideOnlyCommandGroup(Side nearSwitchSide);
};

#endif /* SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_ */
