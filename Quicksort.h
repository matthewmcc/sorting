#include <iostream>
#include <vector>

// Quicksort sort class implementing sorting
template <typename T> 
class Quicksort : public Sorting<T> {

public:
	Quicksort(std::vector<T>, int);
	void sort();

private:
	std::vector<int> quick(std::vector<int>&, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quicksort<T>::Quicksort(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quicksort<T>::sort() {
	this->starttimer();
	std::cout << "Quicksort, average case: O(n log n)" << std::endl;

	this->list = quick(this->list, this->listsize);

	this->stoptimer("Quicksort sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quicksort sort failed" << std::endl;
}

// Recursive quicksort function
template <typename T>
std::vector<int> Quicksort<T>::quick(std::vector<int> &qlist, int qsize) {
	if (qsize < 2)
		return qlist;

	std::vector<int> low, high;

	int pivot = qlist[rand() % qsize];

	for (int i = 0; i < qsize; i++) {
		if (qlist[i] < pivot)
			low.push_back(qlist[i]);
		else
			high.push_back(qlist[i]);
	}

	low = quick(low, low.size());
	high = quick(high, high.size());

	low.reserve(low.size() + high.size());

	for (int i = 0; i < high.size(); i++) {
		low.push_back(high[i]);
	}

	return low;
} 