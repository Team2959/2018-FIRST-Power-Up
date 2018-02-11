/*
 * PlaceOnLeftSwitch.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_AUTO_PLACEONLEFTSWITCHCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_PLACEONLEFTSWITCHCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>

class PlaceOnLeftSwitchCommandGroup: public frc::CommandGroup
{
public:
	PlaceOnLeftSwitchCommandGroup();
	~PlaceOnLeftSwitchCommandGroup() override = default;
};

#endif /* SRC_COMMANDS_AUTO_PLACEONLEFTSWITCHCOMMANDGROUP_H_ */
