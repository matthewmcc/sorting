#include <iostream>
#include <vector>

class Quicksort_med3: public Sorting {
public:
	Quicksort_med3(std::vector<int>, int);
	void sort();

private:
	std::vector<int> quick(std::vector<int>&, int);
	inline int med3(const std::vector<int>&, const int&);
};

Quicksort_med3::Quicksort_med3(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

void Quicksort_med3::sort() {
	starttimer();
	std::cout << "Quicksort median of 3, average case: O(n log n)" << std::endl;

	list = quick(list, listsize);

	stoptimer("Quicksort median of 3");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Quicksort median of 3 failed" << std::endl;
}

// Recursive quicksort function
std::vector<int> Quicksort_med3::quick(std::vector<int> &qlist, int qsize) {
	if (qsize < 2)
		return qlist;

	std::vector<int> low, high;

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
inline int Quicksort_med3::med3(const std::vector<int> &qlist, const int &qsize) {
	std::vector<int> pl;

	// If the list given is small a rand pivot will be returned
	if (qsize < 4)
		return qlist[rand() % qsize];

	for (int i = 0; i < 3; i++)
		pl.push_back(rand() % qsize);

	// Voodoo magic
	return std::max(std::min(qlist[pl[0]],qlist[pl[1]]), 
		std::min(std::max(qlist[pl[0]],qlist[pl[1]]),qlist[pl[2]]));
}