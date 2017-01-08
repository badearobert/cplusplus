/******************************************************************************
* Copyright (C) 08/01/2017
*
* @file         main.cpp
* @project		DesignPatterns_Decorator
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "DecoratorPattern_Example.h"
#include <iostream>
#include <conio.h>

int main()
{
	using namespace NDesignPatterns::NDecoratorPattern;
	using namespace std;

	CBaseDecorator* obj = new CDecorator1(new CDecorator2(new CDecorator1(new CBaseDecorator)));
	obj->print();
	
	/* WHY IT WORKS?
	* We call the print function. 
	If it has a parent, it will call the print function for them first, and then it will call doPrint.

	CDecorator1 call print on his parent (CDecorator2)		- when done, we call doPrint
	CDecorator2 call print on his parent (CDecorator1)		- when done, we call doPrint
	CDecorator1 call print on his parent (CBaseDecorator)	- when done, we call doPrint

	CBaseDecorator have no parent. We return from recursive calls ->

	doPrint on CBaseDecorator	: display on screen
	doPrint on CDecorator1		: display on screen
	doPrint on CDecorator2		: display on screen
	doPrint on CDecorator1		: display on screen

	The order of the calls will change if we call doPrint before calling the function from the parent.
	*/
	
	_getch();
	return 0;
}