/*
 * FindDriveTarget.h
 *
 *  Created on: Feb 16, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_
#define SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_

#include <Commands/Command.h>

class FindDriveTarget: public frc::Command
{
public:
	FindDriveTarget();
	~FindDriveTarget() override = default;

	void Execute() override;
	bool IsFinished() override;
	void End() override;

private:
	double FindTarget();
	bool m_AtTarget = false;
};

#endif /* SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_ */
