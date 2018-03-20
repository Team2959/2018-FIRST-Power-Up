/*
 * DeadReckoningCenterCommandGroup.h
 *
 *  Created on: Mar 9, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_DEADRECKONINGCENTERCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_DEADRECKONINGCENTERCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <Autonomous.h>

class DeadReckoningCenterCommandGroup: public frc::CommandGroup {
public:
	DeadReckoningCenterCommandGroup(Side nearSwitchSide);
};

#endif /* SRC_COMMANDS_AUTO_DEADRECKONINGCENTERCOMMANDGROUP_H_ */
