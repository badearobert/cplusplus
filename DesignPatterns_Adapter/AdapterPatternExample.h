#pragma once
/******************************************************************************
* Copyright (C) 12/02/2016
*
* @file         AdapterPatternExample.h
* @project		DesignPatterns_Adapter
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* In software engineering, the adapter pattern is a software design pattern (also known as Wrapper, an alternative naming 
* shared with the Decorator pattern) that allows the interface of an existing class to be used as another interface.
* It is often used to make existing classes work with others without modifying their source code.
*
* Source: https://en.wikipedia.org/wiki/Adapter_pattern
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "AdaptableClass.h"
#include <iostream>				// for using cout function

namespace NDesignPatterns
{
	namespace NAdapterPattern
	{
		/**
		* Structure to use as example in our calls.
		* We will send this structure to our adapter and it will update the adaptee correspondent structure 
		**/
		struct AdapterDataInput {
			int integerData1Copy;
			int integerData2Copy;
			bool booleanDataCopy;
			int unusedInteger;
			double unusedDouble;
		};

		class CAdapter
		{
		public:
			/**
			* Our adapter class will receive on ctor a reference to the object it should adapt
			**/
			CAdapter(CAdaptableClass& adapter) : mAdapter(adapter) { }

			/**
			* This function will receive some input from the user and we will set the data to the adapter
			* based on what we are interested on
			**/
			void setDataFromInput(const AdapterDataInput &input) {
				AdaptableData newData;
				newData.integerData1 = input.integerData1Copy;
				newData.integerData2 = input.integerData2Copy;
				newData.booleanData = input.booleanDataCopy;

				mAdapter.setData(newData);
			}

			/**
			* Function to display the data.
			* This function will call the display data function from our adapter instance
			**/
			void displayData() {
				mAdapter.displayData();
			}
		private:
			/**
			* Reference to our adaptable class instance
			**/
			CAdaptableClass &mAdapter;
		};



	} // NAdapterPattern
} // NDesignPatterns
