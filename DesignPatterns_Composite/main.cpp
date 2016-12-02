/******************************************************************************
* Copyright (C) 12/02/2016
*
* @file         main.cpp
* @project		DesignPatterns_Composite
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "CompositePatternExample.h"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NCompositePattern;
	using namespace std;
	
	// create the root object..
	auto root = make_shared<CComposite>(0);

	// create a container with two leafs, add to the root..
	auto container1 = make_shared<CComposite>(10);
	container1->addChild(make_shared<CLeaf>(11));
	container1->addChild(make_shared<CLeaf>(12));
	root->addChild(container1);

	// create another container of one leaf, add to the root
	auto container2 = make_shared<CComposite>(20);
	container2->addChild(make_shared<CLeaf>(21));
	root->addChild(container2);

	// create three more leafs and add to the root object
	root->addChild(make_shared<CLeaf>(31));
	root->addChild(make_shared<CLeaf>(32));
	root->addChild(make_shared<CLeaf>(33));

	root->displayData();
		
	system("pause");
	return 0;
}