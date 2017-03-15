#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         Helpers.hpp
* @project		STL_Algorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <vector>
#include <iostream>
#include <algorithm>

namespace NSTL_Algorithms
{
	//--------------------------------------------------------------------
	//                           DEFINES
	//--------------------------------------------------------------------
	using DataType = uint32_t;
	using Vector = std::vector<DataType>;
	//--------------------------------------------------------------------
	//                          CONSTANTS
	//--------------------------------------------------------------------
	const Vector GeneratedVector = Vector{ 1, 2, 3, 4, 5 };
	const DataType PRESET_CAPACITY = 5;
	const DataType LOWER_CAPACITY = PRESET_CAPACITY - 2;


	const DataType CONSTANT_VALUE = 123;
	const DataType OLD_VALUE = 3;
	const DataType NEW_VALUE = 99;
	//--------------------------------------------------------------------
	//                      HELPER FUNCTIONS
	//--------------------------------------------------------------------
	inline static DataType generateNext()
	{
		static DataType i = 0;
		return ++i;
	}
	//--------------------------------------------------------------------
	//                       OUTPUT THE DATA
	//--------------------------------------------------------------------
	inline static void DisplayVector(Vector& vec)
	{
		for (auto &i : vec)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

	inline static void AddSpacingLines()
	{
		std::cout << "----------------------------------\n";
	}
	inline static void Pause()
	{
		std::cin.get();
	}
} // NSTL_Algorithms