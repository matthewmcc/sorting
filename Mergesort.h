#include <iostream>
#include <vector>

class Mergesort: public Sorting {
public:
	Mergesort(std::vector<int>, int);
	void sort();

private:
	std::vector<int> merge(std::vector<int>&, int);
	inline std::vector<int> vectormerge(const std::vector<int>&, const std::vector<int>&);
};

Mergesort::Mergesort(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

void Mergesort::sort() {
	starttimer();
	std::cout << "Mergesort, average case: O(n log n)" << std::endl;

	list = merge(list, listsize);

	stoptimer("Mergesort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Mergesort failed" << std::endl;
}

// Simple merge sort. Extreme thrashing for code simplistity.
std::vector<int> Mergesort::merge(std::vector<int> &mlist, int msize) {
	if (msize < 2)
		return mlist;

	int m = msize / 2;

	std::vector<int> left, right;

	for (int i = 0; i < m; i++)
		left.push_back(mlist[i]);

	for (; m < msize; m++) 
		right.push_back(mlist[m]);

	left = merge(left, left.size());
	right = merge(right, right.size());

	return vectormerge(left, right);
}

// Merges to vectors
inline std::vector<int> Mergesort::vectormerge(const std::vector<int>& left, 
	const std::vector<int>& right) {
	std::vector<int> mlist;
	mlist.reserve(left.size() + right.size());

	int l = 0, r = 0;

	while(true) {
		// std::cout << l << " : " << r << std::endl;
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


