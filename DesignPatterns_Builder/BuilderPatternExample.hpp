#pragma once
/******************************************************************************
* Copyright (C) 19/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_Builder
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* The builder pattern is an object creation software design pattern. 
* The pattern uses another object, a builder, that receives each initialization 
* parameter step by step and then returns the resulting constructed object at once.
*
* It is also used in relation with the Composite pattern, to avoid any mistakes when creating the
* so-called tree, due to all classes being inherited from the same base class (and that could link 
* to any node, even if it was unintentional).
*
* Usually, the builder functions return reference / pointer to the builder itself,
* so the function calls can be continued, as it is with the cout operator.
*
* Source: https://en.wikipedia.org/wiki/Builder_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <string>
#include <vector>
#include <iostream>

namespace NDesignPatterns
{
	namespace NBuilderPattern
	{
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------
		class CData
		{
		public:
			/**
			* Should be called only if the object is valid
			**/
			void display()
			{ 
				std::cout << "Data is: " << mData << std::endl;
				std::cout << "Vector contains: ";
				
				for (const auto& i : mVector)
					std::cout << i << " ";

				std::cout << std::endl;
			}

		private:
			/**
			* Some data we hold
			**/
			void* mData;

			/**
			* A container of data
			**/
			std::vector<uint32_t> mVector;

			friend class CDataBuilder;
		};

		//------------------------------------------------------------------------
		//							BUILDER CLASS
		//------------------------------------------------------------------------
		class CDataBuilder
		{
		public:

			/**
			* This function will return the object
			* The developer should call it after the object is fully built
			**/
			CData* getObject() { return mData; }

			CDataBuilder& init()
			{
				/* do some init stuff. */
				mData = new CData;
				return *this;
			}

			/**
			* Set something in our object
			**/
			CDataBuilder& setData(void* ptr)
			{
				mData->mData = ptr;
				return *this;
			}

			CDataBuilder& addItem(const uint32_t data)
			{
				mData->mVector.push_back(data);
				return *this;
			}

			/**
			* Pointer to the object we will return to the caller
			**/
			CData* mData;
		};
	} // NBuilderPattern
} // NDesignPatterns
