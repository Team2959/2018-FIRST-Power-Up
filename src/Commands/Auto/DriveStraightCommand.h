/*
 * DriveStraightCommand.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Andrew
 */

#ifndef SRC_DRIVE_STRAIGHT_COMMAND_H_
#define SRC_DRIVE_STRAIGHT_COMMAND_H_

#include <Commands/TimedCommand.h>

class DriveStraightCommand: public frc::TimedCommand
{
private:
	double m_speed;
	double m_origSpeed;
	double m_dist;

public:
	DriveStraightCommand(double driveTime = 0);
	~DriveStraightCommand() override = default;

	void Initialize() override;
	void Execute() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_DRIVE_STRAIGHT_COMMAND_H_ */
