/*
 * MoveAroundSwitchCommandGroup.h
 *
 *  Created on: Mar 6, 2018
 *      Author: Aria
 */

#ifndef SRC_COMMANDS_AUTO_MOVEAROUNDSWITCHCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_MOVEAROUNDSWITCHCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>

class MoveAroundSwitchCommandGroup: public frc::CommandGroup
{
public:
	MoveAroundSwitchCommandGroup();
	~MoveAroundSwitchCommandGroup() override = default;
};

#endif /* SRC_COMMANDS_AUTO_MOVEAROUNDSWITCHCOMMANDGROUP_H_ */
