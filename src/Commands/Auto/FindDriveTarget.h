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
#include "../../Subsystems/DriveTrain.h"
#include "../../Subsystems/Vision.h"

class FindDriveTarget: public frc::Command
{
public:
	FindDriveTarget(DriveTrain& driveTrain, Vision& vision, Side nearSwitchSide);
	virtual void Execute() override;
	virtual bool IsFinished() override;
	virtual void End() override;

private:
	enum class Direction { ShimmyLeft, ShimmyRight, Straight, SlideLeft, SlideRight };

	double FindCubePyramid();
	void Shimmy(Direction direction, double angle);

	bool AtReflectiveTape();

	DriveTrain&	m_driveTrain;
	Vision&		m_Vision;
	Side 		m_nearSwitchSide;
	bool		m_AtTarget;
	Direction	m_lastDirection;
	double		m_lastSpeed;
	double		m_lastAngle;
	double		m_autonSpeed;
};

#endif /* SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_ */
