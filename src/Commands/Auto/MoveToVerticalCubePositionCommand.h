/*
 * MoveToVerticalCubePositionCommand.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_AUTO_MOVETOVERTICALCUBEPOSITIONCOMMAND_H_
#define SRC_COMMANDS_AUTO_MOVETOVERTICALCUBEPOSITIONCOMMAND_H_

#include <Commands/Command.h>
#include <Subsystems/VerticalArmMovement.h>

class MoveToVerticalCubePositionCommand: public frc::Command
{
private:
	VerticalArmMovement::CubeVerticalPlace m_target;

public:
	MoveToVerticalCubePositionCommand(VerticalArmMovement::CubeVerticalPlace target = VerticalArmMovement::Switch);
	~MoveToVerticalCubePositionCommand() override = default;

	void Execute() override;
	bool IsFinished() override;
};

#endif /* SRC_COMMANDS_AUTO_MOVETOVERTICALCUBEPOSITIONCOMMAND_H_ */
