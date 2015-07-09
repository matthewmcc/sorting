#include <iostream>
#include <vector>

class Quicksort_inplace: public Sorting {
public:
	Quicksort_inplace(std::vector<int>, int);
	void sort();

private:
	void quick(int, int);
};

Quicksort_inplace::Quicksort_inplace(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

void Quicksort_inplace::sort() {
	starttimer();
	std::cout << "Quick sort in place, average case: O(n log n)" << std::endl;

	quick(0, listsize - 1);

	stoptimer("Quicksort in place");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Quicksort in place failed" << std::endl;
}

void Quicksort_inplace::quick(int f, int l) {
	int pivot = list[l], i = f, j = f;

	for (int x = f; x <= l; x++) {
		if (list[x] >= pivot) {
			std::swap(list[j], list[x]);
			j++;
		}
		else {
			std::swap(list[i], list[x]);
			i++;
			j++;
		}
	}

	if (l - f > 1 || list[f] > list[l])
		std::swap(list[i], list[l]);

	if (l - f > 1) {
		quick(f, i - 1);
		quick(i, l);
	}
}