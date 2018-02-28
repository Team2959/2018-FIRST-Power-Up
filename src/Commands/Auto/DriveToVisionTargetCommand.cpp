/*
 * DriveToVisionTargetCommand.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Tracy
 */

#include <Commands/Auto/DriveToVisionTargetCommand.h>
#include <robot.h>
#include <SmartDashboard/SmartDashboard.h>

DriveToVisionTargetCommand::DriveToVisionTargetCommand(DriveTrain& driveTrain, Vision& vision) :
	m_driveTrain{ driveTrain }, m_vision{ vision }
{
	Requires(Robot::VisionSubsystem.get());
	Requires(Robot::DriveTrainSubsystem.get());
}

void DriveToVisionTargetCommand::Execute()
{
	double xTarget = FindTarget();

	if (xTarget == NoTarget)
	{
		StopDrive();
		return;
	}
	if (xTarget == AtTarget)
	{
		StopDrive();
		m_AtTarget = true;
		return;
	}
	double	angle;
	if (xTarget < 0.4)
		angle = 3.0 * QuarterPi;
	else if(xTarget > 0.6)
		angle = QuarterPi;
	else
		angle = HalfPi;
	Drive(angle);
}

bool DriveToVisionTargetCommand::IsFinished()
{
	return m_AtTarget;
}

void DriveToVisionTargetCommand::End()
{
	StopDrive();
}

double DriveToVisionTargetCommand::FindTarget()
{
	std::vector<VisionObject>	visionObjects = m_vision.GetObjects(TapeColor);
	if (visionObjects.empty())
		return NoTarget;
	double minX = 100.0;
	double maxX = -100.0;
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
	m_driveTrain.Drive(0.0, 0.0, 0.0);
}

void DriveToVisionTargetCommand::Drive(double angle)
{
	double speed = frc::SmartDashboard::GetNumber("Auton Speed", 0.1);

	m_driveTrain.Drive(speed, angle, 0.0);
}
