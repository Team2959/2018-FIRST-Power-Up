/*
 * Vision.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: JWB
 */

#include "Vision.h"
#include "PixyCam/I2CChannel.h"
#include "RobotMap.h"
#include <iostream>
#include <I2C.h>

using namespace frc;
using namespace std;
using namespace PixyCam;

Vision::Vision() : frc::Subsystem("Vision"),
	_camera{std::make_unique<I2CChannel>(I2C::kOnboard,0)}
{
}

vector<VisionObject> Vision::GetObjects(int signature)
{
	vector<VisionObject>	result;
	for(auto& frameBlock : _camera.ReadFrameBlocks())
	{
		if(frameBlock.SignatureNumber() != signature)
			continue;

		double topOfBlock = static_cast<double>(frameBlock.Y() - frameBlock.Height() / 2) / FrameHeight;
		if(topOfBlock > 0.8)
			continue;

		double bottomOfBlock = static_cast<double>(frameBlock.Y() + frameBlock.Height() / 2) / FrameHeight;
		if(bottomOfBlock < 0.25)
			continue;

		// Convert the frame block (in pixel coords) to our VisionObject which is in frame relative coords
		result.emplace_back(static_cast<double>(frameBlock.X() - frameBlock.Width() / 2) / FrameWidth,
							topOfBlock,
							static_cast<double>(frameBlock.Width()) / FrameWidth,
							static_cast<double>(frameBlock.Height()) / FrameHeight);
	}
	return result;
}

void Vision::TestPixyCam()
{
	auto blocks{ _camera.ReadFrameBlocks() };

	if(blocks.size() == 0)
		std::cout << "None\n";
	else
		for(auto i = 0U; i < blocks.size(); ++i)
		{
			auto& block{blocks[i]};
			if (block.SignatureNumber() == CubeColor)
			{
				std::cout << "Cube " << i << ": " << block.X() << ',' << block.Y() << ',' << block.Width() << ',' << block.Height() << '\n';
			}
			else if (block.SignatureNumber() == TapeColor)
			{
				std::cout << "Tape " << i << ": " << block.X() << ',' << block.Y() << ',' << block.Width() << ',' << block.Height() << '\n';
			}
			std::cout << "Calcs " << i <<
					": left " << (static_cast<double>(block.X() - block.Width() / 2) / FrameWidth) <<
					", top " << (static_cast<double>(block.Y() - block.Height() / 2) / FrameHeight) <<
					", width " << (static_cast<double>(block.Width()) / FrameWidth) <<
					", height" << (static_cast<double>(block.Height()) / FrameHeight) << '\n';
		}
}
