/*
 * FarLeftAndRightCommand.h
 *
 *  Created on: Mar 5, 2018
 *      Author: Kevin
 */

#ifndef SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_
#define SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_

#include <Commands/CommandGroup.h>
#include "../../Autonomous.h"

class FarLeftAndRightCommand: public frc::CommandGroup
{
public:
	FarLeftAndRightCommand();
	virtual ~FarLeftAndRightCommand();
};

#endif /* SRC_COMMANDS_AUTO_FARLEFTANDRIGHTCOMMAND_H_ */
