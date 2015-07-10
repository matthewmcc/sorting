#include <iostream>
#include <cmath>

#include "Sorting.h"
#include "Bubble.h"
#include "Cocktail.h"
#include "Oddeven.h"
#include "Comb.h"
#include "Insertionsort.h"
#include "Selection.h"
#include "Mergesort.h"
#include "Mergesort_inplace.h"
#include "Quicksort.h"
#include "Quicksort_inplace.h"
#include "Quicksort_med3.h"
#include "Shell.h"
#include "BST.h"
#include "Radix.h"

#include "Csort.h"

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

	// C++ STL sort algorithm for comparision
	Csort<int> cs(list, listsize);
	cs.sort();

	// Runs an in place quick sort on the random list 
	Quicksort_inplace<int> quickip(list, listsize);
	quickip.sort();

	// Runs shelll sort on the random list
	Shell<int> shell(list, listsize);
	shell.sort();

	// Runs merge sort in place on a random linked list
	Mergesort_inplace<int> mergeip(list, listsize);
	mergeip.sort();

	// Runs comb sort on the random list
	Comb<int> cb(list, listsize);
	cb.sort();

	// Runs a heap sort on the random list
	BST<int> bst(list, listsize);
	bst.sort();

	// Runs a simple merge on the random list
	Mergesort<int> merge(list, listsize);
	merge.sort();

	// Runs an in place radix sort on the random list 
	Radix<int> rad(list, listsize);
	rad.sort();

	// Runs a simple quicksort on the random list
	Quicksort<int> quick(list, listsize);
	quick.sort();

	// Runs a median of 3 quick sort on the random list 
	Quicksort_med3<int> quickmed(list, listsize);
	quickmed.sort();

	// Runs insertion sort on the random list 
	Insertion<int> insertion(list, listsize);
	insertion.sort();

	// Runs Selection sort on the random list 
	Selection<int> select(list, listsize);
	select.sort();

	// Runs an odd even sort on the random list
	Oddeven<int> od(list, listsize);
	od.sort();

	// Runs cocktail sort on the random list
	Cocktail<int> ct(list, listsize);
	ct.sort();

	// Runs a bubble sort on the random list 
	Bubble<int> bub(list, listsize);
	bub.sort();
}