#include <iostream>
#include <vector>

// Cocktail sort class implementing sorting
template <typename T> 
class Cocktail : public Sorting<T> {

public:
	Cocktail(std::vector<T>, int);
	void sort();

private:
	void cocktail();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Cocktail<T>::Cocktail(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Cocktail<T>::sort() {
	this->starttimer();
	std::cout << "Cocktail sort, average case: O(n*n)" << std::endl;

	cocktail();

	this->stoptimer("Cocktail sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Cocktail sort failed" << std::endl;
}

// Cocktail sort that implements Cocktail alternating from left to right.
template <typename T> 
void Cocktail<T>::cocktail() {
	bool swap = true;
	int left = 0, right = this->listsize - 1;

	while (swap) {
		swap = false;
		// Cocktail sort form the left
		for (int l = left; l < right; l++) {
			if (this->list[l] > this->list[l + 1]) {
				std::swap(this->list[l], this->list[l + 1]);
				swap = true;
			}
		}
		right--;

		if (!swap)
			return;
		swap = false;

		// Cocktail sort from the right
		for (int r = right; r > left; r--) {
			if (this->list[r] < this->list[r - 1]){
				std::swap(this->list[r], this->list[r - 1]);
				swap = true;
			}
		}
		left++;
	}
}
