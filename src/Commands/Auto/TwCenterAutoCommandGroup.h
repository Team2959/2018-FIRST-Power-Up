/*
 * TwCenterAutoCommandGroup.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_AUTO_TWCENTERAUTOCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_TWCENTERAUTOCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <Autonomous.h>

class TwCenterAutoCommandGroup: public frc::CommandGroup
{
public:
	TwCenterAutoCommandGroup(Side switchSide, Side scaleSide);
};

#endif /* SRC_COMMANDS_AUTO_TWCENTERAUTOCOMMANDGROUP_H_ */
