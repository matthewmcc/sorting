#include <iostream>
#include <vector>

// Insertion_inplace sort class implementing sorting
template <typename T> 
class Insertion_inplace : public Sorting<T> {

public:
	Insertion_inplace(std::vector<T>, int);
	void sort();

private:
	void insertion_inplace(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Insertion_inplace<T>::Insertion_inplace(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Insertion_inplace<T>::sort() {
	this->starttimer();
	std::cout << "Insertion_inplace sort, average case: O(n*n)" << std::endl;


	insertion_inplace(0, this->listsize - 1);

	this->stoptimer("Insertion_inplace sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Insertion_inplace sort failed" << std::endl;
}

template <typename T>
void Insertion_inplace<T>::insertion_inplace(int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && this->list[divid] < this->list[divid - 1]) {
				std::swap(this->list[divid], this->list[divid - 1]);
				divid--;
		}
	}
}