/*
 * VerticalButtonCommand.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author:
 */

#include <Commands/VerticalButtonCommand.h>
#include "Robot.h"

// decrement is calculated based on 20 ms periodic calls, which is 50 calls per second
// multiply 50 by the number of seconds you wish to take to lower the vertical system
VerticalButtonCommand::VerticalButtonCommand(double time) : frc::Command("Vertical Button"),
	m_targetHeight{1.0}, m_decrement{1.0/(50.0 * time)}
{
	Requires(Robot::VerticalArmMovmentSubsystem.get());
}

void VerticalButtonCommand::Execute()
{
	m_targetHeight = fmax(0.0, m_targetHeight - m_decrement);
	Robot::VerticalArmMovmentSubsystem->MoveArmToHeight(m_targetHeight);
}

bool VerticalButtonCommand::IsFinished()
{
	return m_targetHeight <= 0.0;
}
