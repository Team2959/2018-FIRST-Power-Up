/*
 * DeliverCubeUntilNotPresentCommand.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: CW
 */

#include <Commands/Auto/DeliverCubeUntilNotPresentCommand.h>
#include "Subsystems/CubeDelivery.h"
#include "Robot.h"

DeliverCubeUntilNotPresentCommand::DeliverCubeUntilNotPresentCommand()
{
	Requires(Robot::CubeDeliverySubsystem.get());
	m_cubeNotpresentCount = 0;
}

DeliverCubeUntilNotPresentCommand::~DeliverCubeUntilNotPresentCommand()
{
	// TODO Auto-generated destructor stub
}
void DeliverCubeUntilNotPresentCommand::Initialize()
{
	m_cubeNotpresentCount = 0;

}
bool DeliverCubeUntilNotPresentCommand::IsFinished()
{
	if ( !Robot::CubeDeliverySubsystem->CubePresent())
	{
		m_cubeNotpresentCount++;
		//This is the case if the cube has been gone for a half of a second
		if (m_cubeNotpresentCount >= 25)
		{
			return true;
		}
	}
	else
	{
		m_cubeNotpresentCount = 0;
	}

	return false;
}
void DeliverCubeUntilNotPresentCommand::Execute()
{
	Robot::CubeDeliverySubsystem->SpinWheelsOut(1.0);
}

void DeliverCubeUntilNotPresentCommand::End()
{
	Robot::CubeDeliverySubsystem->StopWheels();
}

void DeliverCubeUntilNotPresentCommand::Interrupted()
{
	End();
}
