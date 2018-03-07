/*
 * Climb.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: CW
 */

#include "Subsystems/ScaleClimb.h"
#include "RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

ScaleClimb::ScaleClimb() : frc::Subsystem("ScaleClimb"),
	m_leftSpark {CLIMB_LEFT_MOTOR},
	m_rightSpark {CLIMB_RIGHT_MOTOR},
	m_topLimitSwitch {CLIMB_TOP_LIMIT_SWITCH},
	m_bottomLimitSwitch {CLIMB_BOTTOM_LIMIT_SWITCH}
{
}

void ScaleClimb::RaiseHooksUp()
{
	m_leftSpark.Set(1);
	m_rightSpark.Set(1);
}

void ScaleClimb::DropHooksDown()
{
	m_leftSpark.Set(-0.5);
	m_rightSpark.Set(-0.5);
}

void ScaleClimb::StopHooks()
{
	m_leftSpark.Set(0);
	m_rightSpark.Set(0);
}

bool ScaleClimb::AtTop()
{
	return m_topLimitSwitch.Get() == true;
}

bool ScaleClimb::AtBottom()
{
	return m_bottomLimitSwitch.Get() == false;
}

void ScaleClimb::UpdateSmartDashboard()
{
	frc::SmartDashboard::PutBoolean("  At Top", AtTop());
	frc::SmartDashboard::PutBoolean("  At Bottom", AtBottom());
}
