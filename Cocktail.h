#include <iostream>
#include <vector>

// Cocktail sort class implementing sorting
class Cocktail: public Sorting {
public:
	Cocktail(std::vector<int>, int);
	void sort();
	void cocktail();
};

Cocktail::Cocktail(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Cocktail::sort() {
	starttimer();
	std::cout << "Cocktail sort, average case: O(n*n)" << std::endl;

	cocktail();

	stoptimer("Cocktail sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Cocktail sort failed" << std::endl;
}

// Cocktail sort that implements bubble altinating from left to right.
void Cocktail::cocktail() {
	bool swap = true;
	int left = 0, right = listsize - 1;

	while (swap) {
		swap = false;
		// Bubble sort form the left
		for (int l = left; l < right; l++) {
			if (list[l] > list[l + 1]) {
				std::swap(list[l], list[l + 1]);
				swap = true;
			}
		}
		right--;

		if (!swap)
			return;
		swap = false;

		// Bubble sort from the right
		for (int r = right; r > left; r--) {
			if (list[r] < list[r - 1]){
				std::swap(list[r], list[r - 1]);
				swap = true;
			}
		}
		left++;
	}
}
