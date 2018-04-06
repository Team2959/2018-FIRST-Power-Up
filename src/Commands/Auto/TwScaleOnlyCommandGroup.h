/*
 * TwScaleOnlyCommandGroup.h
 *
 *  Created on: Mar 26, 2018
 *      Author: CW
 */

#ifndef SRC_COMMANDS_AUTO_TWSCALEONLYCOMMANDGROUP_H_
#define SRC_COMMANDS_AUTO_TWSCALEONLYCOMMANDGROUP_H_

#include <Commands/CommandGroup.h>
#include <Autonomous.h>

class TwScaleOnlyCommandGroup: public frc::CommandGroup
{
public:
	TwScaleOnlyCommandGroup(bool botOnLeft, Side scaleSide, Side switchSide);
};

#endif /* SRC_COMMANDS_AUTO_TWSCALEONLYCOMMANDGROUP_H_ */
