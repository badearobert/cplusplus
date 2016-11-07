#pragma once
/******************************************************************************
* Copyright (C) 23/10/2016
*
* @file         OperatorOverloadingExample.hpp
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* Operators overloading
*
* You can redefine or overload most of the built-in operators available in C++. 
*
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <inttypes.h>

namespace NUtility
{
	namespace NOperatorOverloading
	{
		//------------------------------------------------------------------------
		//			Base Class so we can have the data we want
		//------------------------------------------------------------------------
		class CBase
		{
		protected:
			uint32_t counter;

		public:
			/**
			* We define a constructor that receives an integer to init our counter member value
			**/
			CBase(uint32_t startCounter) : counter(startCounter) { }
		};

		class CCopyableExample : public CBase
		{
			//------------------------------------------------------------------------
			//					Assignment Operator (=)
			//------------------------------------------------------------------------
			/**
			* Note		We have const on the parameter object, the reason is that we are not allowed to modify it!
			*				
			*			In order to support operator chaining (a = b = c), the assignment operator must return some value. 
			*			The value that should be returned is a reference to the left-hand side of the assignment.
			*
			*			Always check for self-assignment!
			*
			* Signature
			*			MyClass & operator=(const MyClass &rhs)
			*
			*			The operator returns a non - const reference to this
			*/
			CCopyableExample & operator=(const CCopyableExample &rhs)
			{
				// check for self-assignment
				if (&rhs == this) 
					return *this;

				// we copy the data - in our case, only the counter
				this->counter = rhs.counter;

				// for dynamically allocated memory, we need to deallocate our memory,
				// allocate enough for rhs, and copy the data afterwards

				// we return pointer to this object
				return *this;
			}

			//------------------------------------------------------------------------
			//					Compound Assignment Operators += -= *=
			//------------------------------------------------------------------------
			/**
			* Note		These are destructive operators, because they update or replace the values 
			*			on the left-hand side of the assignment. 
			*
			*			We must have in mind that we might not want to do self-increment value for our class
			*			eg. MyClass example; example += example;
			*			For that we can check for equal instances
			*
			* Signatures 
			*			MyClass & MyClass::operator +=(const MyClass &rhs) 
			*			MyClass & MyClass::operator -=(const MyClass &rhs)
			*			MyClass & MyClass::operator *=(const MyClass &rhs)
			*
			*			The operator returns a non-const reference to this
			**/
			CCopyableExample & CCopyableExample::operator+=(const CCopyableExample &rhs) 
			{
				//can be skipped if we don't want this
				if (&rhs == this)
					return *this;

				// copy the data
				this->counter += rhs.counter;

				// return our object
				return *this;
			}
			//------------------------------------------------------------------------
			//					Binary Arithmetic Operators + - *
			//------------------------------------------------------------------------
			/**
			* Note		They don't modify either operand - they return a new value created from the two arguments.
			*			For skipping extra work we can define them by using our compound assignment operators (if defined)
			*
			* Signatures
			*			const MyClass MyClass::operator+(const MyClass &other) const 
			*			const MyClass MyClass::operator-(const MyClass &other) const
			*			const MyClass MyClass::operator*(const MyClass &other) const
			*
			*			The operator returns a new object.
			**/
			const CCopyableExample CCopyableExample::operator+(const CCopyableExample &other) const
			{
				CCopyableExample result(*this);
				result += other;
				return result;

				// or return CCopyableExample(*this) += other;
			}
			//------------------------------------------------------------------------
			//					Comparison and Relational Operators  
			//------------------------------------------------------------------------
			/**
			* Note		We return true if the objects are equal, based on our calculations in the overloaded operators
			*			!= can and should be written in terms of the == operator
			*			If you need one of the operators overloaded - overload both of them.
			*
			*
			* Signatures
			*			bool MyClass::operator == (const MyClass &other) const 
			*			bool MyClass::operator != (const MyClass &other) const
			*
			*			bool MyClass::operator  < (const MyClass& other) const
			*			bool MyClass::operator <= (const MyClass& other) const
			*			bool MyClass::operator >= (const MyClass& other) const
			*			bool MyClass::operator  > (const MyClass& other) const

			**/
			bool CCopyableExample::operator==(const CCopyableExample &other) const 
			{
				return (this->counter == other.counter);
			}
			bool CCopyableExample::operator!=(const CCopyableExample &other) const
			{
				return !(*this == other);
			}
			//------------------------------------------------------------------------
			//					Input Output operators
			//------------------------------------------------------------------------
			/**
			* Note		It is important to make operator overloading function a friend of the class because 
			*			it would be called without creating an object.
			*
			* Signatures
			*			friend ostream &operator<<(ostream &output, const MyClass &other)
			*			friend istream &operator>>(istream &input, MyClass &other)
			*
			*			Notice that the istream obj is not const because we need to change the data inside
			*			We use friend to have access to the private members inside.
			**/
			friend std::ostream &operator << (std::ostream &output, const CCopyableExample &obj)
			{
				output << obj.counter;
				return output;
			}

			friend std::istream &operator >> (std::istream  &input, CCopyableExample &obj)
			{
				input >> obj.counter;
				return input;
			}
			//------------------------------------------------------------------------
			//					Function call operator ()
			//------------------------------------------------------------------------
			/**
			* Note		This example can be seen in my NContainersHelpers.hpp post / file
			*			Github link: https://github.com/badearobert/cplusplus/
			*			Blog post:   http://badearobert.ro/blog/2016/10/06/initmap-initvector-util-classes/
			*
			* Signatures
			*			CCopyableExample& operator()(...)	
			*			CCopyableExample  operator()(...)
			*		
			*			Can be used with or without ref, depending on our implementation:
			*
			*			1) 
			*			We can create a new object inside the function, do something with the data received, and return
			*			This can be done only with copy by value because the object was created locally.
			*
			*			2)
			*			We can update the *this based on the data received, and return it as a reference
			**/
			// overload function call
			CCopyableExample& operator()(uint32_t value1, uint32_t value2)
			{
				counter = (value1 * value2);
				return *this;
			}
			//------------------------------------------------------------------------
			//					Subscripting operator []
			//------------------------------------------------------------------------
			/**
			* Note		
			*
			* Signatures
			**/
			
		};

		

	} // NOperatorOverloading
} // NUtility