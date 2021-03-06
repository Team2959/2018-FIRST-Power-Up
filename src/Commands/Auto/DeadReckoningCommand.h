/*
 * DeadReckoning.h
 *
 *  Created on: Mar 3, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_AUTO_DEADRECKONINGCOMMAND_H_
#define SRC_COMMANDS_AUTO_DEADRECKONINGCOMMAND_H_

#include <Commands/TimedCommand.h>

class DeadReckoningCommand: public frc::TimedCommand
{
private:
	double m_magnitude;
	double m_rotation;
	double m_angle;

public:
	DeadReckoningCommand(double driveTime = 0, double magnitude = 0, double angle = 0, double rotation = 0);

	virtual void Initialize() override;
	virtual void Execute() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_COMMANDS_AUTO_DEADRECKONINGCOMMAND_H_ */
