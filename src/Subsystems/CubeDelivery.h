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
#include <Spark.h>
#include <ctre/Phoenix.h>

class CubeDelivery: public frc::Subsystem
{
private:
	frc::DoubleSolenoid m_openCloseArms;
	frc::Spark m_cubeManipulationMotor;
	WPI_TalonSRX m_cubeLiftMotor;

public:
	CubeDelivery();
	~CubeDelivery() override = default;

	void OpenArms();
	void CloseArms();
	void StopWheels();
	void SpinWheelsIn();
	void SpinWheelsOut(double speed);
	bool ArmsAreOpen();
};

#endif /* SRC_COMMANDS_CUBEDELIVERYSUBSYSTEM_H_ */
