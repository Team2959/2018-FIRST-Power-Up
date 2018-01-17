/*
 * DriveTrain.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: CW
 */

#include <Subsystems/DriveTrain.h>
#include "RobotMap.h"


DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	// TODO Auto-generated constructor stub
	m_FrontLeftMotor.reset(new WPI_TalonSRX(Front_LEFT_DRIVE_MOTOR_CAN));
	m_BackLeftMotor.reset(new WPI_TalonSRX(Back_Left_DRIVE_MOTOR_CAN));
	m_FrontRightMotor.reset(new WPI_TalonSRX(Front_Right_DRIVE_MOTOR_CAN));
	m_BackRightMotor.reset(new WPI_TalonSRX(Back_Right_DRIVE_MOTOR_CAN));

}

DriveTrain::~DriveTrain() {
	// TODO Auto-generated destructor stub
}

