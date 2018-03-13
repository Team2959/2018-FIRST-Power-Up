/*
 * MotionTracking.h
 *
 *  Created on: Feb 2, 2018
 *      Author: Bryce's Omen
 */

#ifndef SRC_SUBSYSTEMS_MOTIONTRACKING_H_
#define SRC_SUBSYSTEMS_MOTIONTRACKING_H_

#include <Commands/Subsystem.h>
#include <memory>
#include <unordered_map>
#include <iostream>
#include <Timer.h>
#include "Utilities/XDrive.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"

#include "AHRS.h"

struct MotorTelemetry {
	double displacement;
	double instVelocity;
	double instPercent;
	double instCurrent;
	double time;
	WPI_TalonSRX* controller;
};

constexpr double ENCODER_TO_FPS = (10.0 * 3.141592653589793238462643383279502) / (4096.0 * 3.0);

class MotionTracking: public frc::Subsystem
{
public:
	MotionTracking(std::shared_ptr<XDrive> xDriveSystem = nullptr);
	virtual ~MotionTracking();

	void InitDefaultCommand() override;

    void UpdateWheels();
    void UpdateMotorTelemetry(std::string name);
    void InitMotorTelemetry(std::string name, WPI_TalonSRX& controller);

    void SendMotorNumberToDash();
    void PrintMotorTelemetries();

    void ResetMotorTelemetry(std::string name);
    void ResetTelemetries();

    double GetAngle();

	AHRS* m_navmxp;

private:
	frc::Timer m_time;

	std::unordered_map<std::string, struct MotorTelemetry> m_motors;


	double m_Xdis = 0;
	double m_Ydis = 0;
};

#endif /* SRC_SUBSYSTEMS_MOTIONTRACKING_H_ */
