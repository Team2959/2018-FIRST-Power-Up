/*
 * TestPixyCam.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: JWB
 */

#include <cstdio>
#include <SmartDashboard/SmartDashboard.h>
#include "TestPixyCam.h"
#include "../PixyCam/Spi.h"

using namespace frc;
using namespace PixyCam;

std::unique_ptr<PixyCam::Camera>	TestPixyCam::_camera{std::make_unique<Camera>(std::make_unique<Spi>(SPI::kOnboardCS0))};

TestPixyCam::TestPixyCam() : Command("TestPixyCam")
{
	printf("TestPixyCam::TestPixyCam\n");
}

void TestPixyCam::Execute()
{
	printf("TestPixyCam::Execute1\n");
	auto	blocks{ _camera->ReadFrameBlocks() };
	printf("TestPixyCam::Execute2\n");

	SmartDashboard::PutNumber("BlockCount", blocks.size());
}

bool TestPixyCam::IsFinished()
{
	return false;
}
