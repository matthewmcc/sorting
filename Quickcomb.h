#include <iostream>
#include <vector>

// Quickcomb sort class implementing sorting
template <typename T> 
class Quickcomb : public Sorting<T> {

	int COMB_SIZE = 15;
	double SHRINK_FACTOR = 1.3;

public:
	Quickcomb(std::vector<T>, int);
	void sort();

private:
	void quick(int, int);
	void comb(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quickcomb<T>::Quickcomb(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quickcomb<T>::sort() {
	this->starttimer();
	std::cout << "Quickcomb sort, average case: O(n*n)" << std::endl;

	quick(0, this->listsize - 1);

	this->stoptimer("Quickcomb sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quickcomb sort failed" << std::endl;
}

template <typename T>
void Quickcomb<T>::quick(int f, int l) {
 	int pivot = this->list[l], i = f;

	for (int x = f; x < l; x++) {
		if (this->list[x] < pivot) {
			std::swap(this->list[i], this->list[x]);
			i++;
		}
	}

	if (i > l)
		i = l;
	else std::swap(this->list[i], this->list[l]);

	int high = i - f - 1, low = l - i + 1;

	// Selecting which sorting algorithm to use by list size
	if (low < COMB_SIZE)
		comb(f, i - 1);
	else quick(f, i - 1);

	if (high < COMB_SIZE)
		comb(i + 1, l);
	else quick(i + 1, l);
}

// Comb sort function, a efficient derivation of bubble sort
template <typename T>
void Quickcomb<T>::comb(int left, int right) {
	bool swap = true;
	int gap = right - left;

	if (left >= right) return;

	while(swap || gap > 1) {
		// Srinks gap untill it equals 1
		if (gap > 1)
			gap /= SHRINK_FACTOR;

		swap = false;

		for(int i = left; i + gap <= right; i++) {
			if (this->list[i] > this->list[i + gap]) {
				swap = true;
				std::swap(this->list[i], this->list[i + gap]);
			}
		}
	}
}
