#include <iostream>
#include <vector>

// Quicksort_med3 sort class implementing sorting
template <typename T> 
class Quicksort_med3 : public Sorting<T> {

public:
	Quicksort_med3(std::vector<T>, int);
	void sort();

private:
	std::vector<T> quick(std::vector<T>&, int);
	inline T med3(const std::vector<T>&, const int&);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Quicksort_med3<T>::Quicksort_med3(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Quicksort_med3<T>::sort() {
	this->starttimer();
	std::cout << "Quicksort median of 3, average case: O(n*n)" << std::endl;

	this->list = quick(this->list, this->listsize);

	this->stoptimer("Quicksort median of 3");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Quicksort median of 3 failed" << std::endl;
}


// Recursive quicksort function
template <typename T>
std::vector<T> Quicksort_med3<T>::quick(std::vector<T> &qlist, int qsize) {
	if (qsize < 2)
		return qlist;

	std::vector<T> low, high;

	int pivot = med3(qlist, qlist.size());

	for (int i = 0; i < qsize; i++) {
		if (qlist[i] < pivot)
			low.push_back(qlist[i]);
		else
			high.push_back(qlist[i]);
	}

	low = quick(low, low.size());
	high = quick(high, high.size());

	low.reserve(low.size() + high.size());

	for (int i = 0; i < high.size(); i++) {
		low.push_back(high[i]);
	}

	return low;
} 

// Selects 3 pivots and return the median
template <typename T>
inline T Quicksort_med3<T>::med3(const std::vector<T> &qlist, const int &qsize) {
	std::vector<T> pl;

	// If the list given is small a rand pivot will be returned
	if (qsize < 4)
		return qlist[rand() % qsize];

	for (int i = 0; i < 3; i++)
		pl.push_back(rand() % qsize);

	// Voodoo magic
	return std::max(std::min(qlist[pl[0]],qlist[pl[1]]), 
		std::min(std::max(qlist[pl[0]],qlist[pl[1]]),qlist[pl[2]]));
}