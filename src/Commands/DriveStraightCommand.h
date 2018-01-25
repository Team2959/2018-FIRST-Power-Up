/*
 * DriveStraightCommand.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Tracy
 */

#ifndef SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_
#define SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_

#include <Commands/TimedCommand.h>

class DriveStraightCommand: public frc::TimedCommand
{
public:
	DriveStraightCommand(double driveTime = 0);
	virtual ~DriveStraightCommand();

	void Initialize() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};

#endif /* SRC_COMMANDS_DRIVESTRAIGHTCOMMAND_H_ */
