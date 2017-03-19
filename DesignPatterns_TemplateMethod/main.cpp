/******************************************************************************
* Copyright (C) 19/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_Template
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "TemplatePatternExample.hpp"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NTemplatePattern;
	using namespace std;

	CTemplate_1 templateImpl_1;
	templateImpl_1.start();
	
	CTemplate_2 templateImpl_2;
	templateImpl_2.start();


	cin.get();
	return 0;
}