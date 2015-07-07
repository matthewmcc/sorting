#include <iostream>
#include <vector>
#include <stack>

// Shell sort class implementing sorting
class Shell: public Sorting {
	std::stack<int> gapsequence;
public:
	Shell(std::vector<int>, int);
	void sort();
	void shell();
	void calcgapsequence();
	inline int sedgewick_1986(int&);
};

Shell::Shell(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Shell::sort() {
	starttimer();
	std::cout << "Shell sort, average case: O(n log n)" << std::endl;

	shell();

	stoptimer("Shell sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Shell sort failed" << std::endl;
}

void Shell::shell() {
	calcgapsequence();
	int gap, backgap, temp;

	// Runs the sort for on every gap in the gap sequence
	while (!gapsequence.empty()) {
		gap = gapsequence.top();
		gapsequence.pop();

		// Runs gap for every list index
		for (int i = 0; i + gap < listsize; i++) {

			// Checks first values are in order
			if (list[i] > list[i + gap]) {
				temp = list[i + gap];
				list[i + gap] = list[i];
				list[i] = temp;

				// Continues moving elements back through list untill their inorder...
				// ...with their last gap element
				backgap = i - gap;
				while (backgap >= 0 && list[backgap] > list[backgap + gap]) {
					temp = list[backgap + gap];
					list[backgap + gap] = list[backgap];
					list[backgap] = temp;

					backgap = backgap - gap;
				}
			}
		}
	}
}

// Calculates the gap sequence for the search
void Shell::calcgapsequence() {
	int gap = 1;

	for (int i = 1; gap < listsize; i++) {
		gapsequence.push(gap);
		gap = sedgewick_1986(i);
	}
}

// Sedgewicks 1986 gap sequence funciton
inline int Shell::sedgewick_1986(int &i) {
	return (pow(4, i) + (3 * pow(2, i - 1))) + 1;
}