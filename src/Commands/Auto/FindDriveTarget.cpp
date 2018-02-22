/*
 * FindDriveTarget.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Bryce's Omen
 */

#include <Commands/Auto/FindDriveTarget.h>
#include <Robot.h>
#include <Autonomous.h>

FindDriveTarget::FindDriveTarget(DriveTrain& driveTrain, Vision& vision, Side nearSwitchSide) : m_driveTrain{ driveTrain },
  m_Vision{ vision }, m_nearSwitchSide{ nearSwitchSide }
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());
}

void FindDriveTarget::Execute()
{
	double targetLocation{ FindTarget() };
	if( (targetLocation < 0.5)&&(m_nearSwitchSide == Side::Left) )
	{
		Rotate(Direction::CounterClockwise);
		return;
	}
	if( (targetLocation > 0.5)&&(m_nearSwitchSide == Side::Right) )
	{
		Rotate(Direction::Clockwise);
		return;
	}
	Rotate(Direction::Stop);
	m_AtTarget = true;
}

bool FindDriveTarget::IsFinished()
{
	return m_AtTarget;
}

void FindDriveTarget::End()
{
	Rotate(Direction::Stop);
}

double FindDriveTarget::FindTarget()
{
	std::vector<VisionObject> visionObjects = m_Vision.GetObjects(CubeColor);
	if( visionObjects.empty() )
		return NoTarget;
	double minX = 100.0;
	double maxX = -100.0;
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

void FindDriveTarget::Rotate(Direction direction)
{
	constexpr double Speed{ 0.1 };	// Raise to a faster speed after testing
	if(direction == Direction::Clockwise)
		m_driveTrain.Drive( 0.0, 0.0, Speed );
	else if(direction == Direction::CounterClockwise)
		m_driveTrain.Drive( 0.0, 0.0, -Speed );
	else
		m_driveTrain.Drive( 0.0, 0.0, 0.0 );
}
