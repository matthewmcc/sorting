#include <iostream>
#include <vector>

// Introcomb sort class implementing sorting
template <typename T> 
class Introcomb : public Sorting<T> {

	// Required size of sort list for an insertion sort
	int COMB_SIZE = 15;

public:
	Introcomb(std::vector<T>, int);
	double sort();

private:
	void quick(int, int, int);
	inline void med3(int&, int&, int&);
	inline void heap(int, int);
	inline void siftdown(int, int, int&);
	inline void insertion(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Introcomb<T>::Introcomb(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
double Introcomb<T>::sort() {
	this->starttimer();
	std::cout << "Introcomb, average case: O(n*n)" << std::endl;

	quick(0, this->listsize - 1, (log(this->listsize) * 2) - 1);

	return this->stoptimer("Introcomb");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Introcomb failed" << std::endl;
}

template <typename T>
void Introcomb<T>::quick(int first, int last, int depth) {
	// Finds median of 3 pivot
	med3(this->list[first], this->list[first + ((last - first) / 2)], this->list[last]);

 	int pivot = this->list[last], mid = first;

	for (int x = first; x < last; x++) {
		if (this->list[x] < pivot) {
			std::swap(this->list[mid], this->list[x]);
			mid++;
		}
	}

	if (mid > last)
		mid = last;
	else std::swap(this->list[mid], this->list[last]);

	// Selecting which sorting algorithm to use by list size
	// int low = mid - f, high = last - mid + 1;

	if (!depth) {
		heap(first, mid - 1);
		heap(mid + 1, last);
		return;
	}

	if (mid - first < COMB_SIZE)
		insertion(first, mid - 1);
	else quick(first, mid - 1, depth - 1);
		
	if (last - mid + 1 < COMB_SIZE)
		insertion(mid + 1, last);
	else quick(mid + 1, last, depth - 1);
}

// Selects the median of the 3 pivots and places it at the end of the list
template <typename T>
inline void Introcomb<T>::med3(int &l, int &m, int &r) {
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
inline void Introcomb<T>::heap(int start, int end) {

	for (int i = (((end - start) - 1) / 2) + start; i >= start; i--)
		siftdown(i, end, start);

	// Removes the root of the heap placing it at the end and decrements the...
	// ...heap size untill list is ordered
	for (int i = end; i > start; i--) {
		std::swap(this->list[i], this->list[start]);
		siftdown(start, i - 1, start);
	}
}

template <typename T>
inline void Introcomb<T>::siftdown(int start, int end, int &offset) {
	// Calculate root and first child
	int root = start, child = ((start - offset) * 2 + 1) + offset;

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

// In place insertion sort
template <typename T>
inline void Introcomb<T>::insertion(int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && this->list[divid] < this->list[divid - 1]) {
				std::swap(this->list[divid], this->list[divid - 1]);
				divid--;
		}
	}
}