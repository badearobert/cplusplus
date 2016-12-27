/******************************************************************************
* Copyright (C) 12/27/2016
*
* @file         main.cpp
* @project		DesignPatterns_Observer
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "ObserverPatternExample.hpp"
int main()
{
	using namespace NDesignPatterns::NObserverPattern;

	CObserver observer;
	auto listenerOne = std::shared_ptr<IListener>(new CListenerOne);
	auto listenerTwo = std::shared_ptr<IListener>(new CListenerTwo);

	// attaching both listeners and notifying them about an event...
	observer.attach(listenerOne);
	observer.attach(listenerTwo);
	observer.notifyListeners();

	// detaching one of the listeners and notifying the remaining registered ones...
	observer.detach(listenerTwo);
	observer.notifyListeners();

	system("pause");
	return 0;
}