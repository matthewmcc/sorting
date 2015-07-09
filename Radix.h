#include <iostream>
#include <vector>

// Radix sort class implementing sorting
class Radix: public Sorting {
public:
	Radix(std::vector<int>, int);
	void sort();
	void radix();
};

Radix::Radix(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Radix::sort() {
	starttimer();
	std::cout << "Radix sort, average case: O(nk)" << std::endl;

	radix();

	stoptimer("Radix sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Radix sort failed" << std::endl;
}

void Radix::radix() {
	// Inits vector of vectors for the radixs
	std::vector<std::vector<int*> > radix(10, std::vector<int*>());
	std::vector<std::vector<int*> > nradix(10, std::vector<int*>());

	int max = 0;

	// Finds the largest value in the list
	for (int i = 0; i < listsize; i++) {
		if (list[i] > max)
			max = list[i];
	}

	// Gets length of max n
	int maxlen = std::to_string(max).length();

	// Convert list to int arrays and adds first radix to vector
	for (int i = 0; i < listsize; i++) {
		int *pint = new int[maxlen], temp = list[i];

		for (int k = maxlen - 1; k >= 0; k--) {
			pint[k] = temp % 10;
			temp /= 10;
		}

		// Adds new int array pointer to first radix
		radix[*(pint + (maxlen - 1))].push_back(pint);
	}

	// Runs the sort for every radix
	for (int i = maxlen - 2; i >= 0; i--) {
		// Sorts all buckets to next bucket by radix
		for (int k = 0; k < maxlen; k++) {

			for (int l = 0; l < radix[k].size(); l++) {

				nradix[*((radix[k][l]) + i)].push_back(radix[k][l]);
			}
		}

		// Swaps radix and resets nradix
		radix.swap(nradix);
		std::vector<std::vector<int*> > n(10, std::vector<int*>());
		nradix.swap(n);
	}

	list.clear();

	// Converts the int arrays back to int and appends them to sorted list
	for (int i = 0; i < maxlen; i++) {

		for (int j = 0; j < radix[i].size(); j++) {
			std::string str = "";

			for (int m = 0; m < maxlen; m++) {
				str += std::to_string(*(radix[i][j] + m));
			}

			list.push_back(std::stoi(str));
		}
	}
}
