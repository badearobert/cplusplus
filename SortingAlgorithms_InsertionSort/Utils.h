#pragma once
/******************************************************************************
* Copyright (C) 12/26/2016
*
* @file         Utils.hpp
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
#include <iostream>
#include <ctime> // Needed for the true randomization

namespace NSortingAlgorithms
{
	// the min and max values of the vector elements
	const uint32_t ELEMENT_VALUE_MIN		= 0; 
	const uint32_t ELEMENT_VALUE_MAX		= 30;

	// the size of the randomly generated array
	const uint32_t CAPACITY_SMALL			= 10;
	const uint32_t CAPACITY_MEDIUM			= 100;
	const uint32_t CAPACITY_BIG				= 1000;

	/**
	* Function used to display the elements of an array
	*/
	inline void 
	display(const std::vector<uint32_t> & arr)
	{
		for (auto elem : arr)
		{
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}

	/**
	* Function to create an array of 'capacity' size
	*
	* We return by value because the vector class from std have move semantics
	* so we don't need to worry about performance due to copying by value
	*/
	inline std::vector<uint32_t> 
	generateRandom(uint32_t capacity)
	{
		// we assure that srand will be called only once
		static int bOnceFlag = true;
		if (bOnceFlag)
		{
			// This will allow us to have properly randomized numbers
			srand(time(0)); 
			bOnceFlag = false;
		}
		// we reserve the memory for the array first, so it will not increase size over time
		std::vector<uint32_t> arr;
		arr.reserve(capacity);

		// fill the array with numbers from MIN_VALUE to MAX_VALUE
		for (uint32_t i = 0; i < capacity; i++)
		{
			uint32_t newNumber = (static_cast<uint32_t>(rand()) % (ELEMENT_VALUE_MAX + 1) + ELEMENT_VALUE_MIN);
			arr.push_back(newNumber);
		}
		return arr;
	}
} // NSortingAlgorithms