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
	DriveStraightCommand(double driveTime = 0, double speed = 0);
	virtual void Initialize() override;
	virtual void Execute() override;
	virtual void End() override;
	virtual void Interrupted() override;
};

#endif /* SRC_DRIVE_STRAIGHT_COMMAND_H_ */
