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

FindDriveTarget::FindDriveTarget(DriveTrain& driveTrain, Vision& vision, Side nearSwitchSide) :
	m_driveTrain{ driveTrain }, m_Vision{ vision }, m_nearSwitchSide{ nearSwitchSide },
	m_lastDirection {Direction::Straight}, m_lastSpeed{0.0}, m_lastAngle{HalfPi},
	m_AtTarget{ false }
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());
	m_autonSpeed = frc::SmartDashboard::GetNumber("Auton Shimmy Speed", 0.1);
}

void FindDriveTarget::Execute()
{
	double targetLocation = FindCubePyramid();

	if (targetLocation < 0)
	{
		// no cube data, continue with previous motion
		Shimmy(m_lastDirection, m_lastAngle);
		std::cout << "Continue last Shimmy!\n";
		return;
	}
	m_lastSpeed = m_autonSpeed;

	if (targetLocation >= 0.0 &&
		targetLocation < 0.5 &&
		m_nearSwitchSide == Side::Left)
	{
		// need to move to center of pyramid, which is left of us
		Shimmy(Direction::SlideLeft, 0.875 * Pi);
		std::cout << "Slide Left to Find Target!\n";
		return;
	}

	if( (targetLocation > 0.5)&&(m_nearSwitchSide == Side::Right) )
	{
		// need to move to center of pyramid, which is right of us
		Shimmy(Direction::SlideRight, 0.125 * Pi);
		std::cout << "Slide Right to Find Target!\n";
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
			Shimmy(Direction::ShimmyLeft, 0.75 * Pi);
		}
		else
		{
			std::cout << "Straight from Left side to Vision Target!\n";
			Shimmy(Direction::Straight, HalfPi);
		}
	}
	else
	{
		if (m_lastDirection == Direction::ShimmyRight)
		{
			std::cout << "Shimmy Right to Vision Target!\n";
			Shimmy(Direction::ShimmyRight, QuarterPi);
		}
		else
		{
			std::cout << "Straight from Right side to Vision Target!\n";
			Shimmy(Direction::Straight, HalfPi);
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

	// find the biggest 'cube' from the list (either wider or taller)
	// return the center location as our target
	double biggestCubeDimension = 0;
	double biggestCubeLocation = 0;

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

	m_driveTrain.Drive(m_lastSpeed, angle, 0.0);
}

bool FindDriveTarget::AtReflectiveTape()
{
	std::vector<VisionObject> visionObjects = m_Vision.GetObjects(TapeColor);
	if( visionObjects.empty() )
		return false;

	// find the tallest 'tape' from the list
	double tallest = 0;

	for( auto& visionObject : visionObjects )
	{
		tallest = fmax(tallest, visionObject.Height());
	}

	// At 4' probably 90 high and frame height is 240, hence ratio of 90/240
	return tallest > 0.375;
}
