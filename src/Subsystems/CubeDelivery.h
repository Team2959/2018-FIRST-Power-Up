/*
 * CubeDeliverySubsystem.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_
#define SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include <memory>
#include <DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <Spark.h>
#include "RobotMap.h"

class CubeDelivery: public frc::Subsystem
{
private:
	std::shared_ptr<WPI_TalonSRX> m_cubeLiftMotor;
	std::shared_ptr<frc::Spark> m_cubeManipulationMotor;
	frc::DoubleSolenoid m_openCloseArms {OPEN_CLOSE_CUBE_ARMS_FORWARD_SOLENOID, OPEN_CLOSE_CUBE_ARMS_REVERSE_SOLENOID};

public:
	CubeDelivery();
	~CubeDelivery() override = default;

	void OpenArms();
	void CloseArms();
	void StopWheels();
	void SpinWheelsIn();
	void SpinWheelsOutFast();
	void SpinWheelsOutSlow();
	bool ArmsAreOpen();

};

#endif /* SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_ */
