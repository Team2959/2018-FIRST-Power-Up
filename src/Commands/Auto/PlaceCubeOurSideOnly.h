/*
 * PlaceCubeOurSideOnly.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_
#define SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_

#include <Commands/CommandGroup.h>
#include "../../Autonomous.h"

class PlaceCubeOurSideOnly: public frc::CommandGroup
{
public:
	PlaceCubeOurSideOnly(Side nearSwitchSide);
	~PlaceCubeOurSideOnly() override = default;
};

#endif /* SRC_COMMANDS_AUTO_PLACECUBEOURSIDEONLY_H_ */
