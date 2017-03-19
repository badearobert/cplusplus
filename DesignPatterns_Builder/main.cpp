/******************************************************************************
* Copyright (C) 19/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_Builder
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "BuilderPatternExample.hpp"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NBuilderPattern;
	using namespace std;

	CDataBuilder builder;
	CData* dataPtr = nullptr;

	// Aproach 1
	builder.init();
	builder.setData(nullptr);
	builder.addItem(10);
	builder.addItem(20);

	CData* data_1 = builder.getObject();
	data_1->display();

	// Approach 2
	CData* data_2 = builder.init().setData(nullptr).addItem(30).addItem(40).getObject();
	data_2->display();

	delete data_1;
	delete data_2;

	cin.get();
	return 0;
}