#include <iostream>
#include <vector>

// Heap sort class implementing sorting
template <typename T> 
class Heap : public Sorting<T> {

public:
	Heap(std::vector<T>, int);
	void sort();

private:
	void heap();
	inline void siftdown(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Heap<T>::Heap(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T>
void Heap<T>::sort() {
	this->starttimer();
	std::cout << "Heap sort, average case: O(n log n)" << std::endl;

	heap();

	this->stoptimer("Heap sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Heap sort failed" << std::endl;
}

template <typename T>
void Heap<T>::heap() {

	int heapsize = this->listsize - 1;

	// Heapify only called once so its inline here
	for (int i = (heapsize - 1) / 2; i >= 0; i--) {
		siftdown(i, heapsize);
	}

	// Removes the root of the heap placing it at the end and decrements the...
	// ...heap size untill list is ordered
	for (int end = heapsize; end > 0; end--) {
		std::swap(this->list[end], this->list[0]);
		siftdown(0, end - 1);
	}
}

template <typename T>
inline void Heap<T>::siftdown(int start, int end) {
	// Calculate root and first child
	int root = start, child = start * 2 + 1;

	while (child <= end) {
		// Finds the largest of the 2 chiildren
		if (child + 1 <= end && this->list[child] < this->list[child + 1]) {
			child++;
		}

		// Calculates if a swap need to occur
		if (this->list[root] < this->list[child]) {
			std::swap(this->list[root], this->list[child]);
			root = child;

			// Calculate next child
			child = root * 2 + 1;
		}
		else return;
	}
}