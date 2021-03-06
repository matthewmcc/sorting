#include <iostream>
#include <vector>
#include <thread>

// Introsort sort class implementing sorting
template <typename T> 
class Introsort : public Sorting<T> {

	// Required size of sort list for an insertion sort
	int INSERTION_SIZE = 15;

public:
	Introsort(std::vector<T>, int);
	double sort();

private:
	void quickthread(int);
	void quick(int, int, int);
	inline void med3(int&, int&, int&);
	inline void heap(int, int);
	inline void siftdown(int, int, int&);
	inline void insertion(int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Introsort<T>::Introsort(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
double Introsort<T>::sort() {
	this->starttimer();
	std::cout << "Introsort, average case: O(n*n)" << std::endl;

	// INSERTION_SIZE = insize;
	// std::cout << log2(this->listsize) * 2 << " " << log(this->listsize) * 2 << std::endl;
	quickthread((log2(this->listsize) * 2) - 1);

	return this->stoptimer("Introsort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Introsort failed" << std::endl;
}


///////////////
template <typename T>
void Introsort<T>::quickthread(int depth) {
	int f = 0, l = this->listsize - 1;

	// Finds median of 3 pivot
	med3(this->list[l - 2], this->list[l - 1], this->list[l]);
	med3(this->list[l - 4], this->list[l - 3], this->list[l]);
	med3(this->list[l - 6], this->list[l - 5], this->list[l]);


 	T pivot = this->list[l];
 	int i = f;

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
		std::thread q1(&Introsort::quick, this, f, i - 1, depth - 1);
		std::thread q2(&Introsort::quick, this, i + 1, l, depth - 1);

		q1.join();
		q2.join();
	}
}
////////////////

template <typename T>
void Introsort<T>::quick(int first, int last, int depth) {
	// Finds median of 3 pivot
	med3(this->list[first], this->list[first + ((last - first) / 2)], this->list[last]);

 	T pivot = this->list[last];
 	int mid = first;

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

	if (!depth) {
		heap(first, mid - 1);
		heap(mid + 1, last);
		return;
	}

	if (mid - first < INSERTION_SIZE)
		insertion(first, mid - 1);
	else quick(first, mid - 1, depth - 1);
		
	if (last - mid + 1 < INSERTION_SIZE)
		insertion(mid + 1, last);
	else quick(mid + 1, last, depth - 1);
}

// Selects the median of the 3 pivots and places it at the end of the list
template <typename T>
inline void Introsort<T>::med3(int &l, int &m, int &r) {
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
inline void Introsort<T>::heap(int start, int end) {

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
inline void Introsort<T>::siftdown(int start, int end, int &offset) {
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
inline void Introsort<T>::insertion(int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && this->list[divid] < this->list[divid - 1]) {
				std::swap(this->list[divid], this->list[divid - 1]);
				divid--;
		}
	}
}