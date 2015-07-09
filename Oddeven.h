#include <iostream>
#include <vector>

// Oddeven sort class implementing sorting
class Oddeven: public Sorting {
public:
	Oddeven(std::vector<int>, int);
	void sort();
	void oddeven();
};

Oddeven::Oddeven(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Oddeven::sort() {
	starttimer();
	std::cout << "Oddeven sort, average case: O(n*n)" << std::endl;

	oddeven();

	stoptimer("Oddeven sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Oddeven sort failed" << std::endl;
}


void Oddeven::oddeven() {
	bool swap = true;
	int odd = 0, even = 1;

	while (swap) {
		swap = false;
		// Bubble sort form the left
		for (int o = odd; o < listsize; o += 2) {
			if (list[o] > list[o + 1]) {
				std::swap(list[o], list[o + 1]);
				swap = true;
			}
		}

		// Bubble sort from the right
		for (int e = even; e < listsize; e += 2) {
			if (list[e] > list[e + 1]){
				std::swap(list[e], list[e + 1]);
				swap = true;
			}
		}
	}
}