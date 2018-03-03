/*
 * DeadReckoning.h
 *
 *  Created on: Mar 3, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_AUTO_DEADRECKONING_H_
#define SRC_COMMANDS_AUTO_DEADRECKONING_H_

#include <Commands/TimedCommand.h>

class  DeadReckoning: public frc::TimedCommand
{
private:
	double m_magnitude;
	double m_rotation;
	double m_angle;

public:
	DeadReckoning(double driveTime = 0, double magnitude = 0, double angle = 0, double rotation = 0);
	~DeadReckoning() override = default;

	void Execute() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_AUTO_DEADRECKONING_H_ */
