/*
 * Vision.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: JWB
 */

#include "Vision.h"
#include "PixyCam/I2CChannel.h"

using namespace frc;
using namespace std;
using namespace PixyCam;

Vision::Vision() : frc::Subsystem("Vision"), _camera{make_unique<I2CChannel>(I2C::kOnboard,0)} { }

vector<VisionObject> Vision::GetObjects(int signature)
{
	vector<VisionObject>	result;
	for(auto& frameBlock : _camera.ReadFrameBlocks())
	{
		if(frameBlock.SignatureNumber() != signature)
			continue;

		double TopOfBlock = static_cast<double>(frameBlock.Y() - frameBlock.Height() / 2) / FrameHeight;
			if(TopOfBlock > 0.8)
				continue;

		double BottomOfBlock = static_cast<double>(frameBlock.Y() + frameBlock.Height() / 2) / FrameHeight;
						if(BottomOfBlock < 0.25)
							continue;

		// Convert the frame block (in pixel coords) to our VisionObject which is in frame relative coords
		result.emplace_back(static_cast<double>(frameBlock.X() - frameBlock.Width() / 2) / FrameWidth,
							TopOfBlock,
							static_cast<double>(frameBlock.Width()) / FrameWidth,
							static_cast<double>(frameBlock.Height()) / FrameHeight);
	}
	return result;
}
