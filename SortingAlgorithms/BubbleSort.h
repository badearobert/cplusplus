#pragma once
/******************************************************************************
* Copyright (C) 12/26/2016
*
* @file         BubbleSort.hpp
* @project		SortingAlgorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* 
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <vector>

namespace NSortingAlgorithms
{
	namespace NBubbleSort
	{
		inline void sort(std::vector<uint32_t> & data)
		{
			int length = data.size();
			bool loopAgain = true;

			while (loopAgain)
			{
				loopAgain = false;
				for (int i = 0; i < length - 1; ++i)
				{
					if (data[i] > data[i + 1])
					{
						std::swap(data[i], data[i + 1]);
						loopAgain = true;
					}
				}
			}
		}
	} // NBubbleSort
} // NSortingAlgorithms