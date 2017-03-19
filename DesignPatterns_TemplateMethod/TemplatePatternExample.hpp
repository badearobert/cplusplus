#pragma once
/******************************************************************************
* Copyright (C) 19/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_Template
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* The template method pattern is a behavioral design pattern that defines the program 
* skeleton of an algorithm in an operation, deferring some steps to subclasses.
*
* It lets one redefine certain steps of an algorithm without changing the algorithm's structure.
*
* Source: https://en.wikipedia.org/wiki/Template_method_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

namespace NDesignPatterns
{
	namespace NTemplatePattern
	{
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------
		class CAlgorithm
		{
		public:
			/**
			* The main function, that will call all the other functions, both 
			* from base class and the virtuals
			**/
			void start()
			{
				initData();
				prepareData();
				computeData();
				filterData();
				sortData();
				displayData();

				std::cout << std::endl;
			}
		protected:
			/**
			* Below are a bunch of functions that are called when the algorithm is applied.
			* The virtuals one are supposed to be overriden in subclasses
			**/
			void initData() { std::cout << "Initializing data..." << std::endl; }
			void prepareData() { std::cout << "Preparing data..." << std::endl; }
			virtual void computeData() = 0;
			virtual void filterData() = 0;
			void sortData() { std::cout << "Sorting data..." << std::endl; }
			void displayData() { std::cout << "Displaying data..." << std::endl; }
		};
		//------------------------------------------------------------------------
		//					IMPLEMENTATION OF ALG #1
		//------------------------------------------------------------------------
		class CTemplate_1 : public CAlgorithm
		{
			virtual void computeData() override 
			{ 
				std::cout << "Compute data for CTemplate_1..." << std::endl;
			}
			virtual void filterData() override
			{
				std::cout << "Filter data for CTemplate_1..." << std::endl;
			}
		};
		//------------------------------------------------------------------------
		//					IMPLEMENTATION OF ALG #2
		//------------------------------------------------------------------------
		class CTemplate_2 : public CAlgorithm
		{
			virtual void computeData() override
			{
				std::cout << "Compute data for CTemplate_2..." << std::endl;
			}
			virtual void filterData() override
			{
				std::cout << "Filter data for CTemplate_2..." << std::endl;
			}
		};
	} // NTemplatePattern
} // NDesignPatterns
