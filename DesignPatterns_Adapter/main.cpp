/******************************************************************************
* Copyright (C) 12/02/2016
*
* @file         main.cpp
* @project		DesignPatterns_Adapter
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "AdapterPatternExample.h"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NAdapterPattern;
	using namespace std;

	CAdaptableClass adaptableClass;
	CAdapter adapter(adaptableClass);

	cout << "The initial adaptable class data is: " << endl;
	adapter.displayData();
	cout << endl;

	cout << "Updating the data through the adapter..." << endl;

	AdapterDataInput output;
	output.booleanDataCopy = true;
	output.integerData1Copy = 123;
	output.integerData2Copy = 456;
	output.unusedDouble = 7.89;
	output.unusedInteger = 999;
	adapter.setDataFromInput(output);

	adapter.displayData();
	cout << endl;

	system("pause");
	return 0;
}