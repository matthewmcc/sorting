#include <iostream>
#include <cmath>

#include "Sorting.h"
#include "Bubble.h"
#include "Insertionsort.h"
#include "Mergesort.h"
#include "Mergesort_inplace.h"
#include "Quicksort.h"
#include "Quicksort_inplace.h"
#include "Quicksort_med3.h"

int listsize = std::pow(10, 5);

int main(int argc, char* argv[]) {

	if(argc == 2) {
		listsize = atoi(argv[1]);
		std::cout << "List size: " << listsize << std::endl;
	}

	std::vector<int> list;
	std::srand(time(NULL));

	for (int i = 0; i < listsize; i++) {
		list.push_back(rand());
	}

	// Runs insertion sort on the random list 
	Insertionsort insertion(list, listsize);
	insertion.sort();

	// Runs an in place quick sort on the random list 
	Quicksort_inplace quickip(list, listsize);
	quickip.sort();

	// Runs merge cort in place on a random linked list
	Mergesort_inplace mergeip(list, listsize);
	mergeip.sort();

	// Runs a simple quicksort on the random list
	Quicksort quick(list, listsize);
	quick.sort();

	// Runs a median of 3 quick sort on the random list 
	Quicksort_med3 quickmed(list, listsize);
	quickmed.sort();

	// Runs a simple merge on the random list
	Mergesort merge(list, listsize);
	merge.sort();

	// Runs a bubble sort on the random list 
	Bubble bubble(list, listsize);
	bubble.sort();
}