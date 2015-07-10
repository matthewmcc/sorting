#include <iostream>
#include <vector>

// Csort class implementing sorting
template <typename T> 
class Csort : public Sorting<T> {

public:
	Csort(std::vector<T>, int);
	void sort();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Csort<T>::Csort(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Csort<T>::sort() {
	this->starttimer();
	std::cout << "Csort, average case: O(n log n)" << std::endl;

	std::sort(this->list.begin(), this->list.end());

	this->stoptimer("Csort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Csort failed" << std::endl;
}