/******************************************************************************
* Copyright (C) 12/26/2016
*
* @file         main.cpp
* @project		SortingAlgorithms
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "Utils.h"

#include "BubbleSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"

#include <iostream>

int main()
{
	using namespace NSortingAlgorithms;

	auto mediumSizedArray = generateRandom(CAPACITY_MEDIUM);
	display(mediumSizedArray);

	NSortingAlgorithms::NBubbleSort::sort(mediumSizedArray);
	display(mediumSizedArray);
	system("pause");
	return 0;
}