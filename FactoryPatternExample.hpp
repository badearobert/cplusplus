#pragma once
/******************************************************************************
* Copyright (C) 10/15/2016
*
* @file         FactoryPatternExample.hpp
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
*
* Factory method pattern is a creational pattern that uses factory methods to deal with the problem of creating objects 
* without having to specify the exact class of the object that will be created. 
* 
* This is done by creating objects by calling a factory method—either specified in an interface 
* and implemented by child classes, or implemented in a base class and optionally overridden by 
* derived classes—rather than by calling a constructor.
* 
* Source: https://en.wikipedia.org/wiki/Factory_method_pattern
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <memory>		// for C++11 unique_ptr
#include <string>		// param in factory pattern implementation

namespace NDesignPatterns
{
	namespace NFactoryPattern
	{
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------

		/*
		* CBaseClass is abstract due to containing at least one pure virtual function (note the '= 0' at the end)
		* It cannot be instantiated, the call function need to be overloaded by the derived classes
		*
		* Note		The void received as parameter is purely visual. 
		*		The class definition was implemented in the same hpp line, this is called inlining.
		*		I've decided to have it this way so we have only one file for each pattern.
		*		
		*/
		class CBaseClass
		{
			virtual void call(void) = 0;
		};

		/*
		* Note		The override keyword after method declaration, it was implemented starting with C++11.
		*		Its purpose is to notify the reader that the function is overriding an inherited virtual function
		*		The compiler will crash if override is used on a non virtual function
		*/
		class CDerivedClassOne : public CBaseClass
		{
			void call(void) override { /* logic specific to CDerivedClassOne */ }
		};
		class CDerivedClassTwo : public CBaseClass
		{
			void call(void) override {  /* logic specific to CDerivedClassTwo */ }
		};

		/*
		* Note:		This object is so called the NULL OBJECT PATTERN. 
		*		It is used to mimic the functionality of a class by deriving the base class,
		*		without creating any logic for its overloaded functions.
		*		In our case, we use to return the reference of the object created if the factory method
		*		did not enter any of the implemented cases.
		*/
		class CNullObject : public CBaseClass
		{
			void call(void) override { /* do nothing */ }
		};

		//------------------------------------------------------------------------
		//			FACTORY METHOD PATTERN IMPLEMENTATION
		//------------------------------------------------------------------------
		class CFactory
		{
		public:
			//------------------------------------------------------------------------
			//			 IMPLEMENTATION IN C++0X
			//------------------------------------------------------------------------
			/**
			* Note		The function will return nullptr if we did not matched any cases.
			*		When used with multiple values, the factory is most likely implemented using switch 
			*			
			*		We can use CNullObject at the end to return a null object, or we can use nullptr (both valid)
			**/
			static CBaseClass* CreateObject_Example1(std::string objectName)
			{
				if (objectName == "CDerivedClassOne")
				{
					return new CDerivedClassOne();
				}
				else if (objectName == "CDerivedClassTwo")
				{
					return new CDerivedClassTwo();
				}
				return new CNullObject();
			}
			//------------------------------------------------------------------------
			//			 IMPLEMENTATION IN C++11
			//------------------------------------------------------------------------
			/**
			* Note		In C++11 we have a function that expects a unique_ptr container
			*		We can either return a null object ptr, or return an unique_ptr without ownership
			**/
			static std::unique_ptr<CBaseClass> CreateObject_Example2(std::string objectName)
			{
				if (objectName == "CDerivedClassOne")
				{
					return std::unique_ptr<CBaseClass>(new CDerivedClassOne);
				}
				else if (objectName == "CDerivedClassTwo")
				{
					return std::unique_ptr<CBaseClass>(new CDerivedClassTwo);
				}
				return std::unique_ptr<CBaseClass>();
			}
		};
	

	} // NFactoryPattern
} // NDesignPatterns
