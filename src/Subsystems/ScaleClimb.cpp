/*
 * Climb.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include <RobotMap.h>
#include <PWMSpeedController.h>
#include <Subsystems/ScaleClimb.h>

ScaleClimb::ScaleClimb() : frc::Subsystem("Climb")
{
	m_leftSpark.reset(new frc::Spark(CLIMB_LEFT_MOTOR));
	m_rightSpark.reset(new frc::Spark(CLIMB_RIGHT_MOTOR));
	m_topLimitSwitch.reset(new frc::DigitalInput(CLIMB_TOP_LIMIT_SWITCH));
}

void ScaleClimb::RaiseHooksUp()
{
	m_leftSpark->Set(1);
	m_rightSpark->Set(1);
}

void ScaleClimb::StopHooks()
{
	m_leftSpark->Set(0);
	m_rightSpark->Set(0);
}

bool ScaleClimb::AtTop()
{
	return m_topLimitSwitch->Get();
}