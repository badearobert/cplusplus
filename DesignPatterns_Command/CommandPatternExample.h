#pragma once
/******************************************************************************
* Copyright (C) 29/04/2016
*
* @file         main.cpp
* @project		DesignPatterns_Command
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
*
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>		// for using cout function
#include <functional>
#include <memory>
#include <vector>
#include <string>
namespace NDesignPatterns
{
	namespace NCommandPattern
	{
		/**
		* Namespace containing the available commands
		**/
		namespace NCommands
		{
			using CommandFunction = std::function<void()>;
			CommandFunction function1 = []() { std::cout << "Called function1 \n";  };
			CommandFunction function2 = []() { std::cout << "Called function2 \n";  };
			CommandFunction function3 = []() { std::cout << "Called function3 \n";  };
		}

		/**
		* Data for a specific command
		**/
		class Command
		{
		public:
			Command(std::string description, NCommands::CommandFunction functor)
				: mDescription(description)
				, mFunctor(functor)
			{

			}

			std::string getDescription() const { return mDescription; }
			void execute() { mFunctor(); }

		private:
			std::string mDescription;
			NCommands::CommandFunction mFunctor;
		};

		/**
		* Container of commands. 
		* This class will hold the commands and call them based on a given unique identifier.
		**/
		class CCommandContainer
		{
		public:
			CCommandContainer()
			{
				mCommands.push_back( std::make_unique<Command>("function1: ", NCommands::function1) );
				mCommands.push_back( std::make_unique<Command>("function2: ", NCommands::function2) );
				mCommands.push_back( std::make_unique<Command>("function3: ", NCommands::function3) );
			}
			void callFunction(const uint32_t id)
			{
				if (id < mCommands.size())
				{
					mCommands[id]->execute();
				}
			}
		private:
			std::vector<std::unique_ptr<Command>> mCommands;
		};
	} // NCommandPattern
} // NDesignPatterns