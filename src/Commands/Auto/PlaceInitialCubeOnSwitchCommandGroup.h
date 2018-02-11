/*
 * PlaceInitialCubeOnSwitch.h
 *
 *  Created on: Feb 7, 2018
 *      Author: JWB
 */

#ifndef SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_
#define SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_

#include <Commands/CommandGroup.h>

class PlaceInitialCubeOnSwitchCommandGroup : public frc::CommandGroup
{
public:
	PlaceInitialCubeOnSwitchCommandGroup(bool switchOnLeft = true);
	~PlaceInitialCubeOnSwitchCommandGroup() override = default;
};

#endif /* SRC_PLACE_INITIAL_CUBE_ON_SWITCH_H_ */

