#pragma once
/******************************************************************************
* Copyright (C) 02/01/2017
*
* @file         FacadePatternExample.hpp
* @project		DesignPatterns_Facade
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* A facade is an object that provides a simplified interface to a larger body 
* of code, such as a class library. 
*
* A facade can:
* - make a software library easier to use, understand and test, 
*	since the facade has convenient methods for common tasks
* - make the library more readable, for the same reason
* - reduce dependencies of outside code on the inner workings of a library, since most code uses 
*	the facade, thus allowing more flexibility in developing the system
* - wrap a poorly designed collection of APIs with a single well-designed API.
*
* Usage:
* A Facade is used when an easier or simpler interface to an underlying object is desired
* 
* Alternatively, the developer can use the following patterns:
* - adapter, when the wrapper must respect a particular interface and must support polymorphic behavior. 
* - decorator makes it possible to add or alter behavior of an interface at run-time.
*
* Source: https://en.wikipedia.org/wiki/Facade_pattern
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>		// for printing in the call function
#include <vector>		// for processes
#include <string>	

namespace NDesignPatterns
{
	namespace NFacadePattern
	{
		//------------------------------------------------------------------------
		//			INIIALIZATION OF THE VARIABLES
		//------------------------------------------------------------------------

		/**
		* CCommandsReceiver will execute system commands
		**/
		class CCommandsReceiver
		{
		private:
			explicit CCommandsReceiver() 
			{
				/**
				* Private constructor, we cannot create objects of this type
				**/
				std::cout << "Commands Receiver instance created, system is ready to receive commands." << std::endl;
			}

			/**
			* we need access to the class from inside-out
			**/
			friend class CSystemState;

		public:
			enum ESystemState
			{
				/**
				* Shutdown the system
				**/
				Shutdown,

				/**
				* Restarts the system
				**/
				Restart,
				/**
				* Log off the user
				**/
				Sleep
			};

		protected:
			void changeComputerState(ESystemState newState) const
			{
				// ask confirmation from the user
				bool bContinue = doAlertUnsaved();

				if (bContinue)
				{
					// log the changing state

					// close the processes
					doCloseProcesses();

					// end the session 
					endCurrentSession();

					if (newState != Sleep)
					{
						// we close or restart the pc
						bool bRestart = (newState == Restart);

						closeTheComputer(bRestart);
					}
				}
			}
		private:

			/**
			* Returns true if the user agreed to continue with the system closing down
			**/
			bool doAlertUnsaved() const
			{ 
				// alert the user regarding unsaved documents
				return true;
			}

			bool doCloseProcesses() const
			{ 
				// send the shutdown signal to all active processes 
				return true;
			}

			void endCurrentSession() const
			{ 
				// end the session 
			}

			void closeTheComputer(bool restart = false) const
			{ 
				// send the shutdown/restart signal to the power management device 
			}
		};

		//------------------------------------------------------------------------
		//			          FACADE PATTERN IMPLEMENTATION
		//------------------------------------------------------------------------
		class CSystemState
		{
		private:
			/**
			* We cannot create instances, we need to use the singleton Instance
			**/
			explicit CSystemState() { }
		public:
			/**
			* The only instance of this class (let's ignore move/copy/equal constructors for now)
			**/
			static const CSystemState& getInstance()
			{
				static CSystemState instance;
				return instance;
			}

			/**
			* Shutdown the entire system
			**/
			void shutdown() const
			{
				std::cout << "Shutdown command received from the user." << std::endl;
				mCommandsExecuter.changeComputerState(CCommandsReceiver::Shutdown);
			}

			/**
			* Restart the system
			**/
			void restart() const
			{
				std::cout << "Restart command received from the user." << std::endl;
				mCommandsExecuter.changeComputerState(CCommandsReceiver::Restart);
			}

			/**
			* Log off
			**/
			void sleep() const
			{
				std::cout << "Sleep command received from the user." << std::endl;
				mCommandsExecuter.changeComputerState(CCommandsReceiver::Sleep);
			}
		private:
			/**
			* Instance to commands, due to private access as a friend class
			**/
			CCommandsReceiver mCommandsExecuter;
		};
	} // NFacadePattern
} // NDesignPatterns
