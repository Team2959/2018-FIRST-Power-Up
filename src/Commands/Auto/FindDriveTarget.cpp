/*
 * FindDriveTarget.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/Auto/FindDriveTarget.h>
#include <Robot.h>
#include <Autonomous.h>
#include <SmartDashboard/SmartDashboard.h>
#include <iostream>
#include <chrono>

FindDriveTarget::FindDriveTarget(Side nearSwitchSide) :
	m_nearSwitchSide{ nearSwitchSide }
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());

	m_autonSpeed = 0.25;
}

static decltype(std::chrono::high_resolution_clock::now())	startTime;

void ResetStartTime()
{
	startTime = std::chrono::high_resolution_clock::now();
}

int ElapsedMS()
{
	return static_cast<int>(1000.0 * std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - startTime).count());
}

void FindDriveTarget::Initialize()
{
	ResetStartTime();
	m_autonSpeed = frc::SmartDashboard::GetNumber("Auton Shimmy Speed", 0.25);
	m_lastSpeed = 0.0;
	m_lastAngle = HalfPi;
	m_atTarget = false;
	m_lastDirection = Direction::Straight;
}

void FindDriveTarget::Execute()
{
	std::cout << "FindDriveTarget::Execute\n";
	double targetLocation = FindCubePyramid();

	std::cout << ElapsedMS() << ":  targetLocation = " << targetLocation << '\n';

	if (targetLocation < 0)
	{
		// no cube data, continue with previous motion
		Shimmy(m_lastDirection, m_lastAngle);
		return;
	}
	m_lastSpeed = m_autonSpeed;

	if (targetLocation >= 0.0 &&
		targetLocation < 0.5 &&
		m_nearSwitchSide == Side::Left)
	{
		// need to move to center of pyramid, which is left of us
		Shimmy(Direction::SlideLeft, 0.875 * Pi);
		return;
	}

	if( (targetLocation > 0.5)&&(m_nearSwitchSide == Side::Right) )
	{
		// need to move to center of pyramid, which is right of us
		Shimmy(Direction::SlideRight, 0.125 * Pi);
		return;
	}

	m_atTarget = AtReflectiveTape();

	std::cout << ElapsedMS() << ":  m_atTarget = " << m_atTarget << '\n';

	if (m_atTarget)
	{
		return;
	}

	if (m_nearSwitchSide == Side::Left)
	{
		if (m_lastDirection == Direction::ShimmyLeft)
		{
			Shimmy(Direction::ShimmyLeft, 0.875 * Pi);
		}
		else
		{
			Shimmy(Direction::Straight, HalfPi);
		}
	}
	else
	{
		if (m_lastDirection == Direction::ShimmyRight)
		{
			Shimmy(Direction::ShimmyRight, QuarterPi/2.0);
		}
		else
		{
			Shimmy(Direction::Straight, HalfPi);
		}
	}
}

bool FindDriveTarget::IsFinished()
{
	return m_atTarget;
}

void FindDriveTarget::End()
{
	Shimmy(Direction::Straight, 0);
}

void FindDriveTarget :: Interrupted()
{
	Robot::DriveTrainSubsystem->Drive(0.0, 0, 0.0);
}

double FindDriveTarget::FindCubePyramid()
{
	std::vector<VisionObject> visionObjects = Robot::VisionSubsystem->GetObjects(CubeColor);
	if( visionObjects.empty() )
		return NoTarget;

	// find the biggest 'cube' from the list (either wider or taller)
	// return the center location as our target
	double biggestCubeDimension = 0;
	double biggestCubeLocation = NoTarget;

	for( auto& visionObject : visionObjects )
	{
		double biggerDimension = fmax(visionObject.Width(), visionObject.Height());

		if (biggerDimension > biggestCubeDimension)
		{
			biggestCubeDimension = biggerDimension;
			biggestCubeLocation = (visionObject.Left() + visionObject.Right()) / 2.0;
		}
	}

	return biggestCubeLocation;
}

void FindDriveTarget::Shimmy(Direction direction, double angle)
{
	m_lastDirection = direction;
	m_lastAngle = angle;

	std::cout << ElapsedMS() << ":  Shimmy(" << (int)direction << ", " << (int)(angle * 180.0 / Pi) << ")\n";

	Robot::DriveTrainSubsystem->Drive(m_lastSpeed, angle, 0.0);
}

bool FindDriveTarget::AtReflectiveTape()
{
	std::vector<VisionObject> visionObjects = Robot::VisionSubsystem->GetObjects(TapeColor);
	if( visionObjects.empty() )
	{
		std::cout << ElapsedMS() << ":  AtReflectiveTape - None\n";
		return false;
	}

	// find the tallest 'tape' from the list
	double tallest = 0;

	for( auto& visionObject : visionObjects )
	{
		tallest = fmax(tallest, visionObject.Height());
	}

	std::cout << ElapsedMS() << ":  AtReflectiveTape - " << tallest << "\n";

	// At 4' probably 90 high and frame height is 240, hence ratio of 90/240
	//).25 works better
	return tallest > 0.25;
}
