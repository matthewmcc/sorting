#include <iostream>
#include <vector>

// Comb sort class implementing sorting
class Comb: public Sorting {
	const float SHRINK_FACTOR = 1.3;
public:
	Comb(std::vector<int>, int);
	void sort();
	void comb();
};

Comb::Comb(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Comb::sort() {
	starttimer();
	std::cout << "Comb sort, average case: O(n * n / pow(2, P)) where P is the # of increments" << std::endl;

	comb();

	stoptimer("Comb sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Comb sort failed" << std::endl;
}

void Comb::comb() {
	bool swap = true;
	int gap = listsize / SHRINK_FACTOR;

	while(swap || gap != 1) {
		swap = false;

		for(int i = 0; i + gap < listsize; i++) {
			if (list[i] > list[i + gap]) {
				swap = true;
				std::swap(list[i], list[i + gap]);
			}
		}

		// Srinks gap untill it equals 1
		if (gap != 1)
			gap /= SHRINK_FACTOR;
	}
}