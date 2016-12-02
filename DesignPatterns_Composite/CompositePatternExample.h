#pragma once
/******************************************************************************
* Copyright (C) 12/02/2016
*
* @file         main.cpp
* @project		DesignPatterns_Composite
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* In software engineering, the composite pattern is a partitioning design pattern. 
* The composite pattern describes that a group of objects is to be treated in the same way as a single instance of an object. 
* The intent of a composite is to "compose" objects into tree structures to represent part-whole hierarchies. 
* Implementing the composite pattern lets clients treat individual objects and compositions uniformly.
*
* Source: https://en.wikipedia.org/wiki/Composite_pattern
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>		// for using cout function
#include <vector>
#include <memory>		// for shared_ptr

namespace NDesignPatterns
{
	namespace NCompositePattern
	{
		/**
		* Base class, overridden by leaf and nodes
		**/
		class CBaseComposite
		{
		public:
			/**
			* Constructor for base class. It receives the int data for the node.
			* Note: The constructor is not explicit so we can do implicit cast!
			**/
			CBaseComposite(int data) : mData(data) { }

			/**
			* This function is left to be overwritten in the inherited classes
			**/
			virtual void displayData() = 0;

		protected:
			/**
			* Our private data. 
			**/
			int mData;

		};

		/**
		* Container class
		* Used to keep other objects of the base type
		*.
		* Note:			It contains the addChild function which will add elements in its vector
		*				The objects can be either of same type (containers) or leafs
		**/
		class CComposite : public CBaseComposite
		{
		public:
			/**
			* Default constructor
			**/
			CComposite(int data) : CBaseComposite(data) { } 

			/**
			* Function to add element in the container - can be a leaf or another container
			**/
			void addChild(std::shared_ptr<CBaseComposite> obj) { mObjects.push_back(obj); }

			/**
			* Function that will iterate through all elements and display the data
			**/
			void displayData() override {
				// display the current node...
				std::cout << "------------------->" << std::endl;
				std::cout << "Container | value: " << mData << std::endl;
				
				// display the child nodes...
				for each (auto &elem in mObjects) {
					elem->displayData();
				}
				std::cout << "<-------------------" << std::endl;
			}
		private:
			/**
			* Vector of objects of base class
			**/
			std::vector<std::shared_ptr<CBaseComposite>> mObjects;
		};

		/**
		* Leaf class - It will only hold the data member
		**/
		class CLeaf : public CBaseComposite
		{
		public:
			/**
			* Default constructor
			**/
			CLeaf(int data) : CBaseComposite(data) { }

			/**
			* Function that will display the leaf data
			**/
			void displayData() override {
				std::cout << "Leaf | value: " << mData << std::endl;
			}
		};
	} // NCompositePattern
} // NDesignPatterns