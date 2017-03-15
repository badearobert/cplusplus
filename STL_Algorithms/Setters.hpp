#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         Setters.hpp
* @project		STL_Algorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "Helpers.hpp"
namespace NSTL_Algorithms
{
	/**
	* fill: 
	*	Iterate through items and set them to a particular value
	**/
	inline static void Fill(Vector& vec)
	{
		std::cout
			<< "Fill: \n"
			<< "Iterate through items and set them to a particular value \n";

		std::fill(vec.begin(), vec.end(), CONSTANT_VALUE);
		
		DisplayVector(vec);
	}
	/** 
	* fill_n
	*	Iterate through items and set the next numberOfItems 
	*	(starting from vec.begin) to CONSTANT_VALUE
	**/
	inline static void Fill_n(Vector& vec, DataType numberOfItems)
	{
		std::cout
			<< "Fill_n: \n"
			<< "Iterate through items and set the next x items to a constant value \n";

		std::fill_n(vec.begin(), numberOfItems, CONSTANT_VALUE);

		DisplayVector(vec);
	}
	/**
	* generate
	*	Iterate through items and set them to the value received 
	*	from the functor set as 3rd param
	**/
	inline static void Generate(Vector& vec)
	{
		std::cout
			<< "Generate: \n"
			<< "Iterate through items and set them to the value received "
			<< "from the functor set as 3rd param \n";

		std::generate(vec.begin(), vec.end(), generateNext);

		DisplayVector(vec);
	}
	/**
	* generate_n
	*	Iterate through items and set the next numberOfItems (starting from vec.begin) 
	*	to  the value received from the functor set as 3rd param
	**/
	inline static void Generate_n(Vector& vec, DataType numberOfItems)
	{
		std::cout
			<< "Generate_n: \n"
			<< "Iterate through items and set the next x items to the value received "
			<< "from the functor set as 3rd param \n";

		std::generate_n(vec.begin(), numberOfItems, generateNext);

		DisplayVector(vec);
	}

	//--------------------------------------------------------------------
	//                              EXAMPLES
	//--------------------------------------------------------------------
	namespace NSetters
	{
		inline static void callFunctions()
		{
			std::cout << "----- Algorithms for setting the data ----- \n";
			
			// Fill
			AddSpacingLines();
			Fill(Vector(PRESET_CAPACITY));
			
			// Fill_n
			AddSpacingLines();
			Fill_n(Vector(PRESET_CAPACITY), LOWER_CAPACITY);
				
			// Generate
			AddSpacingLines();
			Generate(Vector(PRESET_CAPACITY));
				
			// Generate_n
			AddSpacingLines();
			Generate_n(Vector(PRESET_CAPACITY), LOWER_CAPACITY);
						
			std::cout << "\n";
		}
	} // NSetters
} // NSTL_Algorithms