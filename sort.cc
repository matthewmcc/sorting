#include <iostream>
#include <cmath>

#include "Sorting.h"
#include "Bubble.h"
#include "Cocktail.h"
#include "Oddeven.h"
#include "Comb.h"
#include "Selection.h"
#include "Insertion.h"
#include "Mergesort.h"
#include "Mergesort_inplace.h"
#include "Quicksort.h"
#include "Quicksort_inplace.h"
#include "Quicksort_med3.h"
#include "Quicksort_med3_inplace.h"
#include "Shell.h"
#include "BST.h"
#include "Radix.h"
#include "Heap.h"
#include "Ternaryheap.h"
#include "Introsort.h"
#include "IntroM3.h"
#include "Quickcomb.h"
#include "Quickinsert.h"

#include "Csort.h"

// Default list size
int listsize = std::pow(10, 5);

int main(int argc, char* argv[]) {

	// If theres a commandline input number it'll be come the list size
	if(argc == 2) {
		listsize = atoi(argv[1]);
		std::cout << "List size: " << listsize << std::endl;
	}

	std::vector<int> list;
	std::srand(time(NULL));

	// Creates a random list of size listsize
	for (int i = 0; i < listsize; i++) {
		list.push_back(rand());
	}

	// Introsort implementing a quicksort to a heap or insertion sort.
	Introsort<int> it(list, listsize);
	it.sort();

	// Quickcomb implementing a quicksort to comb sort
	Quickcomb<int> qc(list, listsize);
	qc.sort();

	// Introsort median of 3 implementing a quicksort to heap
	IntroM3<int> ij(list, listsize);
	ij.sort();

	// C++ STL sort algorithm for comparision
	Csort<int> cs(list, listsize);
	cs.sort();

	// Runs an in place quick sort on the random list 
	Quicksort_inplace<int> quickip(list, listsize);
	quickip.sort();

	// Runs an in place median of 3 quick sort on the random list 
	Quicksort_med3_inplace<int> qsmp(list,listsize);
	qsmp.sort();

	// Runs shell sort on the random list
	Shell<int> shell(list, listsize);
	shell.sort();

	// Runs heap sort on the random list
	Heap<int> h(list, list.size());
	h.sort();

	Ternaryheap<int> th(list, listsize);
	th.sort(); 

	// Runs comb sort on the random list
	Comb<int> cb(list, listsize);
	cb.sort();

	// Quickinsert implementing a quicksort to insertion sort
	Quickinsert<int> qi(list, listsize);
	qi.sort();

	// Runs a heap sort on the random list
	BST<int> bst(list, listsize);
	bst.sort();

	// Runs a simple merge on the random list
	Mergesort<int> merge(list, listsize);
	merge.sort();

	// Runs a simple quicksort on the random list
	Quicksort<int> quick(list, listsize);
	quick.sort();

	// Runs a median of 3 quick sort on the random list 
	Quicksort_med3<int> quickmed(list, listsize);
	quickmed.sort();

	// Runs an in place radix sort on the random list 
	Radix<int> rad(list, listsize);
	rad.sort();

	// Runs merge sort in place on a random linked list
	Mergesort_inplace<int> mergeip(list, listsize);
	mergeip.sort();

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