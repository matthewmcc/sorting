#include <iostream>
#include <vector>

// Mergesort sort class implementing sorting
template <typename T> 
class Mergesort : public Sorting<T> {

public:
	Mergesort(std::vector<T>, int);
	void sort();

private:
	std::vector<int> merge(std::vector<int>&, int);
	inline std::vector<int> vectormerge(const std::vector<int>&, 
		const std::vector<int>&);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Mergesort<T>::Mergesort(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void Mergesort<T>::sort() {
	this->starttimer();
	std::cout << "Mergesort, average case: O(n log n)" << std::endl;

	this->list = merge(this->list, this->listsize);

	this->stoptimer("Mergesort sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "Mergesort sort failed" << std::endl;
}

// Simple merge sort. Extreme thrashing for code simplistity.
template <typename T> 
std::vector<int> Mergesort<T>::merge(std::vector<int> &mlist, int msize) {
	if (msize < 2)
		return mlist;

	int m = msize / 2;

	std::vector<int> left, right;

	// Splits vector mlist into 2 even lists
	for (int i = 0; i < m; i++)
		left.push_back(mlist[i]);

	for (; m < msize; m++) 
		right.push_back(mlist[m]);

	// Recursively calls merge on the 2 new lists
	left = merge(left, left.size());
	right = merge(right, right.size());

	// Merges the 2 ordered lists and returns result
	return this->vectormerge(left, right);
}

// Merges to vectors
template <typename T> 
inline std::vector<int> Mergesort<T>::vectormerge(const std::vector<int>& left, 
	const std::vector<int>& right) {
	std::vector<int> mlist;
	mlist.reserve(left.size() + right.size());

	int l = 0, r = 0;

	while(true) {
		// Pushs from the larger value of the 2 lists to mlist
		if(left[l] < right[r]) {
			mlist.push_back(left[l]);
			l++;

			if(l >= left.size()) {
				for(; r < right.size(); r++) {
					mlist.push_back(right[r]);
				}
				return mlist;
			}
		}
		else{
			mlist.push_back(right[r]);
			r++;

			if(r >= right.size()) {
				for(; l < left.size(); l++) {
					mlist.push_back(left[l]);
				}
				return mlist;
			}
		}
	}
}