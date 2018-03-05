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

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	enum class Direction { ShimmyLeft, ShimmyRight, Straight, SlideLeft, SlideRight };

	double FindCubePyramid();
	void Shimmy(Direction direction, double angle);
	bool AtReflectiveTape(double& center);
	double AngleToTape(double center);

	double		m_lastSpeed;
	double		m_lastAngle;
	double		m_autonSpeed;
	Direction	m_lastDirection;
	Side 		m_nearSwitchSide;
	bool		m_atTarget;
};

#endif /* SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_ */
