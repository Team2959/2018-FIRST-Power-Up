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

FindDriveTarget::FindDriveTarget(DriveTrain& driveTrain, Vision& vision, Side nearSwitchSide) : m_driveTrain{ driveTrain },
  m_Vision{ vision }, m_nearSwitchSide{ nearSwitchSide }
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());
}

void FindDriveTarget::Execute()
{
	double targetLocation{ FindCubePyramid() };
	if( (targetLocation < 0.5)&&(m_nearSwitchSide == Side::Left) )
	{
		Shimmy(Direction::ShimmyLeft, 0.875 * Pi);
		std::cout << "Shimmy Left to Find Target!\n";
		return;
	}

	if( (targetLocation > 0.5)&&(m_nearSwitchSide == Side::Right) )
	{
		Shimmy(Direction::ShimmyRight, 0.125 * Pi);
		std::cout << "Shimmy Right to Find Target!\n";
		return;
	}

	m_AtTarget = AtReflectiveTape();

	if (m_AtTarget)
	{
		return;
	}

	if (m_nearSwitchSide == Side::Left)
	{
		if (m_lastDirection == Direction::ShimmyLeft)
		{
			std::cout << "Shimmy Left to Vision Target!\n";
			Shimmy(m_lastDirection, 0.75 * Pi);
		}
		else
		{
			std::cout << "Straight from Left side to Vision Target!\n";
			Shimmy(m_lastDirection, HalfPi);
		}
	}
	else
	{
		if (m_lastDirection == Direction::ShimmyRight)
		{
			std::cout << "Shimmy Right to Vision Target!\n";
			Shimmy(m_lastDirection, QuarterPi);
		}
		else
		{
			std::cout << "Straight from Right side to Vision Target!\n";
			Shimmy(m_lastDirection, HalfPi);
		}
	}
}

bool FindDriveTarget::IsFinished()
{
	return m_AtTarget;
}

void FindDriveTarget::End()
{
	Shimmy(Direction::Straight, 0);
}

double FindDriveTarget::FindCubePyramid()
{
	std::vector<VisionObject> visionObjects = m_Vision.GetObjects(CubeColor);
	if( visionObjects.empty() )
		return NoTarget;
	double minX = 100.0;
	double maxX = -100.0;
	// think about limiting this to largest width 'cube', which should be the pyramid
	for( auto& visionObject : visionObjects )
	{
		double	left = visionObject.Left();
		double 	right = visionObject.Right();
		if (left < minX)
		{
			minX = left;
		}
		if ( right > maxX)
		{
			maxX = right;
		}
	}
	return (minX + maxX) / 2.0;
}

void FindDriveTarget::Shimmy(Direction direction, double angle)
{
	double speed = frc::SmartDashboard::GetNumber("Auton Shimmy Speed", 0.1);

	m_lastDirection = direction;

	m_driveTrain.Drive(speed, angle, 0.0 );
}


bool FindDriveTarget::AtReflectiveTape()
{
	std::vector<VisionObject> visionObjects = m_Vision.GetObjects(TapeColor);
	return visionObjects.empty() == false;
}
