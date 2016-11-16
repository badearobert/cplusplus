/******************************************************************************
* Copyright (C) 11/15/2016
*
* @file         main.cpp
* @project		DesignPatterns_Factory
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "FactoryPatternExample.hpp"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NFactoryPattern;
	using namespace std;

	cout << "C++ 0x part" << endl;

	// C++0x
	{
		// creating an object of type CDerivedClassOne...
		CBaseClass* derivedClassOnePtr = CFactory::CreateObject_Example1("CDerivedClassOne");
		derivedClassOnePtr->call();

		// creating an object of type CDerivedClassTwo...
		CBaseClass* derivedClassTwoPtr = CFactory::CreateObject_Example1("CDerivedClassTwo");
		derivedClassTwoPtr->call();

		// creating a null object..	
		CBaseClass* nullObjectPtr = CFactory::CreateObject_Example1("null object");
		nullObjectPtr->call();

		// deallocating the resources..
		delete derivedClassOnePtr;
		delete derivedClassTwoPtr;
		delete nullObjectPtr;
	}


	cout << endl << "C++11 part" << endl;


	// C++11
	{
		// creating an object of type CDerivedClassOne...
		unique_ptr<CBaseClass> derivedClassOnePtr = CFactory::CreateObject_Example2("CDerivedClassOne");
		derivedClassOnePtr->call();

		// creating an object of type CDerivedClassTwo...
		unique_ptr<CBaseClass> derivedClassTwoPtr = CFactory::CreateObject_Example2("CDerivedClassTwo");
		derivedClassTwoPtr->call();

		// creating a null object..unique ptr is not set
		unique_ptr<CBaseClass> nullObjectPtr = CFactory::CreateObject_Example2("null object");
		if (nullObjectPtr) 
		{
			nullObjectPtr->call();
		}
		else 
		{
			cout << "nullObjectPtr does not owns a pointer" << endl;
		}

		// no need to deallocate, unique-ptrs destroy themselves when leaving the containing scope
	}

	system("pause");
	return 0;
}