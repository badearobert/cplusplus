/******************************************************************************
* Copyright (C) 14/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_Mediator
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "MediatorPatternExample.hpp"
#include <memory>
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NMediatorPattern;
	using namespace std;

	CMediatorImpl mediator;
	auto client_1 = std::make_shared<ISource>(mediator, ADDRESS_JOHN);
	auto client_2 = std::make_shared<ISource>(mediator, ADDRESS_MICHAEL);
	auto client_3 = std::make_shared<ISource>(mediator, ADDRESS_ROBERT);
	auto client_4 = std::make_shared<ISource>(mediator, ADDRESS_DIANA);

	mediator.addSource(client_1);
	mediator.addSource(client_2);
	mediator.addSource(client_3);
	mediator.addSource(client_4);

	client_1->sendMessage(ADDRESS_MICHAEL, "Hello Michael!");
	client_2->sendMessage(ADDRESS_JOHN, "Hello John!");
	client_3->sendMessage(ADDRESS_BROADCAST, "Hello everyone!");

	cin.get();
	return 0;
}