/*
 * FindDriveTarget.h
 *
 *  Created on: Feb 16, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_
#define SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_

#include <Commands/Command.h>
#include "../../Autonomous.h"
#include "../../RobotMap.h"

class FindDriveTarget: public frc::Command
{
public:
	FindDriveTarget(Side nearSwitchSide);

	virtual void Initialize() override;
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;
	virtual void Interrupted () override;

private:
	enum class Direction { ShimmyLeft, ShimmyRight, Straight, SlideLeft, SlideRight };

	double FindCubePyramid();
	void Shimmy(Direction direction, double angle);
	bool AtReflectiveTape();

	double		m_lastSpeed{ 0.0 };
	double		m_lastAngle{ HalfPi };
	double		m_autonSpeed;
	Direction	m_lastDirection{ Direction::Straight };
	Side 		m_nearSwitchSide;
	bool		m_atTarget{ false };
};

#endif /* SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_ */
