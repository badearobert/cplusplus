#pragma once
/******************************************************************************
* Copyright (C) 30/04/2017
*
* @file         NonCopyable.h
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* Template for creating non copyable classes
* 
* Usage:
* 
* class Example1 : NUtility::NonCopyable {};
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
namespace NUtility
{
	template <class T>
	class NonCopyable_T
	{
	protected:
		NonCopyable_T() {}
		~NonCopyable_T() {} /// Protected non-virtual destructor
	private:
		NonCopyable_T(const NonCopyable_T &) = delete;
		NonCopyable_T & operator = (const NonCopyable &) = delete;
	};
	class NonCopyable : private NonCopyable_T <NonCopyable> {};
}

