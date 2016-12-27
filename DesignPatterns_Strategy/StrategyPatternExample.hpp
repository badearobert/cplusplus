#pragma once
/******************************************************************************
* Copyright (C) 12/27/2016
*
* @file         StrategyPatternExample.hpp
* @project		DesignPatterns_Strategy
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* There are common situations when classes differ only in their behavior.
* For these cases it is a good idea to isolate the algorithms in separate classes 
* in order to have the ability to select different algorithms at runtime.
*
* Intent:
* - Define a family of algorithms, encapsulate each one, and make them interchangeable.
*/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <memory>		// for C++11 unique_ptr

namespace NDesignPatterns
{
	namespace NStrategyPattern
	{
		/**
		* NOTE 		We define a base class (CBaseStrategy) that contains a virtual function
		*			This function will be overwritten by all of its subclasses
		*			
		*			The strategy pattern will hold a reference/pointer to the current strategy
		*			and will call this virtual function at a place in time.
		*			The user will be able to switch between strategies at runtime, if needed.
		*
		**/
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------
		/**
		* The base class, will be kept as a pointer in the strategy-caller class instance
		**/
		class CBaseStrategy
		{
		public:
			/**
			* Function to be overwritten by inherited classes
			**/
			virtual void executeStrategy() = 0;
		};

		/**
		* The implementation for strategy #1
		**/
		class CStrategyOne : public CBaseStrategy
		{
		public:
			/**
			* Function overwritten for strategy one
			**/
			virtual void executeStrategy() override
			{
				std::cout << "Calling the strategy number one..." << std::endl;
			}
		};

		/**
		* The implementation for strategy #2
		**/
		class CStrategyTwo : public CBaseStrategy
		{
		public:
			/**
			* Function overwritten for strategy two
			**/
			virtual void executeStrategy() override
			{
				std::cout << "Calling the strategy number two..." << std::endl;
			}
		};

		//------------------------------------------------------------------------
		//			STRATEGY PATTERN IMPLEMENTATION - 
		//------------------------------------------------------------------------
		class CStrategyPatternImplementation
		{
		public:
			/**
			* NOTE:			The impl can receive a default strategy on constructor. 
			*				This is not always the case and differs based on the developer's needs.
			**/
			CStrategyPatternImplementation() { }

			/**
			* This function will allow us to switch between strategies at runtime
			**/
			void setStrategy(std::unique_ptr<CBaseStrategy> strategy)
			{
				mStrategyImpl = std::move(strategy);
			}

			/**
			* This function will make use of our strategy
			* It should call a particular (virtual) function from the strategy obj
			**/
			void doStrategy()
			{
				// execute some default code for all the strategies..
				std::cout << "Doing Initialization and other code for all strategies..." << std::endl;

				// execute the current strategy, if we have one (we could also add a default one)
				if (mStrategyImpl)
				{
					mStrategyImpl->executeStrategy();
				}
				else
				{
					std::cout << "Skipping strategy, we don't have one set..." << std::endl;
				}

				// release memory and execute another default code..
				std::cout << "After the strategy function call..." << std::endl;

				std::cout << std::endl;
			}
		private:
			std::unique_ptr<CBaseStrategy> mStrategyImpl;
		};
	} // NStrategyPattern
} // NDesignPatterns
