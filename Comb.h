#include <iostream>
#include <vector>

// Comb sort class implementing sorting
template <typename T> 
class Comb : public Sorting<T> {

	const float SHRINK_FACTOR = 1.3;

public:
	Comb(std::vector<T>, int);
	void sort();

private:
	void comb();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Comb<T>::Comb(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Comb<T>::sort() {
	this->starttimer();
	std::cout << "Comb sort, average case: O(n * n / pow(2, P))" <<
		" where P is the # of increments" << std::endl;

	comb();

	this->stoptimer("Comb sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Comb sort failed" << std::endl;
}

// Comb sort function, a efficient derivation of bubble sort
template <typename T>
void Comb<T>::comb() {
	bool swap = true;
	int gap = this->listsize / SHRINK_FACTOR;

	while(swap || gap != 1) {
		swap = false;

		for(int i = 0; i + gap < this->listsize; i++) {
			if (this->list[i] > this->list[i + gap]) {
				swap = true;
				std::swap(this->list[i], this->list[i + gap]);
			}
		}

		// Srinks gap untill it equals 1
		if (gap != 1)
			gap /= SHRINK_FACTOR;
	}
}