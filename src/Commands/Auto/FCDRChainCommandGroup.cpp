/*
 * FCDRChainCommandGroup.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: jcopi
 */

#include <Commands/Auto/FCDRChainCommandGroup.h>

FCDRChainCommandGroup::FCDRChainCommandGroup(std::vector<FCDRObj> chain) : frc::CommandGroup("FCDRChain")
{
	for (std::vector<FCDRObj>::size_type i = 0; i != chain.size(); i++)
	{
		if (chain[i].waitForCompletion)
		{
			AddSequential(chain[i].cmd);
		}

		else {
			AddParallel(chain[i].cmd);
		}
	}
}

