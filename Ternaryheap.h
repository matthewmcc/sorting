#include <iostream>
#include <vector>

// Ternary heap sort class implementing sorting
template <typename T> 
class Ternaryheap : public Sorting<T> {

public:
	Ternaryheap(std::vector<T>, int);
	void sort();

private:
	void ternaryheap();
	inline void siftdown(int, const int&);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Ternaryheap<T>::Ternaryheap(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Ternaryheap<T>::sort() {
	this->starttimer();
	std::cout << "Ternary heap sort, average case: O(n log n)" << std::endl;

	ternaryheap();

	this->stoptimer("Ternary heap sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Ternary heap sort failed" << std::endl;
}

template <typename T>
void Ternaryheap<T>::ternaryheap() {
	// Heapify only called once so is inline here
	for (int i = (this->listsize - 1) / 3; i >= 0; i--) {
		siftdown(i, this->listsize - 1);
	}

	// Removes the root of the heap placing it at the end and decrements the...
	// ...heap size untill list is ordered.
	for (int end = this->listsize - 1; end > 0; end--) {
		std::swap(this->list[end], this->list[0]);
		siftdown(0, end - 1);
	}
}

template <typename T>
inline void Ternaryheap<T>::siftdown(int root, const int &end) {

	int largest, rchild, mchild, lchild = root * 3 + 1;

	while (lchild <= end) {
		mchild = lchild + 1;
		rchild = lchild + 2;

		// Check last is within bounds to reduce comparisons
		if (rchild <= end) {
			// Finds the largest of the 3 children
			largest = this->list[lchild] > this->list[root] ?
				lchild : root;

			if (this->list[rchild] > this->list[largest])
				largest = rchild;

			if (this->list[mchild] > this->list[largest])
				largest = mchild;
		}
		else {
			// Finds the largest of the 3 children
			largest = lchild <= end && this->list[lchild] > this->list[root] ?
				lchild : root;

			if (mchild <= end && this->list[mchild] > this->list[largest])
				largest = mchild;
		}

		// If the largest of the children is greater than its parent, swap the...
		// ...and continue
		if (this->list[largest] > this->list[root]) {
			std::swap(this->list[root], this->list[largest]);
			lchild = largest * 3 + 1;
			root = largest;
		}
		else return;
	}
}