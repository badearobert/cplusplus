#pragma once
/******************************************************************************
* Copyright (C) 14/03/2017
*
* @file         MediatorPatternExample.hpp
* @project		DesignPatterns_Mediator
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* Usually a program is made up of a large number of classes. 
* Logic and computation is distributed among these classes. 
* However, as more classes are added to a program, especially during maintenance and/or 
* refactoring, the problem of communication between these classes may  become more complex. 
* This makes the program harder to read and maintain. 
* Furthermore, it can become difficult to change the program, since any change may affect 
* code in several other classes.
* 
* With the mediator pattern, communication between objects is encapsulated within a mediator object. 
* Objects no longer communicate directly with each other, but instead communicate through the mediator.
* This reduces the dependencies between communicating objects, thereby reducing coupling.
*
* Source: https://en.wikipedia.org/wiki/Mediator_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

namespace NDesignPatterns
{
	namespace NMediatorPattern
	{
		enum Addresses : uint32_t 
		{
			ADDRESS_BROADCAST = 0,
			ADDRESS_JOHN,
			ADDRESS_MICHAEL,
			ADDRESS_ROBERT,
			ADDRESS_DIANA,
		};

		class ISource;

		class IMessagingInterface {
		public:
			void addSource(std::shared_ptr<ISource> &src)
			{
				mSources.emplace_back(src);
			}
			virtual void OnMessageReceived(ISource* const sender, uint32_t receiver, std::string message) = 0;		
			
		protected:
			std::vector<std::shared_ptr<ISource>> mSources;
		};


		class ISource 
		{
		public:
			ISource(IMessagingInterface& _mediator, const uint32_t id)
				: mediator(_mediator)
				, mID(id)
			{
			}

			void sendMessage(uint32_t receiver, std::string message)
			{
				mediator.OnMessageReceived(this, receiver, message);
			}

			void getMessage(uint32_t sender, std::string message)
			{
				std::cout << sender << " -> " << mID << " : " << message << std::endl;
			}

			const uint32_t getID() const { return mID; }

		private:
			IMessagingInterface& mediator;

			uint32_t mID;
		};

		class CMediatorImpl : public IMessagingInterface
		{
		public:
			virtual void OnMessageReceived(
				ISource* const sender, uint32_t receiver, std::string message) override
			{
				auto source = std::find_if(
					mSources.begin(),
					mSources.end(),
					[sender](const auto& curr) { return (sender->getID() == curr->getID()); }
				);

				if (mSources.end() != source)
				{
					if (ADDRESS_BROADCAST == receiver)
					{
						const auto SENDER_ADDR = (*source)->getID();
						// broadcast message
						for (const auto& curr : mSources)
						{
							if (*source != curr)
							{
								curr->getMessage(SENDER_ADDR, message);
							}
						}
					}
					else
					{
						// private message
						auto destination = std::find_if(
							mSources.begin(), mSources.end(),
							[receiver](const auto& curr) { return (receiver == curr->getID()); }
						);

						if (mSources.end() != destination)
						{
							(*source)->getMessage((*destination)->getID(), message);
						}
					}
				}
			}
		};
	} // NMediatorPattern
} // NDesignPatterns
