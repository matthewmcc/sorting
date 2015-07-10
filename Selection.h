#include <iostream>
#include <vector>

// Selection sort class implementing sorting
template <typename T> 
class Selection : public Sorting<T> {

public:
	Selection(std::vector<T>, int);
	void sort();

private:
	void select();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Selection<T>::Selection(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Selection<T>::sort() {
	this->starttimer();
	std::cout << "Selection sort, average case: O(n*n)" << std::endl;

	select();

	this->stoptimer("Selection sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Selection sort failed" << std::endl;
}

// Selection algorithm
template <typename T> 
void Selection<T>::select() {
	int nextindex = 0;

	// Loop to add next smallest to the next position of the this->list
	for (int pass = 0; pass < this->listsize - 1; pass++) {
		nextindex = pass;

		// Loop to find the next smallest
		for (int i = pass; i < this->listsize; i++)  {
			if (this->list[i] < this->list[nextindex]) {
				nextindex = i;
			}
		}

		// Moving the next smallest to the correct index
		std::swap(this->list[pass], this->list[nextindex]);
	}
}