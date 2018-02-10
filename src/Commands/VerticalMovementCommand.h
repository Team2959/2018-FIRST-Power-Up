/*
 * VerticleMovementCommand.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_VERTICALMOVEMENTCOMMAND_H_
#define SRC_COMMANDS_VERTICALMOVEMENTCOMMAND_H_

#include <Commands/Command.h>

class VerticalMovementCommand: public frc::Command {
public:
	VerticalMovementCommand();
	~VerticalMovementCommand() override = default;

void InitDefaultCommand() override;


};




#endif /* SRC_COMMANDS_VERTICALMOVEMENTCOMMAND_H_ */
