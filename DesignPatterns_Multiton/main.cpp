/******************************************************************************
* Copyright (C) 11/15/2016
*
* @file         main.cpp
* @project		DesignPatterns_Multiton
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "MultitonPatternExample.hpp"
#include <iostream>

class CTestClass {
public:

};
int main()
{
	using namespace NDesignPatterns::NMultitonPattern;
	using namespace std;


	// getting the multiton object for the string 'item1'...
	weak_ptr<CTestClass> obj1 = CMultiton<CTestClass>::get("item1");

	// getting the same multiton object for the string 'item1'...obj1 == obj2
	weak_ptr<CTestClass> obj2 = CMultiton<CTestClass>::get("item1");
	
	// getting the multiton object for the string 'item2'...obj1 != obj3
	weak_ptr<CTestClass> obj3 = CMultiton<CTestClass>::get("item2");



	cout << "Memory address of the objects: " << endl;
	cout << "&obj1: \t" << &obj1 << endl;
	cout << "&obj2: \t" << &obj2 << endl;
	cout << "&obj3: \t" << &obj3 << endl;

	cout << "obj1" << ((shared_ptr<CTestClass>(obj1) == shared_ptr<CTestClass>(obj2)) ? " == " : " != ") << "obj2" << endl;
	cout << "obj1" << ((shared_ptr<CTestClass>(obj1) == shared_ptr<CTestClass>(obj3)) ? " == " : " != ") << "obj3" << endl;

	
	
	cout << endl;

	system("pause");
	return 0;
}