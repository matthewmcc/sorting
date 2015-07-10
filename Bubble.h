#include <iostream>
#include <vector>

// Bubble sort class implementing sorting
template <typename T> 
class Bubble : public Sorting<T> {

public:
	Bubble(std::vector<T>, int);
	void sort();

private:
	void bubble();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Bubble<T>::Bubble(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Bubble<T>::sort() {
	this->starttimer();
	std::cout << "Bubble sort, average case: O(n*n)" << std::endl;

	bubble();

	this->stoptimer("Bubble sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Bubble sort failed" << std::endl;
}

// Bubble sort function
template <typename T>
void Bubble<T>::bubble() {
	bool swap = true;
	int pass = 0;

	while(swap) {
		swap = false;
		pass++;

		for(int i = 0; i < this->listsize - pass; i++) {
			if (this->list[i] > this->list[i + 1]) {
				swap = true;
				std::swap(this->list[i], this->list[i + 1]);
			}
		}
	}
}