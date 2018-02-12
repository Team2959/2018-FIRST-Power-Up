/*
 * VerticleMovementCommand.h
 *
 *  Created on: Feb 9, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_VERTICALARMMOVEMENTFROMCOPILOT_H_
#define SRC_COMMANDS_VERTICALARMMOVEMENTFROMCOPILOT_H_

#include <Commands/Command.h>

class VerticalArmMovementFromCoPilot: public frc::Command
{
public:
	VerticalArmMovementFromCoPilot();
	~VerticalArmMovementFromCoPilot() override = default;

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_VERTICALARMMOVEMENTFROMCOPILOT_H_ */
