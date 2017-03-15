#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         Replacers.hpp
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
	* replace:
	*	Iterate through items and replace all the values that are equal 
	*	to replace_from with the value set as replace_with 
	**/
	inline static void Replace(
		Vector& vec, DataType oldValue, DataType newValue)
	{
		std::cout
			<< "Replace: \n"
			<< "Iterate through items and replace the ones that are equal to "
			<< oldValue << "to the new value: " << newValue << "\n";

		std::cout << "Before: ";
		DisplayVector(vec);

		std::replace(vec.begin(), vec.end(), oldValue, newValue);

		std::cout << "After: ";
		DisplayVector(vec);
	}
	/**
	* replace_copy
	*	Iterate through items and copy them from oldVector to the newVector
	*	All the items that are equal to oldValue will have the newValue in the newVector
	*
	*	oldVector will not be changed during the process
	*
	**/
	inline static void Replace_copy(
		Vector& oldVector, Vector& newVector, DataType oldValue, DataType newValue)
	{
		std::cout
			<< "Replace_copy: \n"
			<< "Iterate through items and copy them to a new data structure.\n"
			<< "If the value is equal to "
			<< oldValue << " , in the new data structure they will be" << newValue << "\n";

		std::replace_copy(oldVector.begin(), oldVector.end(), newVector.begin(), oldValue, newValue);

		std::cout << "\nOldVector contains: \n";
		DisplayVector(oldVector);
		std::cout << "\nNewVector contains: \n";
		DisplayVector(newVector);
	}
	/**
	* replace_if
	*	Iterate through items and change them to the newValue if the functor returns true
	**/
	inline static void Replace_if(
		Vector& vec, const DataType& minValue, const DataType& newValue)
	{
		std::cout
			<< "Replace_if: \n"
			<< "Iterate through items and, if the functor that iterates "
			<< "through the data returns true, replace them with the new value" << NEW_VALUE
			<< "\n";

		std::cout << "Before: ";
		DisplayVector(vec);

		std::replace_if(
			vec.begin(), vec.end(),
			[minValue](const DataType& item) { return item < minValue; },
			newValue
		);
		std::cout << "After: ";
		DisplayVector(vec);
	}
	/**
	* replace_copy_if
	*	Combination of replace_if and replace_copy
	*	Iterate through items and copy them to the newVector. If the funtor returns true, the data
	*	will now be changed to newValue.
	*
	*	oldVector will not be changed during the process.
	**/
	inline static void Replace_copy_if(
		Vector& oldVector, Vector& newVector, const DataType& minValue, const DataType& newValue)
	{
		std::cout
			<< "Replace_copy_if: \n"
			<< "Iterate through items and copy them to the new data structure.\n"
			<< "if the functor that iterates through the data returns true "
			<< "(< " << minValue << ", replace them with the new value "
			<< "(" << newValue << ") \n";

		std::replace_copy_if(
			oldVector.begin(), oldVector.end(), newVector.begin(),
			[minValue](const DataType& item) { return item < minValue; },
			newValue
		);
		std::cout << "\nOldVector contains: \n";
		DisplayVector(oldVector);
		std::cout << "\nNewVector contains: \n";
		DisplayVector(newVector);
	}

	//--------------------------------------------------------------------
	//                              EXAMPLES
	//--------------------------------------------------------------------
	namespace NReplacers
	{
		inline static void callFunctions()
		{
			std::cout << "----- Algorithms for replacing the data ----- \n";
			
			// Replace
			AddSpacingLines();
			Replace(Vector(GeneratedVector), OLD_VALUE, NEW_VALUE);

			// Replace_copy
			AddSpacingLines();
			Replace_copy(Vector(GeneratedVector), Vector(PRESET_CAPACITY), OLD_VALUE, NEW_VALUE);

			// Replace_if
			AddSpacingLines();
			Replace_if(Vector(GeneratedVector), OLD_VALUE, NEW_VALUE);

			// Replace_copy_if
			AddSpacingLines();
			Replace_copy_if(Vector(GeneratedVector), Vector(PRESET_CAPACITY), OLD_VALUE, NEW_VALUE);
			
			std::cout << "\n";
		}
	} // NReplacers
} // NSTL_Algorithms