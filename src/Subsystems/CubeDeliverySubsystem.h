/*
 * CubeDeliverySubsystem.h
 *
 *  Created on: Feb 3, 2018
 *      Author: Andrew
 */

#ifndef SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_
#define SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include "ctre/Phoenix.h"
#include <Spark.h>

class CubeDeliverySubsystem: public frc::Subsystem
{
private:
	frc::DoubleSolenoid m_openCloseArms {2, 3};
	std::shared_ptr<WPI_TalonSRX> m_cubeLiftMotor;
	std::shared_ptr<frc::Spark> m_cubeManipulationMotor;

public:
	CubeDeliverySubsystem();
	~CubeDeliverySubsystem() override = default;

	void OpenArms();
	void CloseArms();
	void StopWheels();
	void SpinWheelsIn();
	void SpinWheelsOutFast();
	void SpinWheelsOutSlow();
};

#endif /* SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_ */
