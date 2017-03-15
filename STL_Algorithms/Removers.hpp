#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         Removers.hpp
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
	* remove:
	*	Remove all elements with the value dataToRemove in the iterator range.
	**/
	inline static void Remove(Vector& vec, DataType dataToRemove)
	{
		std::cout
			<< "Remove: \n"
			<< "Iterate through items and remove the ones that are equal to" << OLD_VALUE
			<< "\n";

		std::cout << "Before: ";
		DisplayVector(vec);

		auto it = std::remove(vec.begin(), vec.end(), dataToRemove);
		vec.erase(it, vec.end());

		std::cout << "After:  ";
		DisplayVector(vec);
	}
	/**
	* remove_copy
	*	newVector will contain all the data from oldVector, except the dataToRemove. 
	*	oldVector will not be modified in the process.
	*	
	**/
	inline static void Remove_copy(Vector& oldVector, Vector& newVector, DataType dataToRemove)
	{
		std::cout
			<< "Remove_copy: \n"
			<< "Iterate through items and copy them to the new vector "
			<< "- except the value " << dataToRemove << "\n";

		auto it = remove_copy(oldVector.begin(), oldVector.end(), newVector.begin(), dataToRemove);
		newVector.erase(it, newVector.end());

		std::cout << "\nOldVector contains: \n";
		DisplayVector(oldVector);
		std::cout << "\nNewVector contains: \n";
		DisplayVector(newVector);
	}
	/**
	* remove_if
	*	For all the data between the iterators, the function will call the functor received as 3rd param
	*	(that receives a DataType as param) and remove the element if the function returns true 
	**/
	inline static void Remove_if(Vector& vec, const DataType& minValue)
	{
		std::cout
			<< "Remove_if: \n"
			<< "Iterate through items and remove them if the functor that iterates "
			<< "through the data returns true \n";

		std::cout << "Before: ";
		DisplayVector(vec);

		auto it = std::remove_if(
			vec.begin(), vec.end(), 
			[minValue](const DataType& val) { return val < minValue; }
		);
		vec.erase(it, vec.end());

		std::cout << "After:  ";
		DisplayVector(vec);
	}
	/**
	* remove_copy_if
	*	Combination of remove_if and remove_copy
	*	Copy all the data from the oldVector to the newVector, except for the values that returns
	*	true in the function receives as 3rd param
	*
	**/
	inline static void Remove_copy_if(Vector& oldVector, Vector& newVector, DataType minValue)
	{
		std::cout
			<< "Remove_copy_if: \n"
			<< "Iterate through items and copy them to the new vector (except for those "
			<< "that the functor that iterates through the data returns true '< 5') \n";


		auto it = remove_copy_if(
			oldVector.begin(), oldVector.end(), newVector.begin(), 
			[minValue](const DataType& val) { return val < minValue; });
		newVector.erase(it, newVector.end());

		std::cout << "\nOldVector contains: \n";
		DisplayVector(oldVector);
		std::cout << "\nNewVector contains: \n";
		DisplayVector(newVector);
	}

	//--------------------------------------------------------------------
	//                              EXAMPLES
	//--------------------------------------------------------------------
	namespace NRemovers
	{
		inline static void callFunctions()
		{
			std::cout << "----- Algorithms for removing the data ----- \n";
			
			// Remove
			AddSpacingLines();
			Remove(Vector(GeneratedVector), OLD_VALUE);

			// Remove_copy
			AddSpacingLines();
			Remove_copy(Vector(GeneratedVector), Vector(PRESET_CAPACITY), 3);

			// Remove_if
			AddSpacingLines();
			Remove_if(Vector(GeneratedVector), OLD_VALUE);

			// Remove_copy_if
			AddSpacingLines();
			Remove_copy_if(Vector(GeneratedVector), Vector(PRESET_CAPACITY), OLD_VALUE);

			std::cout << "\n";
		}
	} // NSetters
} // NSTL_Algorithms