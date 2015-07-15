#include <iostream>
#include <vector>

// IntroM3 sort class implementing sorting
template <typename T> 
class IntroM3 : public Sorting<T> {

	// Required size of the sort list use median of 3 pivot selection
	int HEAPSORT_SIZE;

public:
	IntroM3(std::vector<T>, int);
	void sort();

private:
	void quick(int, int);
	inline void med3(int&, int&, int&);
	inline void heap(int, int);
	inline void siftdown(int, int);
	inline void siftdown(int, int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
IntroM3<T>::IntroM3(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void IntroM3<T>::sort() {
	this->starttimer();
	std::cout << "IntroM3, average case: O(n*n)" << std::endl;

	HEAPSORT_SIZE = log2(this->listsize) * 2;
	quick(0, this->listsize - 1);

	this->stoptimer("IntroM3");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "IntroM3 failed" << std::endl;
}

template <typename T>
void IntroM3<T>::quick(int f, int last) {
	// Finds median of 3 pivot
	med3(this->list[last - 2], this->list[last - 1], this->list[last]);

 	int pivot = this->list[last], mid = f;

	for (int x = f; x < last; x++) {
		if (this->list[x] < pivot) {
			std::swap(this->list[mid], this->list[x]);
			mid++;
		}
	}

	if (mid > last)
		mid = last;
	else std::swap(this->list[mid], this->list[last]);


	// Selecting which sorting algorithm to use by list size
	if ((mid - f) < HEAPSORT_SIZE) {
		if (f < mid - 1)
			heap(f, mid - 1);
	}
	else quick(f, mid - 1);

	if (last - (mid) < HEAPSORT_SIZE) {
		if (mid + 1 < last)
			heap(mid + 1, last);
	}
	else quick(mid + 1, last);
}

// Selects the median of the 3 pivots and places it at the end of the list
template <typename T>
inline void IntroM3<T>::med3(int &l, int &m, int &r) {
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

template <typename T>
inline void IntroM3<T>::heap(int start, int end) {

	for (int i = (((end - start) - 1) / 2) + start; i >= start; i--) {
		// siftdown(i, end - 1);
		siftdown(i, end, start);
	}

	// Removes the root of the heap placing it at the end and decrements the...
	// ...heap size untill list is ordered
	for (int i = end; i > start; i--) {
		std::swap(this->list[i], this->list[start]);
		siftdown(start, i - 1, start);
	}
}

template <typename T>
inline void IntroM3<T>::siftdown(int start, int end, int offset) {
	// Calculate root and first child
	int root = start, child = ((start - offset) * 2 + 1) + offset;/* child = start + 1;*/

	while (child <= end) {
		// Finds the largest of the 2 chiildren
		if (child + 1 <= end && this->list[child] < this->list[child + 1])
			child++;

		// Calculates if a swap need to occur
		if (this->list[root] < this->list[child]) {
			std::swap(this->list[root], this->list[child]);
			root = child;

			// Calculate next child
			child = ((root - offset) * 2 + 1) + offset;
		}
		else return;
	}
}

template <typename T>
inline void IntroM3<T>::siftdown(int start, int end) {
	// Calculate root and first child
	int root = start, /*child = start * 2 + 1*/ child = start + 1;

	while (child <= end) {
		// Finds the largest of the 2 chiildren
		if (child + 1 <= end && this->list[child] < this->list[child + 1])
			child++;

		// Calculates if a swap need to occur
		if (this->list[root] < this->list[child]) {
			std::swap(this->list[root], this->list[child]);
			root = child;

			// Calculate next child
			child = (root - start) * 2 + 1;
		}
		else return;
	}
}