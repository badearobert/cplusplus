#pragma once
/******************************************************************************
* Copyright (C) 12/02/2016
*
* @file         AdaptableClass.h
* @project		DesignPatterns_Adapter
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* An adapter helps two incompatible interfaces to work together. 
* This is the real world definition for an adapter. 
* Interfaces may be incompatible but the inner functionality should suit the need. 
* The Adapter design pattern allows otherwise incompatible classes to work together by converting the interface of 
* one class into an interface expected by the clients.
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>			//  for using cout function

namespace NDesignPatterns
{
	namespace NAdapterPattern
	{
		struct AdaptableData {
			void displayData() {
				std::cout << "integerData1: " << integerData1 << std::endl;
				std::cout << "integerData2: " << integerData2 << std::endl;
				std::cout << "booleanData: "  << booleanData  << std::endl;
			}
			
			int integerData1;
			int integerData2;
			bool booleanData;
		};

		/*
		* Note:			This class cannot be modified at all.
		*				All the functions inside will be called from our adapter class.
		*/
		class CAdaptableClass
		{
		public:
			/**
			* Constructor for our adaptable class.
			**/
			CAdaptableClass() { mData = {}; }

			/**
			* Function to display the private data
			**/
			void displayData() { mData.displayData(); }

			/**
			* Setter for our private data
			**/
			void setData(const AdaptableData& input) {
				mData = input;
			}
		private:
			/**
			* Our private data 
			**/
			AdaptableData mData;
		};

	} // NAdapterPattern
} // NDesignPatterns
