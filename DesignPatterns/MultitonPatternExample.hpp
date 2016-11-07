#pragma once
/******************************************************************************
* Copyright (C) 11/06/2016
*
* @file         MultitonPatternExample.hpp
* @author       Robert Badea
* @url		www.robertbadea.ro
******************************************************************************
*
* In software engineering, the multiton pattern is a design pattern similar to the singleton, which allows only one
* instance of a class to be created.
*
* The multiton pattern expands on the singleton concept to manage a map of named instances as key - value pairs.
* Most people and textbooks consider this a singleton pattern
*
* For example, multiton does not explicitly appear in the highly regarded object-oriented programming textbook Design Patterns
* (it appears as a more flexible approach named registry of singletons).
*
* Source: https://en.wikipedia.org/wiki/Multiton_pattern
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <memory>		// for C++11 ptr types
#include <map>			// for multiton map of singletons
#include <string>		// for multiton map keys

namespace NDesignPatterns
{
	namespace NMultitonPattern
	{
		//------------------------------------------------------------------------
		//					MULTITON IMPLEMENTATION - C++11
		//------------------------------------------------------------------------
		template <typename T, typename Key = std::string>
		class CMultiton
		{
		public:
			/**
			* The get function is a static that returns the instance if found in map, or creates one otherwise
			*
			* Note		This pattern is very similar to Flyweight, if the keys are limited to an enum, for example.
			*		Multiton does pooling where object creation is resource intensive.
			*		Flyweight pattern uses it to manage redundancy of the objects in the system.
			**/
			static std::weak_ptr<T*> get(const Key &key)
			{
				// check for an existent value..
				const auto it = instances.find(key);

				// return value if found..
				if (it != instances.end())
				{
					return std::weak_ptr<T*>(it->second);
				}

				// crate object if we reached this point
				std::shared_ptr<T*>instance = std::make_shared<T*>(new T);

				// the code from below will not throw any exceptions, it is safe to add in map
				instances[key] = instance;
				return std::weak_ptr<T*>(instance);
			}

		private:

			/**
			* Let's also disable the access to constructor, we don't need instances of this class 
			**/
			explicit CMultiton(void) = delete;

			/**
			* The static map for the multiton object which shall keep the pointers to our singletons.
			**/
			static std::map<Key, std::shared_ptr<T*>> instances;
		};

		template <typename T, typename Key>
		std::map<Key, std::shared_ptr<T*>> CMultiton<T, Key>::instances;
	} // NMultitonPattern
} // NDesignPatterns
