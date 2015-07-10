#include <iostream>
#include <vector>

// Oddeven sort class implementing sorting
template <typename T> 
class Oddeven : public Sorting<T> {

public:
	Oddeven(std::vector<T>, int);
	void sort();

private:
	void oddeven();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Oddeven<T>::Oddeven(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Oddeven<T>::sort() {
	this->starttimer();
	std::cout << "Oddeven sort, average case: O(n*n)" << std::endl;

	oddeven();

	this->stoptimer("Oddeven sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Oddeven sort failed" << std::endl;
}

// Oddeven sort function, a simple extension of bubble sort
template <typename T> 
void Oddeven<T>::oddeven() {
	bool swap = true;
	int odd = 0, even = 1;

	while (swap) {
		swap = false;
		// Oddeven sort form the left
		for (int o = odd; o < this->listsize; o += 2) {
			if (this->list[o] > this->list[o + 1]) {
				std::swap(this->list[o], this->list[o + 1]);
				swap = true;
			}
		}

		// Oddeven sort from the right
		for (int e = even; e < this->listsize; e += 2) {
			if (this->list[e] > this->list[e + 1]){
				std::swap(this->list[e], this->list[e + 1]);
				swap = true;
			}
		}
	}
}