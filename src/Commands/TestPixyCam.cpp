/*
 * TestPixyCam.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: JWB
 */

#include <Commands/TestPixyCam.h>
#include <iostream>
#include <memory>
#include <SmartDashboard/SmartDashboard.h>
#include <PixyCam/I2CChannel.h>
#include <PixyCam/SpiChannel.h>

using namespace frc;
using namespace PixyCam;
using namespace std;

std::unique_ptr<PixyCam::Camera>	TestPixyCam::_camera{std::make_unique<Camera>(std::make_unique<PixyCam::I2CChannel>(frc::I2C::kOnboard,0))};

TestPixyCam::TestPixyCam() : Command("TestPixyCam")
{
	cout << "TestPixyCam::TestPixyCam\n";
}

void TestPixyCam::Execute()
{
	cout << "TestPixyCam::Execute - Start\n";
	auto	blocks{ _camera->ReadFrameBlocks() };

	SmartDashboard::PutNumber("BlockCount", blocks.size());
	cout << "TestPixyCam::Execute - End\n";
}

bool TestPixyCam::IsFinished()
{
	return false;
}
