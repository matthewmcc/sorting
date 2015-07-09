#include <iostream>
#include <vector>

// Linkedlist node structure
struct Node {
	Node *node;
	int value;
};

// Linkedlist structure
struct Linkedlist {
	Node *head;
	int lsize;
	Node *tail;
};

// Parent sorting class for sorting algrithms
class Sorting {
protected:
	std::vector<int> list;
	int listsize;
	std::clock_t start;

public:
	bool sorted();
	bool sortedlink(Linkedlist&);
	Linkedlist vectortolink();
	void starttimer();
	void stoptimer(std::string);	
};

// Checks if vector is sorted
bool Sorting::sorted() {
	for(int i = 0; i < listsize - 1; i++) {
		if (list[i] > list[i + 1]) {
			std::cout << "Failure at index: " << i << std::endl;
			std::cout << list[i] << " : " << list[i + 1] << std::endl;
			for(int j : list) {
				std::cout << j << std::endl;
			}
			return false;
		}
	}

	return true;
}

// Checks if linked list is correctly sorted
bool Sorting::sortedlink(Linkedlist &ll) {
	Node *p = ll.head;

	while (p->node) {
		if (p->value > p->node->value) {
			std::cout << "Sort faliure" << std::endl;
			return false;
		}
		p = p->node;
	}
	return true;
}

// Changes the vector to a Linkedlist
Linkedlist Sorting::vectortolink() {
	Node *n = new Node;
	*n = (Node){ new Node, list[0] };
	Linkedlist ll = { n, listsize };

	// Loops through all values in the vector adding them to the new Linkedlist
	for (int i = 1; i < listsize; i++) {
		*n->node = (Node){ new Node, list[i] };
		n = n->node;
	}

	n->node = NULL;
	ll.tail = n;
	return ll;
}

// Functions used for timing the algorithms
void Sorting::starttimer() {
    start = std::clock();
}
void Sorting::stoptimer(std::string sortname) {
    std::cout << '\r' << sortname << " duration: " << ( std::clock() - start ) / (double) CLOCKS_PER_SEC << " secs" << std::endl;
}