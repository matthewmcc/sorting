#include <iostream>
#include <vector>

// Insertion sort class implementing sorting
template <typename T> 
class Insertion : public Sorting<T> {

public:
	Insertion(std::vector<T>, int);
	void sort();

private:
	void insertion(int, int);
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


	insertion(0, this->listsize - 1);

	this->stoptimer("Insertion sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Insertion sort failed" << std::endl;
}

// In place insertion sort
template <typename T>
void Insertion<T>::insertion(int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && this->list[divid] < this->list[divid - 1]) {
				std::swap(this->list[divid], this->list[divid - 1]);
				divid--;
		}
	}
}