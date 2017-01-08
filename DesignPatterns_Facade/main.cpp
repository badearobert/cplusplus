/******************************************************************************
* Copyright (C) 02/01/2017
*
* @file         main.cpp
* @project		DesignPatterns_Facade
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "FacadePatternExample.h"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NFacadePattern;
	using namespace std;

	CSystemState::getInstance().shutdown();
	CSystemState::getInstance().restart();
	CSystemState::getInstance().sleep();
	system("pause");
	return 0;
}