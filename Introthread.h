#include <iostream>
#include <vector>
#include <thread>

// Introthread sort class implementing sorting
template <typename T> 
class Introthread : public Sorting<T> {

	// Required size of sort list for an insertion sort
	int INSERTION_SIZE = 15;

	// Amount of threads supported by the hardware
	unsigned int NTHREADS;

public:
	Introthread(std::vector<T>, int);
	double sort();

private:
	void quickthread(std::vector<T>&, int, unsigned int);
	void thread_helper(int, int, int, unsigned int);
	void quick(std::vector<T>&, int, int, int);
	inline void med3(int&, int&, int&);
	inline void heap(std::vector<T>&, int, int);
	inline void siftdown(std::vector<T>&, int, int, int&);
	inline void insertion(std::vector<T>&, int, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Introthread<T>::Introthread(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
double Introthread<T>::sort() {
	this->starttimer();
	std::cout << "Introthread, average case: O(n*n)" << std::endl;

	// INSERTION_SIZE = insize;
	// std::cout << log2(listsize) * 2 << " " << log(listsize) * 2 << std::endl;
	NTHREADS = std::thread::hardware_concurrency();
	quickthread(this->list, (log2(this->listsize) * 2) - 1, NTHREADS / 2);

	return this->stoptimer("Introthread");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Introthread failed" << std::endl;
}


///////////////
template <typename T>
void Introthread<T>::quickthread(std::vector<T> &list, int depth, unsigned int threads) {
	int f = 0, l = list.size() - 1;

	// Finds median of 3 pivot
	med3(list[l - 2], list[l - 1], list[l]);
	med3(list[l - 4], list[l - 3], list[l]);
	med3(list[l - 6], list[l - 5], list[l]);


 	T pivot = list[l];
 	int i = f;

	for (int x = f; x < l; x++) {
		if (list[x] < pivot) {
			std::swap(list[i], list[x]);
			i++;
		}
	}

	if (i > l)
		i = l;
	else std::swap(list[i], list[l]);

	if (f < l) {
		std::thread q1(&Introthread::thread_helper, this, f, i - 1, depth - 1, threads);
		std::thread q2(&Introthread::thread_helper, this, i + 1, l, depth - 1, threads);

		q1.join();
		q2.join();
	}
}
////////////////

template <typename T>
void Introthread<T>::thread_helper(int first, int last, int depth, unsigned int threads) {
	// Detects the amount of avaliable threads left creates more if theres is
	if (threads < 3)
		quick(this->list, first, last, depth);
	else  quickthread(this->list, depth, threads / 2);
}

template <typename T>
void Introthread<T>::quick(std::vector<T> &list, int first, int last, int depth) {
	// Finds median of 3 pivot
	med3(list[first], list[first + ((last - first) / 2)], list[last]);

 	T pivot = list[last];
 	int mid = first;

	for (int x = first; x < last; x++) {
		if (list[x] < pivot) {
			std::swap(list[mid], list[x]);
			mid++;
		}
	}

	if (mid > last)
		mid = last;
	else std::swap(list[mid], list[last]);

	// Selecting which sorting algorithm to use by list size

	if (!depth) {
		heap(list, first, mid - 1);
		heap(list, mid + 1, last);
		return;
	}

	if (mid - first < INSERTION_SIZE)
		insertion(list, first, mid - 1);
	else quick(list, first, mid - 1, depth - 1);
		
	if (last - mid + 1 < INSERTION_SIZE)
		insertion(list, mid + 1, last);
	else quick(list, mid + 1, last, depth - 1);
}

// Selects the median of the 3 pivots and places it at the end of the list
template <typename T>
inline void Introthread<T>::med3(int &l, int &m, int &r) {
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
inline void Introthread<T>::heap(std::vector<T> &list, int start, int end) {

	for (int i = (((end - start) - 1) / 2) + start; i >= start; i--)
		siftdown(list, i, end, start);

	// Removes the root of the heap placing it at the end and decrements the...
	// ...heap size untill list is ordered
	for (int i = end; i > start; i--) {
		std::swap(list[i], list[start]);
		siftdown(list, start, i - 1, start);
	}
}

template <typename T>
inline void Introthread<T>::siftdown(std::vector<T> &list, int start, int end, int &offset) {
	// Calculate root and first child
	int root = start, child = ((start - offset) * 2 + 1) + offset;

	while (child <= end) {
		// Finds the largest of the 2 chiildren
		if (child + 1 <= end && list[child] < list[child + 1])
			child++;

		// Calculates if a swap need to occur
		if (list[root] < list[child]) {
			std::swap(list[root], list[child]);
			root = child;

			// Calculate next child
			child = ((root - offset) * 2 + 1) + offset;
		}
		else return;
	}
}

// In place insertion sort
template <typename T>
inline void Introthread<T>::insertion(std::vector<T> &list, int left, int right) {
	int divid;
	for (int i = left; i < right + 1; i++){
		divid = i;
	
		while (divid > left && list[divid] < list[divid - 1]) {
				std::swap(list[divid], list[divid - 1]);
				divid--;
		}
	}
}