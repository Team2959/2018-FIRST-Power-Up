/*
 * FarLeftAndRightCommandGroup.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Aria
 */

#ifndef SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_
#define SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_

#include <Commands/CommandGroup.h>
#include "../../Autonomous.h"

class FarLeftAndRightCommandGroup : public frc::CommandGroup
{
public:
	FarLeftAndRightCommandGroup(Side nearSwitchSide);
	~FarLeftAndRightCommandGroup() override = default;
};

#endif /* SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_ */
