/*
 * DriveToVisionTargetCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <robot.h>

DriveToVisionTargetCommand::DriveToVisionTargetCommand()
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveToVisionTargetCommand::Execute()
{
	double xTarget = FindTarget();
	DriveTrain* driveTrain = Robot::DriveTrainSubsystem.get();

	if (xTarget == NoTarget)
	{
		driveTrain->Drive(0, 0, 0);
		return;
	}

	if (xTarget == AtTarget)
	{
		driveTrain->Drive(0, 0, 0);
		m_AtTarget = true;
		return;
	}

	if (xTarget < 0.4)
	{
		driveTrain->Drive(1, 3 * QuarterPi, 0);
		return;
	}

	if (xTarget > 0.6)
	{
		driveTrain->Drive(1, QuarterPi, 0);
		return;
	}

	driveTrain->Drive(1, HalfPi, 0);
}

bool DriveToVisionTargetCommand::IsFinished()
{
	return m_AtTarget;
}

void DriveToVisionTargetCommand::End()
{
	DriveTrain* driveTrain = Robot::DriveTrainSubsystem.get();
	driveTrain->Drive(0, 0, 0);
}

double DriveToVisionTargetCommand::FindTarget()
{
	Vision* vision = Robot::VisionSubsystem.get();
	std::vector<VisionObject> visionObjects = vision->GetObjects(TapeColor);
	if (visionObjects.size() == 0)
		return NoTarget;

	double minX = 100;
	double maxX = -100;
	for (unsigned i = 0; i != visionObjects.size(); i++)
	{
		double left = visionObjects[i].Left();
		double right = left + visionObjects[i].Width();
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
