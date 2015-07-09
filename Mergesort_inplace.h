#include <iostream>
#include <vector>

class Mergesort_inplace: public Sorting {
public:
	Mergesort_inplace(std::vector<int>, int);
	void sort();

private:
	Linkedlist merge(Linkedlist&);
	inline Linkedlist nextlink(Linkedlist&, int);
};

Mergesort_inplace::Mergesort_inplace(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

void Mergesort_inplace::sort() {
	std::cout << "Mergesort in place, average case: O(n log n)" << std::endl;

	Linkedlist ll = vectortolink();

	starttimer();
	ll = merge(ll);
	stoptimer("Mergesort in place");

	// Checks if sort was successful
	if (!sortedlink(ll))
		std::cout << "Merge sort in place failed" << std::endl;
}

// Gets the newnode
inline Linkedlist Mergesort_inplace::nextlink(Linkedlist &ll, int lsize) {
	Linkedlist nextll = ll;

	for (int i = 0; i < lsize; i++) {
		ll.tail = nextll.head;
		nextll.head = nextll.head->node;
	}
	nextll.lsize = ll.lsize - lsize;
	ll.tail->node = NULL;

	return nextll;
}

// Main in place merge sort function
Linkedlist Mergesort_inplace::merge(Linkedlist &ll) {
	if (ll.lsize < 2)
		return ll;

	// Halves the linked list and runs merge recursivly on new halves
	Linkedlist nll = nextlink(ll, (ll.lsize / 2)); //, ll.lsize - m};
	ll.lsize = ll.lsize / 2;

	ll = merge(ll);
	nll = merge(nll);

	// Primes Linkedlist with the first value
	Linkedlist newlink;
	Node *lnode = ll.head, *rnode = nll.head;

	if (ll.head->value < nll.head->value) {
		newlink = (Linkedlist){ lnode, (ll.lsize + nll.lsize), lnode };
		lnode = lnode->node;
	}
	else {
		newlink = (Linkedlist){ rnode, (ll.lsize + nll.lsize), rnode };
		rnode = rnode->node;
	}

	// Removes links to the left and right lists
	newlink.head->node = NULL;
	newlink.tail->node = NULL;

	// Merges the lists
	while(lnode && rnode) {
		if (lnode->value <= rnode->value) {
			newlink.tail->node = lnode;
			newlink.tail = lnode;
			lnode = lnode->node;
		}
		else {
			newlink.tail->node = rnode;
			newlink.tail = rnode;
			rnode = rnode->node;
		}
	}

	// Adds the right list to the new link list
	if (lnode == NULL) {
		if (rnode) {
			newlink.tail->node = rnode;
			newlink.tail = nll.tail;
		}
	}
	else {
		newlink.tail->node = lnode;

		// Sets tail to the end of the left list
		newlink.tail = ll.tail;
	}

	newlink.tail->node = NULL;

	return newlink;
}