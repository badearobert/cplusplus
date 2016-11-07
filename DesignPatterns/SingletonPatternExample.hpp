#pragma once
/******************************************************************************
* Copyright (C) 11/06/2016
*
* @file         SingletonPatternExample.hpp
* @author       Robert Badea
* @url		www.robertbadea.ro
******************************************************************************
* In software engineering, the singleton pattern is a design pattern that restricts the instantiation of a class to one object.
* This is useful when exactly one object is needed to coordinate actions across the system.
*
* Source: https://en.wikipedia.org/wiki/Singleton_pattern
* 
* Useful related links
* http://www.codeproject.com/Articles/4750/Singleton-Pattern-A-review-and-analysis-of-existin
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <memory>		// for C++11 unique_ptr

namespace NDesignPatterns
{
	namespace NSingletonPattern
	{
		/**
		* NOTE 		Singletons solve one(and only one) problem : Resource Contention
		*		A singleton should be used ONLY if you have some resource that
		*			(1) can only have a single instance, and
		*			(2) you need to manage that single instance
		*			
		*		Singleton is not a pattern to wrap globals.
		*		It is also considered an anti - pattern by some people, who feel that it is overly used, introducing 
		*		unnecessary limitations in situations where a sole instance of a class is not actually required.
		*
		*		A singleton can be implemented in multiple ways, but the ollowing general rules still applies
		*
		*		We need to have the following:
		*			(1) A static instance of that class, created internally
		*			(2) A static function that will return the static instance
		* 
		*			(3) Copy constructor / Assignment operator made private so the object cannot be cloned
		*			C++11 added move constructor / move assignment, so they also need to be made private (or deleted)
		**/
		//------------------------------------------------------------------------
		//			SINGLETON IMPLEMENTATION - 
		//------------------------------------------------------------------------
		class CSingleton
		{
		public:
			/**
			* NOTE		The function that returns our object will create the object at its first call.
			*
			*		An object that's static in a class is, for all intents and purposes, always constructed
			*		(and destructed), even if it's never used.
			*		In contrast, an object that's static in a function is created the first time through the function,
			*		so if the function is never called, the object is never created.
			*
			*		Static initialization is thread-safe in C++11. 
			*		Object initialization will be made only by one thread, other threads will wait till it complete.
			*			
			*		The following code is NOT thread-safe if used in a C++0x environment.
			**/
			inline static CSingleton& getInstance() {
				static CSingleton instance;
				return instance;
			}
		private:
			/**
			* The object should not be created from outside of the class
			**/
			CSingleton();

			/**
			* Disallow the following call: 
			* CSingleton& obj = CSingleton::getInstance();
			* CSingleton clone(obj);
			**/
			inline explicit CSingleton(CSingleton const&) { }

			/**
			* The following call will return the same memory address instead of copying the data to the other object
			* CSingleton& obj = CSingleton::getInstance();
			* CSingleton &clone = obj; => clone and obj points to the same memory
			**/
			inline CSingleton& operator=(CSingleton const&) { return *this; }

			/**
			* NOTE		C++11 added move constructor & operator, so we will need to delete them also for C++11 environment
			*
			*		delete can be used for any function, in which case it is explicitly marked as deleted and any 
			*		use results in a compiler error. For special member functions, this also means in particular that 
			*		they then aren't generated for you by the compiler.
			**/
			inline explicit CSingleton(const CSingleton &&)		= delete; // Move constructor - C++11 
			CSingleton& operator=(CSingleton&&)					= delete; // Asssignment operator - C++11
		};
	} // NSingletonPattern
} // NDesignPatterns
