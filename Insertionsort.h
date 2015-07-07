#include <iostream>
#include <vector>

// Insertionsort sort class implementing sorting
class Insertionsort: public Sorting {
public:
	Insertionsort(std::vector<int>, int);
	void sort();
	void insertion();
};

Insertionsort::Insertionsort(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Insertionsort::sort() {
	starttimer();
	std::cout << "Insertion sort, average case: O(n*n)" << std::endl;

	insertion();

	stoptimer("Insertion sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Insertion sort failed" << std::endl;
}

void Insertionsort::insertion() {
	std::vector<int> sortedlist;
	int temp;

	// Removes items from unsorted list untill its empty
	while (!list.empty()) {
		temp = list.back();
		list.pop_back();

		// Finds the correct place in the sorted list to add next element
		for (int i = 0; true; i++) {
			if (i >= sortedlist.size() || temp < sortedlist[i]) {
				sortedlist.insert(sortedlist.begin() + i, temp);
				break;
			}
		}

		std::cout << std::endl;
		for (int i : sortedlist)
			std::cout << i << std::endl;
	}

	list = sortedlist;
}