#include <iostream>
#include <vector>

class Quicksort: public Sorting {
public:
	Quicksort(std::vector<int>, int);
	void sort();

private:
	std::vector<int> quick(std::vector<int>&, int);
};

Quicksort::Quicksort(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

void Quicksort::sort() {
	starttimer();
	std::cout << "Quicksort, average case: O(n log n)" << std::endl;

	list = quick(list, listsize);

	stoptimer("Quicksort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Quicksort failed" << std::endl;
}

// Recursive quicksort function
std::vector<int> Quicksort::quick(std::vector<int> &qlist, int qsize) {
	if (qsize < 2)
		return qlist;

	std::vector<int> low, high;

	int pivot = qlist[rand() % qsize];

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