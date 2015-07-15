#include <iostream>
#include <vector>

// Quicksort_med3_inplace sort class implementing sorting
template <typename T> 
class Quicksort_med3_inplace : public Sorting<T> {

	// Required size of the sort list use median of 3 pivot selection
	const int MED_COMP_LISTSIZE = 50;

public:
	Quicksort_med3_inplace(std::vector<T>, int);
	void sort();

private:
	void quick(int, int);
	inline void med3(int&, int&, int&);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quicksort_med3_inplace<T>::Quicksort_med3_inplace(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quicksort_med3_inplace<T>::sort() {
	this->starttimer();
	std::cout << "Quicksort median of 3 in place, average case: O(n*n)" << std::endl;

	quick(0, this->listsize - 1);

	this->stoptimer("Quicksort median of 3 in place");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quicksort median of 3 in place failed" << std::endl;
}

template <typename T>
void Quicksort_med3_inplace<T>::quick(int f, int l) {
	// If the list is large enough a median of 3 pivot is selected
	if (l - f > MED_COMP_LISTSIZE)
		med3(this->list[l - 2], this->list[l - 1], this->list[l]);

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

	if (f < l) {
		quick(f, i - 1);
		quick(i + 1, l);
	}

}

// Selects 3 pivots and return the median
template <typename T>
inline void Quicksort_med3_inplace<T>::med3(int &l, int &m, int &r) {
	// Index of the median selection
	if (l < m) {
		if (m < r)
			std::swap(r, m);
		else { 
			if (l < r)
				return;
			else 
				std::swap(r, l);
		}
	} 
	else {
		if (r < m)
			std::swap(r, m);
		else { 
			if (r > l)
				std::swap(r, l);
			else 
				return;
		}
	}
}