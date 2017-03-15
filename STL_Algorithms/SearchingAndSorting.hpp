#pragma once
/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         SearchingAndSorting.hpp
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
	* find
	*	Returns the first occurance of an element into the data structure
	**/
	inline static void Find(Vector& vec, const DataType& dataToSearch)
	{
		std::cout
			<< "Find: \n"
			<< "Returns the first occurance of " << dataToSearch << " element into the data structure \n";

		auto foundAt = std::find(vec.begin(), vec.end(), dataToSearch);
		if (foundAt != vec.end())
		{
			std::cout << "Element " << dataToSearch << " found at location: " << foundAt - vec.begin();
		}
		else
		{
			std::cout << "Element " << dataToSearch << " not found.";
		}
		std::cout << "\n";
	}
	/**
	* find_if
	*	Returns the first occurence of an element that is accepted by the functor (first true occurence)
	**/
	inline static void Find_if(Vector& vec, DataType dataToSearch)
	{
		std::cout
			<< "Find_if: \n"
			<< "Returns the first occurence of an element that is accepted by the functor "
			<< "(first true occurence) \n";
		
		auto foundAt = std::find_if(
			vec.begin(), vec.end(),
			[dataToSearch](const DataType& item) { return item < dataToSearch; }
		);

		if (foundAt != vec.end())
		{
			std::cout << "First element less than " << dataToSearch << " is " << *foundAt 
				<< " and was found at location: " << (foundAt - vec.begin());
		}
		else
		{
			std::cout << "Could not find any element less than " << dataToSearch;
		}
		std::cout << "\n";
	}

	/**
	* find_if_not
	*	Returns the first occurence of an element that is not accepted by the functor (first false occurence)
	*
	*	The negate of the find_if 
	**/
	inline static void Find_if_not(Vector& vec, DataType dataToSearch)
	{
		std::cout
			<< "Find_if_not: \n"
			<< "Returns the first occurence of an element that is not accepted by the functor "
			<< "(first false occurence) \n";

		auto foundAt = std::find_if_not(
			vec.begin(), vec.end(),
			[dataToSearch](const DataType& item) { return item < dataToSearch; }
		);

		if (foundAt != vec.end())
		{
			std::cout << "First element that is bigger than " << dataToSearch << " is " << *foundAt
				<< "and it was found at location: " << (foundAt - vec.begin());
		}
		else
		{
			std::cout << "Could not find any element bigger than " << dataToSearch;
		}
		std::cout << "\n";
	}

	/**
	* sort
	*	Sort the vector
	**/
	inline static void Sort(Vector& vec)
	{
		std::cout
			<< "Sort: \n"
			<< "Sort the data structure \n";

		std::cout << "\nBefore: ";
		DisplayVector(vec);

		std::sort(vec.begin(), vec.end());

		std::cout << "\nAfter: ";
		DisplayVector(vec);

		std::cout << "\n";
	}
	/**
	* binary_search
	*	Performs a binary search on an element. 
	*	The data structure have to be sorted.
	*
	*	Returns true if the element was found.
	**/
	inline static void Binary_Search(Vector& vec, DataType dataToSearch)
	{
		std::cout
			<< "Binary_Search: \n"
			<< "Returns true if the element " << dataToSearch << "is found in the data structure \n";

		bool found = std::binary_search(vec.begin(), vec.end(), dataToSearch);
		
		std::cout << "Element " << dataToSearch << (found ? "was found" : "was not found") << "\n";
	}

	/**
	* all_of
	*	Iterate through all elements and return true if all of them returns true 
	*	by the functor received as param
	**/
	inline static void All_of(Vector& vec, DataType minValue)
	{
		std::cout
			<< "All_of: \n"
			<< "Returns true if all the elements returns true in the functor \n";

		bool allAreLess = std::all_of(
				vec.begin(), vec.end(),
				[minValue](const DataType& item) { return item < minValue; }
			);
		std::cout 
			<< (allAreLess ? "All" : "Not all") 
			<< " of the elements are less than " << minValue << "\n";
	}
	/**
	* any_of
	*	Iterate through all elements and return true if at least one of the element returns true
	*	by the functor received as param
	**/
	inline static void Any_of(Vector& vec, DataType minValue)
	{
		std::cout
			<< "Any_of: \n"
			<< "Returns true if at least one element returns true in the functor \n";

		if (std::any_of(
			vec.begin(), vec.end(),
			[minValue](const DataType& item) { return item < minValue; }
		))
		{
			std::cout << "At least one element is less than " << minValue;
		}
		else
		{
			std::cout << "No elements are less than " << minValue;
		}
		std::cout << "\n";
	}
	/**
	* none_of
	*	Iterate through all elements and return true if all of them returns false 
	*	by the functor received as param
	* 
	*	The opposite of all_of, probably it just negates that result 
	*	std::none_of = return !std::all_of
	**/
	inline static void None_of(Vector& vec, DataType minValue)
	{
		std::cout
			<< "None_of: \n"
			<< "Returns true if all the elements returns false in the functor \n";

		bool allAreNotLess = std::none_of(
			vec.begin(), vec.end(),
			[minValue](const DataType& item) { return item < minValue; }
		);
		std::cout
			<< (allAreNotLess ? "All" : "Not all")
			<< " of the elements are bigger than " << minValue << "\n";
	}

	//--------------------------------------------------------------------
	//                              EXAMPLES
	//--------------------------------------------------------------------
	namespace NSearchingAndSorting
	{
		inline static void callFunctions()
		{
			std::cout << "----- Algorithms for setting the data ----- \n";
			
			Vector vec = GeneratedVector;
			// Find
			AddSpacingLines();
			Find(vec, 100);
			Find(vec, OLD_VALUE);

			// Find_if
			AddSpacingLines();
			Find_if(vec, 100);
			Find_if(vec, OLD_VALUE);

			// Find_if_not
			AddSpacingLines();
			Find_if_not(vec, 100);
			Find_if_not(vec, OLD_VALUE);

			//Sort
			AddSpacingLines();
			Sort(vec);

			//Binary_search
			AddSpacingLines();
			Binary_Search(vec, OLD_VALUE);

			// All_of
			AddSpacingLines();
			All_of(vec, 100);
			All_of(vec, 0);

			// Any_of
			AddSpacingLines();
			Any_of(vec, 100);
			Any_of(vec, 0);

			// None_of
			AddSpacingLines();
			None_of(vec, 100);
			None_of(vec, 0);
		}
	} // NSearchingAndSorting
} // NSTL_Algorithms