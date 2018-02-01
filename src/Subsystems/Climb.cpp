/*
 * Climb.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include <Subsystems/Climb.h>
#include <RobotMap.h>

Climb::Climb() : Subsystem("Climb")
{
	m_leftSpark.reset(new frc::Spark(CLIMB_LEFT_MOTOR));
	m_rightSpark.reset(new frc::Spark(CLIMB_RIGHT_MOTOR));
	m_topLimitSwitch.reset(new frc::DigitalInput(CLIMB_TOP_LIMIT_SWITCH));
}

Climb::~Climb()
{
	// TODO Auto-generated destructor stub
}
