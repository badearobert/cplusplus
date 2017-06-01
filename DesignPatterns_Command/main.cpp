/******************************************************************************
* Copyright (C) 29/04/2016
*
* @file         main.cpp
* @project		DesignPatterns_Command
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "CommandPatternExample.h"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NCommandPattern;
	using namespace std;

	CCommandContainer cmdContainer;
	cmdContainer.callFunction(0);
	cmdContainer.callFunction(1);
	cmdContainer.callFunction(2);

	cin.get();
	return 0;
}