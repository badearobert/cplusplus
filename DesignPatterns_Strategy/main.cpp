/******************************************************************************
* Copyright (C) 12/27/2016
*
* @file         main.cpp
* @project		DesignPatterns_Strategy
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "StrategyPatternExample.hpp"
int main()
{
	using namespace NDesignPatterns::NStrategyPattern;

	CStrategyPatternImplementation strategyTest;

	// calling the first time - no strategy applied
	strategyTest.doStrategy();

	// calling the second time - strategy one applied
	strategyTest.setStrategy(std::unique_ptr<CBaseStrategy>(new CStrategyOne));
	strategyTest.doStrategy();

	// calling the third time - strategy two applied
	strategyTest.setStrategy(std::unique_ptr<CBaseStrategy>(new CStrategyTwo));
	strategyTest.doStrategy();


	system("pause");
	return 0;
}