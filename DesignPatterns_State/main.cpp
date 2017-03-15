/******************************************************************************
* Copyright (C) 14/03/2017
*
* @file         main.cpp
* @project		DesignPatterns_State
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "StatePatternExample.hpp"
#include <iostream>

int main()
{
	using namespace NDesignPatterns::NStatePattern;
	using namespace std;

	CStateImpl stateObj;
	IState* state_active   = new CActiveState;
	IState* state_inactive = new CInactiveState;

	stateObj.setState(state_active);
	stateObj.open();
	stateObj.exec();

	stateObj.setState(state_inactive);
	stateObj.open();
	stateObj.exec();

	delete state_active;
	delete state_inactive;

	cin.get();
	return 0;
}