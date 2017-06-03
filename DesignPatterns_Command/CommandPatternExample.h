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
		*  Command interface
		**/
		class ICommand 
		{
		public:
			virtual void execute() = 0;
		};
		/**
		* Data for a specific command
		**/
		class CCommand_1 : public ICommand
		{
			virtual void execute() override { std::cout << "CCommand_1 execute" << std::endl; }
		};

		class CCommand_2 : public ICommand
		{
			virtual void execute() override { std::cout << "CCommand_2 execute" << std::endl; }
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
				mCommands.push_back(std::unique_ptr<ICommand>(new CCommand_1));
				mCommands.push_back(std::unique_ptr<ICommand>(new CCommand_2));
			}
			~CCommandContainer()
			{
			}
			void callFunction(const uint32_t id)
			{
				if (id < mCommands.size())
				{
					mCommands[id]->execute();
				}
			}
		private:
			std::vector<std::unique_ptr<ICommand>> mCommands;
		};
	} // NCommandPattern
} // NDesignPatterns