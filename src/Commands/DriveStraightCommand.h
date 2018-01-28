/*
 * DriveStraightCommand.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Andrew
 */

#pragma once

#include <Commands/TimedCommand.h>

class DriveStraightCommand: public frc::TimedCommand
{
public:
	DriveStraightCommand(double driveTime = 0);
	~DriveStraightCommand() override = default;

	void Execute() override;
	void End() override;
	void Interrupted() override;
};
