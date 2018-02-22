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
	enum class Direction { Clockwise, CounterClockwise, Stop };

	double FindTarget();
	void Rotate(Direction direction);

	DriveTrain&	m_driveTrain;
	Vision&		m_Vision;
	Side 		m_nearSwitchSide;
	bool		m_AtTarget{ false };
};

#endif /* SRC_COMMANDS_AUTO_FINDDRIVETARGET_H_ */
