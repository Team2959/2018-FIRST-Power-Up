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
	double m_height;

public:
	MoveToVerticalCubePositionCommand(double height);

	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_AUTO_MOVETOVERTICALCUBEPOSITIONCOMMAND_H_ */
