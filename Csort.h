#include <iostream>
#include <vector>
#include <algorithm>

// Csort sort class implementing sorting
class Csort: public Sorting {
public:
	Csort(std::vector<int>, int);
	void sort();
};

Csort::Csort(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Csort::sort() {
	starttimer();
	std::cout << "Csort, average case: O(n*n)" << std::endl;

	std::sort(list.begin(), list.end());

	stoptimer("Csort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Csort failed" << std::endl;
}
