#include <iostream>
#include <vector>

// Selection sort class implementing sorting
class Selection: public Sorting {
public:
	Selection(std::vector<int>, int);
	void sort();
	void select();
};

Selection::Selection(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Selection::sort() {
	starttimer();
	std::cout << "Selection sort, average case: O(n*n)" << std::endl;

	select();

	stoptimer("Selection sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Selection sort failed" << std::endl;
}

// Selection algorithm
void Selection::select() {
	int nextindex = 0, temp;

	// Loop to add next smallest to the next position of the list
	for (int pass = 0; pass < listsize - 1; pass++) {
		nextindex = pass;

		// Loop to find the next smallest
		for (int i = pass; i < listsize; i++)  {
			if (list[i] < list[nextindex]) {
				nextindex = i;
			}
		}

		// Moving the next smallest to the correct index
		temp = list[pass];
		list[pass] = list[nextindex];
		list[nextindex] = temp;
	}
}