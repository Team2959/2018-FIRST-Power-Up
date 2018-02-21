/*
 * CubePresentTrigger.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Kevin
 */

#include <Triggers/CubePresentTrigger.h>
#include <Robot.h>

CubePresentTrigger::CubePresentTrigger()
{
}

bool CubePresentTrigger::Get()
{
	return Robot::CubeDeliverySubsystem->CubePresent();
}
