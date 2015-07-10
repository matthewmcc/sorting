#include <iostream>
#include <vector>

// Quicksort_inplace sort class implementing sorting
template <typename T> 
class Quicksort_inplace : public Sorting<T> {

public:
	Quicksort_inplace(std::vector<T>, int);
	void sort();

private:
	void quick(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quicksort_inplace<T>::Quicksort_inplace(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quicksort_inplace<T>::sort() {
	this->starttimer();
	std::cout << "Quicksort_inplace sort, average case: O(n*n)" << std::endl;

	quick(0, this->listsize - 1);

	this->stoptimer("Quicksort_inplace sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quicksort_inplace sort failed" << std::endl;
}

template <typename T>
void Quicksort_inplace<T>::quick(int f, int l) {
	int pivot = this->list[l], i = f, j = f;

	for (int x = f; x <= l; x++) {
		if (this->list[x] >= pivot) {
			std::swap(this->list[j], this->list[x]);
			j++;
		}
		else {
			std::swap(this->list[i], this->list[x]);
			i++;
			j++;
		}
	}

	if (l - f > 1 || this->list[f] > this->list[l])
		std::swap(this->list[i], this->list[l]);

	if (l - f > 1) {
		quick(f, i - 1);
		quick(i, l);
	}
}