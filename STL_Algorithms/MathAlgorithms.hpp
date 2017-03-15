#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         MathAlgorithms.hpp
* @project		STL_Algorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "Helpers.hpp"
#include <numeric> // for accumulate 
#include <string>
namespace NSTL_Algorithms
{
	/**
	* random_shuffle
	*	Shuffle the items
	**/
	inline static void Random_shuffle(Vector& vec)
	{
		std::cout << "Random_shuffle: \n Shuffle the vector \n";

		std::cout << "Before: ";
		DisplayVector(vec);

		std::random_shuffle(vec.begin(), vec.end());

		std::cout << "After: ";
		DisplayVector(vec);

	}
	/**
	* count
	*	Count the number of items in the data structure that are equal to number
	**/
	inline static void Count(Vector& vec, DataType number)
	{
		std::cout
			<< "Count: \n"
			<< "Count the number of items in the data structure that are equal to " << number << "\n";

		auto numberOfItems = std::count(vec.begin(), vec.end(), number);
		std::cout
			<< "The number of items that contains the value " << number
			<< " are : " << numberOfItems << "\n";
	}
	/**
	* count_if
	*	Count the number of items in the data structure that, for the given functor, returns true
	**/
	inline static void Count_if(Vector& vec, const DataType& number)
	{
		std::cout
			<< "Count_if: \n"
			<< "Count the number of items in the data structure that are less than " << number << "\n";

		auto numberOfItems = std::count_if(
			vec.begin(), vec.end(),
			[number](const DataType& item) { return item < number; }
			);
		std::cout
			<< "The number of items that are less than the value " << number
			<< " are : " << numberOfItems << "\n";
	}
	/**
	* min_element
	*	Returns the min element (as iterator) from that data structure
	**/
	inline static void Min_Element(Vector& vec)
	{
		auto min = *(std::min_element(vec.begin(), vec.end()));
		std::cout << "Min element: " << min << "\n";
	}

	/**
	* max_element
	*	Returns the max element (as iterator) from that data structure
	**/
	inline static void Max_Element(Vector& vec)
	{
		auto max = *(std::max_element(vec.begin(), vec.end()));
		std::cout << "Max element: " << max << "\n";
	}

	/**
	* minmax_element
	*	Returns the min & max element (as pair) from that data structure
	**/
	inline static void MinMax_Element(Vector& vec)
	{
		auto minMax = std::minmax_element(vec.begin(), vec.end());
		std::cout << "Min / Max elements: " << *minMax.first << " & " << *minMax.second << "\n";
	}

	/**
	* acummulate
	*	Returns the sum of elements from that data structure
	**/
	inline static void Acummulate(Vector& vec)
	{
		auto sum = std::accumulate(vec.begin(), vec.end(), 0);
		std::cout << "The sum of elements: " << sum << "\n";
	}

	/**
	* for_each
	*	Call a function for each element of the data structure
	**/
	inline static void For_Each(Vector& vec)
	{
		std::cout << "For_each will display all the items: \n";

		std::for_each(
			vec.begin(), vec.end(), 
			[](const DataType& item) { std::cout << item << " "; }
		);
		std::cout << "\n";
	}

	/**
	* transform
	*	Iterate through all the elements from a data structure and copy the values returned after
	*	calling a function that receives them, into a new data structure.
	*
	*	The old data structure remains unchanged
	**/
	inline static void Transform(Vector& oldVec, Vector& newVec)
	{
		std::cout
			<< "Transform: \n"
			<< "Iterate through all the elements from a data structure and copy the values returned "
			<< "after calling a function that receives them, into a new data structure. \n";

		std::transform(
			oldVec.begin(), oldVec.end(), newVec.begin(),
			[](const DataType& item) { return item*2; }
		);

		std::cout << "\nOldVector contains: \n";
		DisplayVector(oldVec);
		std::cout << "\nNewVector contains: \n";
		DisplayVector(newVec);
	}
	//--------------------------------------------------------------------
	//                              EXAMPLES
	//--------------------------------------------------------------------
	namespace NMathAlgorithms
	{
		inline static void callFunctions()
		{
			std::cout << "----- Algorithms for using math functions on the data ----- \n";
			
			Vector vec = GeneratedVector;
			// Random_shuffle
			AddSpacingLines();
			Random_shuffle(vec);

			// Count
			AddSpacingLines();
			Count(vec, OLD_VALUE);


			// Count_if
			AddSpacingLines();
			Count_if(vec, OLD_VALUE);

			// Min_Element, MaxElement, MinMax_Element, Accumulate, For_each
			AddSpacingLines();
			Min_Element(vec);
			Max_Element(vec);
			MinMax_Element(vec);
			Acummulate(vec);
			For_Each(vec);

			// Transform
			AddSpacingLines();
			Transform(vec, Vector(PRESET_CAPACITY));

			std::cout << "\n";
		}
	} // NMathAlgorithms
} // NSTL_Algorithms