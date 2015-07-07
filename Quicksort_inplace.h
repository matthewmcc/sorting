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
	int temp;

	for (int x = f; x <= l; x++) {
		if (list[x] >= pivot) {
			temp = list[j];
			list[j] = list[x];
			list[x] = temp;
			j++;
		}
		else {
			temp = list[i];
			list[i] = list[x];
			list[x] = temp;
			i++;
			j++;
		}
	}

	if (l - f > 1 || list[f] > list[l]) {
		temp = list[i];
		list[i] = pivot;
		list[l] = temp;
	}

	if (l - f > 1) {
		quick(f, i - 1);
		quick(i, l);
	}
}