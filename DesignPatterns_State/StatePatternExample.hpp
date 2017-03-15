#pragma once
/******************************************************************************
* Copyright (C) 14/03/2017
*
* @file         StatePatternExample.hpp
* @project		DesignPatterns_State
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* The state pattern is a behavioral software design pattern that implements
* a state machine in an object-oriented way. 
* With the state pattern, a state machine is implemented by implementing each
* individual state as a derived class of the state pattern interface, and implementing 
* state transitions by invoking methods defined by the pattern's superclass.
* 
* The state pattern can be interpreted as a strategy pattern which is able to switch
* the current strategy through invocations of methods defined in the pattern's interface.
*
* Source: https://en.wikipedia.org/wiki/State_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>

namespace NDesignPatterns
{
	namespace NStatePattern
	{
		//------------------------------------------------------------------------
		//						INTERFACE FOR OUR STATES
		//------------------------------------------------------------------------
		/**
		* This class will contain all the functions that change based on the state.
		* The functions will be virtual and will be overwritten in each subclass.
		* We will have a subclass for each state we will have, and the functions
		* will contain the implementation that should exist for that particular state.
		**/
		class IState {
		public:
			virtual bool open(void)   = 0;
			virtual bool close(void)  = 0;
			virtual bool exec(void)   = 0;
		};
		//------------------------------------------------------------------------
		//				IMPLEMENTATION OF THE LOGIC FOR ACTIVE STATE
		//------------------------------------------------------------------------
		class CActiveState : public IState {
		public:
			virtual bool open(void) override
			{
				// in active state, cannot open..
				std::cout << "In active state, cannot open.." << std::endl;
				return false;
			}
			virtual bool close(void) override
			{
				// in active state, closing..
				std::cout << "In active state, closing.." << std::endl;
				return true;
			}
			virtual bool exec(void) override
			{
				// in active state, executing..
				std::cout << "In active state, executing.." << std::endl;
				return true;
			}
		};
		//------------------------------------------------------------------------
		//				IMPLEMENTATION OF THE LOGIC FOR INACTIVE STATE
		//------------------------------------------------------------------------
		class CInactiveState : public IState {
		public:
			virtual bool open(void) override
			{
				// in inactive state, opening..
				std::cout << "In inactive state, opening.." << std::endl;
				return true; 
			}
			virtual bool close(void) override
			{
				// in inactive state, cannot close..
				std::cout << "In inactive state, cannot close.." << std::endl;
				return false;
			}
			virtual bool exec(void) override
			{
				// in inactive state, we cannot execute..
				std::cout << "In inactive state, cannot execute.." << std::endl;
				return false;
			}
		};
		
		//------------------------------------------------------------------------
		//				IMPLEMENTATION OF THE ACTUAL STATE HANDLER
		//------------------------------------------------------------------------
		/**
		* We will have a class that contain a pointer to our interface.
		* The pointer can point to any state object, and will delegate to the existant virtual functions
		**/
		class CStateImpl {
		public:
			void setState(IState *state) { mStatePtr = state; }

			bool open(void)  { return mStatePtr->open();  }
			bool close(void) { return mStatePtr->close(); }
			bool exec(void)  { return mStatePtr->exec();  }

		private:
			IState *mStatePtr;
		};
		
	} // NStatePattern
} // NDesignPatterns
