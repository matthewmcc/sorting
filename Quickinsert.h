#include <iostream>
#include <vector>

// Quickinsert sort class implementing sorting
template <typename T> 
class Quickinsert : public Sorting<T> {

	int INSERT_SIZE = 15;

public:
	Quickinsert(std::vector<T>, int);
	void sort();

private:
	void quick(int, int);
	void insertion(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quickinsert<T>::Quickinsert(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quickinsert<T>::sort() {
	this->starttimer();
	std::cout << "Quickinsert sort, average case: O(n*n)" << std::endl;

	quick(0, this->listsize - 1);

	this->stoptimer("Quickinsert sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quickinsert sort failed" << std::endl;
}

template <typename T>
void Quickinsert<T>::quick(int f, int l) {
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
	if (low < INSERT_SIZE)
		insertion(f, i - 1);
	else quick(f, i - 1);

	if (high < INSERT_SIZE)
		insertion(i + 1, l);
	else quick(i + 1, l);
}

// In place insertion sort
template <typename T>
inline void Quickinsert<T>::insertion(int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && this->list[divid] < this->list[divid - 1]) {
				std::swap(this->list[divid], this->list[divid - 1]);
				divid--;
		}
	}
}