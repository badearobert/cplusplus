#pragma once
/******************************************************************************
* Copyright (C) 12/27/2016
*
* @file         ObserverPatternExample.hpp
* @project		DesignPatterns_Observer
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* The observer pattern is a software design pattern in which an object, called the subject, 
* maintains a list of its dependents, called observers, and notifies them automatically of 
* any state changes, usually by calling one of their methods. 
*
* It is mainly used to implement distributed event handling systems. 
* The Observer pattern is also a key part in the familiar model–view–controller (MVC) architectural pattern.
* The observer pattern is implemented in numerous programming libraries and systems, 
* including almost all GUI toolkits.
*
* Indent:
* Define a one-to-many dependency between objects so that when one object changes state, all its dependents
* are notified and updated automatically.
*
* Drawbacks:
* - Cascade update may be 'heavy' in terms of time and CPU resources.
* - Harmless at the first glance, the operation of the subject can cause a number of updated 
*	observers and their dependent objects.
*
* Please take into account that the current implementation is not thread-safe!
* For that, we would need to add a mutex into all the functions.
* I skipped that because I wanted to present only the design pattern, and not other functionalities.
*
* Source: https://en.wikipedia.org/wiki/Observer_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <memory>		// for C++11 shared_ptr
#include <vector>		// for the vector of observers
#include <algorithm>	// for remove_if
#include <iostream>		// for screen output

namespace NDesignPatterns
{
	namespace NObserverPattern
	{
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------
		/**
		* The base class, will be kept in the observer vector of listeners
		**/
		class IListener
		{
		public:
			virtual void onUpdate() = 0;
		};

		/**
		* The implementation for listener #1
		**/
		class CListenerOne : public IListener
		{
		public:
			virtual void onUpdate() override 
			{ 
				std::cout << "onUpdate called in CListenerOne..." << std::endl;
			}
		};

		/**
		* The implementation for listener #2
		**/
		class CListenerTwo : public IListener
		{
		public:
			virtual void onUpdate() override
			{
				std::cout << "onUpdate called in CListenerTwo..." << std::endl;
			}
		};
		//------------------------------------------------------------------------
		//					OBSERVER IMPLEMENTATION 
		//------------------------------------------------------------------------
		class IObserver
		{
		public:
			/**
			* The observer should contain a public method that allows listeners to
			* register to a particular event.
			**/
			virtual void attach(std::shared_ptr<IListener> & listener) = 0;

			/**
			* The observer may also contain a detach method, to unregister a listener from
			* the notification list.
			**/
			virtual void detach(std::shared_ptr<IListener> & listener) = 0;

			/**
			* The function will notify all the registered listeners
			**/
			virtual void notifyListeners() = 0;
		};

		class CObserver: public IObserver
		{
		public:
			/**
			* Actual implementation of the attach function
			**/
			void attach(std::shared_ptr<IListener> & listener)
			{
				mListeners.push_back(listener);
				std::cout << "A listener has been attached." << std::endl;
			}

			/**
			* Actual implementation of the detach function.
			*
			* This is a bit tricky, because i've used an algorithm to do so.
			* (It will be explained further in the C++11 topic)
			*
			* First of all, i have a lambda function that will:
			* - store the listener received as param.
			* - return true if the iterated element from the vector is the one received as param
			*
			* remove_if will not remove the elements, but return an iterator with the last valid range.
			* Due to that, we need to call the erase function from the vector to clear the invalid items.
			*
			* 
			* We just need to know that detach will simply remove the listener from the registered list.
			**/
			void detach(std::shared_ptr<IListener> & listener)
			{
				mListeners.erase(
					std::remove_if(mListeners.begin(), mListeners.end(),
					[&listener](const std::shared_ptr<IListener>& current)
				{
					return listener == current;
				}), mListeners.end());

				std::cout << "A listener has been detached." << std::endl;
			}

			/**
			* Actual implementation of the notify function
			**/
			void notifyListeners()
			{
				// we iterate through all the listeners and call the update function
				for (const auto& listener : mListeners)
				{
					listener->onUpdate();
				}
				std::cout << std::endl;
			}
		private:
			/**
			* Our vector of listener objects currently registered
			**/
			std::vector < std::shared_ptr<IListener> > mListeners;
		};
	} // NObserverPattern
} // NDesignPatterns
