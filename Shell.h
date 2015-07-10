#include <iostream>
#include <vector>
#include <stack>

// Shell sort class implementing sorting
template <typename T> 
class Shell: public Sorting<T> {

	// Stack for the gap sequence
	std::stack<int> gapsequence;

public:
	Shell(std::vector<T>, int);
	void sort();

private:
	void shell();
	void calcgapsequence();
	inline int sedgewick_1986(int&);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Shell<T>::Shell(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Shell<T>::sort() {
	this->starttimer();
	std::cout << "Shell sort, average case: O(n log n)" << std::endl;

	shell();

	this->stoptimer("Shell sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Shell sort failed" << std::endl;
}

// Shell sorting function, a efficient change to bubble sort
template <typename T> 
void Shell<T>::shell() {
	calcgapsequence();
	int gap, backgap;

	// // Runs the sort for on every gap in the gap sequence
	while (!gapsequence.empty()) {
		gap = gapsequence.top();
		gapsequence.pop();

		// Runs gap for every list index
		for (int i = 0; i + gap < this->listsize; i++) {

			// Checks first values are in order
			if (this->list[i] > this->list[i + gap]) {
				std::swap(this->list[i], this->list[i + gap]);

				// Continues moving elements back through list untill their inorder...
				// ...with their last gap element
				backgap = i - gap;
				while (backgap >= 0 && this->list[backgap] > this->list[backgap + gap]) {
					std::swap(this->list[backgap], this->list[backgap + gap]);
					backgap = backgap - gap;
				}
			}
		}
	}
}

// Calculates the gap sequence for the search
template <typename T> 
void Shell<T>::calcgapsequence() {
	int gap = 1;

	for (int i = 1; gap < this->listsize; i++) {
		gapsequence.push(gap);
		gap = sedgewick_1986(i);
	}
}

// Sedgewicks 1986 gap sequence funciton
template <typename T> 
inline int Shell<T>::sedgewick_1986(int &i) {
	return (pow(4, i) + (3 * pow(2, i - 1))) + 1;
}