#include <iostream>
#include <vector>

// Bubble sort class implementing sorting
class Bubble: public Sorting {
public:
	Bubble(std::vector<int>, int);
	void sort();
	void bubble();
};

Bubble::Bubble(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Bubble::sort() {
	starttimer();
	std::cout << "Bubble sort, average case: O(n*n)" << std::endl;

	bubble();

	stoptimer("Bubble sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Bubble sort failed" << std::endl;
}

void Bubble::bubble() {
	bool swap = true;
	int pass = 0;

	while(swap) {
		swap = false;
		pass++;

		std::cout << "\rPass number: " << pass << std::flush;

		for(int i = 0; i < listsize - pass; i++) {
			if (list[i] > list[i + 1]) {
				swap = true;
				std::swap(list[i], list[i + 1]);
			}
		}
	}
}