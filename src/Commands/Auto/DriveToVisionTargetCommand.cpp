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
	if (xTarget < 0.4)
		angle = 3.0 * QuarterPi;
	else if(xTarget > 0.6)
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
	double minX = 100.0;
	double maxX = -100.0;
	// potential changes
	// probably need to find the cube pile and only want tape to the side of the pile
	// if no cube pile, do not use as reference, just tape then
	for (auto& visionObject : visionObjects)
	{
		double left = visionObject.Left();
		double right = visionObject.Right();
		if (left < minX)
		{
			minX = left;
		}
		if (right > maxX)
		{
			maxX = right;
		}
	}
	if (maxX - minX >= TargetSize)
	{
		return AtTarget;
	}

	return (minX + maxX) / 2;
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
