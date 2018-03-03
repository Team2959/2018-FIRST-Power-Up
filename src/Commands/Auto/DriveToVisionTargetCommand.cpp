/*
 * DriveToVisionTargetCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <robot.h>
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>

DriveToVisionTargetCommand::DriveToVisionTargetCommand() :
	m_atTarget{ false }, m_lastAngle{HalfPi}
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());

	m_speed = 0.25;
}

void DriveToVisionTargetCommand::Initialize()
{
	m_atTarget = false;
	m_lastAngle = HalfPi;
	m_speed = frc::SmartDashboard::GetNumber("Auton Speed", 0.25);
}

void DriveToVisionTargetCommand::Execute()
{
	double xTarget = FindTarget();

	if (xTarget <= AtTarget)
	{
		std::cout << "Drive to Vision Target - STOP at target.\n";
		m_atTarget = true;
		return;
	}

	if (xTarget <= NoTarget)
	{
		std::cout << "Drive to Vision Target - keep moving - No TARGET!\n";
		Drive(m_lastAngle);
		return;
	}

	double	angle;
	if (xTarget < 0.45)
		angle = 3.0 * QuarterPi;
	else if(xTarget > 0.55)
		angle = QuarterPi;
	else
		angle = HalfPi;
	std::cout << "Drive to Vision Target - angle " << angle << ".\n";
	Drive(angle);
}

bool DriveToVisionTargetCommand::IsFinished()
{
	return m_atTarget;
}

void DriveToVisionTargetCommand::End()
{
	StopDrive();
}

void DriveToVisionTargetCommand :: Interrupted()
{
	StopDrive();
}

double DriveToVisionTargetCommand::FindTarget()
{
	std::vector<VisionObject>	visionObjects = Robot::VisionSubsystem->GetObjects(TapeColor);
	if (visionObjects.empty())
		return NoTarget;

	auto&	biggestObject{ visionObjects[0] };

	if(visionObjects.size()==1)
	{
		if (biggestObject.Height() >= TargetSize)
		{
			return AtTarget;
		}
		return biggestObject.CenterX();
	}

	auto*	mate{ &visionObjects[1] };
	auto	mateDistance{ fabs(mate->CenterX() - biggestObject.CenterX()) };

	for(auto i = 2U; i < visionObjects.size(); ++i)
	{
		auto&	comparisonObject{ visionObjects[i] };
		auto	comparisonDistance{ fabs(comparisonObject.CenterX() - biggestObject.CenterX())};
		if(mateDistance > comparisonDistance)
		{
			mate = &comparisonObject;
			mateDistance = comparisonDistance;
		}
	}

	return (biggestObject.CenterX() + mate->CenterX()) / 2.0;
}

void DriveToVisionTargetCommand::StopDrive()
{
	Robot::DriveTrainSubsystem->Drive(0.0, 0.0, 0.0);
}

void DriveToVisionTargetCommand::Drive(double angle)
{
	m_lastAngle = angle;
	Robot::DriveTrainSubsystem->Drive(m_speed, angle, 0.0);
}
