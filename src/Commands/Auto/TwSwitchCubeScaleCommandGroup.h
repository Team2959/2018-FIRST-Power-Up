/*
 * TwSwitchCubeScaleCommandGroup.h
 *
 *  Created on: Mar 23, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_AUTO_TWSWITCHCUBESCALECOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_TWSWITCHCUBESCALECOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <Autonomous.h>

class TwSwitchCubeScaleCommandGroup: public frc::CommandGroup
{
public:
	TwSwitchCubeScaleCommandGroup(bool botOnLeft, Side switchSide, Side scaleSide);
};

#endif /* SRC_COMMANDS_AUTO_TWSWITCHCUBESCALECOMMANDGROUP_H_ */
