#include <iostream>
#include <vector>

// Insertion sort class implementing sorting
template <typename T> 
class Insertion : public Sorting<T> {

public:
	Insertion(std::vector<T>, int);
	void sort();

private:
	void insertion();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Insertion<T>::Insertion(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Insertion<T>::sort() {
	this->starttimer();
	std::cout << "Insertion sort, average case: O(n*n)" << std::endl;

	insertion();

	this->stoptimer("Insertion sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Insertion sort failed" << std::endl;
}

template <typename T>
void Insertion<T>::insertion() {
	std::vector<int> sortedlist;
	int temp;

	// Removes items from unsorted this->list untill its empty
	while (!this->list.empty()) {
		temp = this->list.back();
		this->list.pop_back();

		// Finds the correct place in the sorted this->list to add next element
		for (int i = 0; true; i++) {
			if (i >= sortedlist.size() || temp < sortedlist[i]) {
				sortedlist.insert(sortedlist.begin() + i, temp);
				break;
			}
		}
	}

	this->list = sortedlist;
}