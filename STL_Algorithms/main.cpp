/******************************************************************************
* Copyright (C) 05/03/2017
*
* @file         main.cpp
* @project		STL_Algorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "Setters.hpp"
#include "Removers.hpp"
#include "Replacers.hpp"
#include "MathAlgorithms.hpp"
#include "SearchingAndSorting.hpp"

int main()
{
	using namespace NSTL_Algorithms;

	NSetters::callFunctions();
	NRemovers::callFunctions();
	NReplacers::callFunctions();
	NMathAlgorithms::callFunctions();
	NSearchingAndSorting::callFunctions();

	Pause();
	return 0;
}