/*
 * SlideToTapeVisibleCommand.cpp
 *
 *  Created on: Mar 6, 2018
 *      Author: Aria
 */

#include <Commands/Auto/SlideToTapeVisibleCommand.h>
#include <SmartDashboard/SmartDashboard.h>
#include <robotmap.h>
#include <iostream>
#include <robot.h>

SlideToTapeVisibleCommand::SlideToTapeVisibleCommand(Side nearSwitchSide)
{
		Requires(Robot::VisionSubsystem.get());
		Requires(Robot::DriveTrainSubsystem.get());
	m_autonSpeed = frc::SmartDashboard::GetNumber("Auton Shimmy Speed", 0.25);
if (nearSwitchSide == Side::Left ) {
	m_DriveAngle = Pi / 4.0;
}
else {
	m_DriveAngle = 3 * Pi / 4.0;
}
}

void SlideToTapeVisibleCommand::Initialize()
{
m_isFinished = false;
}

void SlideToTapeVisibleCommand::Execute()
{
	std::cout << "SlideToTapeVisibleCommand::Execute\n";
	bool isTapeVisible = IsTapeVisible();

	std::cout <<  ":IsTapeVisible = " << isTapeVisible << '\n';

	if (isTapeVisible)
	{
		m_isFinished = true;

		return;
	}
	Robot::DriveTrainSubsystem->Drive(m_autonSpeed, m_DriveAngle, 0);


}

bool SlideToTapeVisibleCommand::IsFinished()
{
	return m_isFinished;
}

void SlideToTapeVisibleCommand::End()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
}

void SlideToTapeVisibleCommand::Interrupted()
{
	Robot::DriveTrainSubsystem->Drive(0, 0, 0);
}
bool SlideToTapeVisibleCommand::IsTapeVisible(){
	std::vector<VisionObject> visionObjects = Robot::VisionSubsystem->GetObjects(TapeColor);
	if( visionObjects.empty() )
	{
		return false;

	}



	for( auto& visionObject : visionObjects )
	{
		std::cout <<  ":Height = " << visionObject.Height() << '\n';
		if (visionObject.Height() >= 0.1)
		{
			return true;

		}
	}
	return false;

}
