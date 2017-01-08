#pragma once
/******************************************************************************
* Copyright (C) 08/01/2017
*
* @file         DecoratorPatternExample.hpp
* @project		DesignPatterns_Decorator
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
*  Decorator is a design pattern that allows behavior to be added to an individual object, 
* either statically or dynamically, without affecting the behavior of other objects from the same class.
*
* Source: https://en.wikipedia.org/wiki/Decorator_pattern
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>		// for printing in the call function
#include <string>
namespace NDesignPatterns
{
	namespace NDecoratorPattern
	{
		/**
		* CBaseDecorated is a base class with a virtual function.
		* All the decorator classes will keep a pointer to a base, 
		* and will call the virtual function from the base class.
		*
		* By stacking decorated classes one over another, the virtual 
		* function call will call the same function for each of them, sequentially.
		**/
		class CBase
		{
		public:
			/**
			* Function to be overwritten by classes that inherit from the base decorated
			**/
			virtual void print() = 0;
		};
		class CBaseDecorator: public CBase
		{
		public:
			CBaseDecorator(CBase* parent = NULL)
			{
				mParent = parent;
			}
			/**
			* Each other decorator will inherit from the base decorator class
			* The decorator subclasses will overwrite doPrint function.
			**/
			virtual void print() override
			{
				// we go recursive into the parent
				if (mParent)
					mParent->print();

				// when recursivity ends, we display the string
				doPrint();
			}

			virtual void doPrint()
			{
				std::cout << "CBaseDecorator doPrint has been called.." << std::endl;
			}
		protected:
			CBase* mParent;
		};

		class CDecorator1 : public CBaseDecorator
		{
		public:
			CDecorator1(CBase *parent)
			{
				mParent = parent;
			}

			virtual void doPrint() override
			{
				std::cout << "CDecorator1 doPrint has been called.." << std::endl;
			}

		};

		class CDecorator2 : public CBaseDecorator
		{
		public:
			CDecorator2(CBase *parent)
			{
				mParent = parent;
			}

			virtual void doPrint() override
			{
				std::cout << "CDecorator2 doPrint has been called.." << std::endl;
			}
		};
	} // NDecoratorPattern
} // NDesignPatterns
