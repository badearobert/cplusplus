/******************************************************************************
* Copyright (C) 11/15/2016
*
* @file         main.cpp
* @project		DesignPatterns_Singleton
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "SingletonPatternExample.hpp"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NSingletonPattern;
	using namespace std;

	// get instance of the singleton..
	CSingleton & singletonObjectOne = CSingleton::getInstance();
		
	// get the same singleton instance..
	CSingleton & singletonObjectTwo = CSingleton::getInstance();

	// check the instances for equality. should be the same object, same address memory
	if (&singletonObjectOne == &singletonObjectTwo)
	{
		cout << "singletonObjectOne == singletonObjectTwo" << endl;
		cout << "Memory address of the objects: " << &singletonObjectOne << " vs " << &singletonObjectTwo << endl;
	}
	

	system("pause");
	return 0;
}