#include <iostream>
#include <vector>

// Radix sort class implementing sorting
template <typename T> 
class Radix : public Sorting<T> {

public:
	Radix(std::vector<T>, int);
	void sort();

private:
	void radix();
};

// Constructor defaults from Sorting class constructor
template <typename T>
Radix<T>::Radix(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Radix<T>::sort() {
	this->starttimer();
	std::cout << "Radix sort, average case: O(nk)" << std::endl;

	radix();

	this->stoptimer("Radix sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Radix sort failed" << std::endl;
}

template <typename T> 
void Radix<T>::radix() {
	// Inits vector of vectors for the radixs
	std::vector<std::vector<T*> > radix(10, std::vector<T*>());
	std::vector<std::vector<T*> > nradix(10, std::vector<T*>());

	int max = 0;

	// Finds the largest value in the list
	for (int i = 0; i < this->listsize; i++) {
		if (this->list[i] > max)
			max = this->list[i];
	}

	// Gets length of max n
	int maxlen = std::to_string(max).length();

	// Convert list to int arrays and adds first radix to vector
	for (int i = 0; i < this->listsize; i++) {
		int *pint = new int[maxlen], temp = this->list[i];

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
		std::vector<std::vector<T*> > n(10, std::vector<T*>());
		nradix.swap(n);
	}

	this->list.clear();

	// Converts the int arrays back to int and appends them to sorted list
	for (int i = 0; i < maxlen; i++) {

		for (int j = 0; j < radix[i].size(); j++) {
			std::string str = "";

			for (int m = 0; m < maxlen; m++) {
				str += std::to_string(*(radix[i][j] + m));
			}

			this->list.push_back(std::stoi(str));
		}
	}
}
