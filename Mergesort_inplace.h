#include <iostream>
#include <vector>

// Mergesort in place sort class implementing sorting
template <typename T> 
class Mergesort_inplace : public Sorting<T> {
public:
	Mergesort_inplace(std::vector<T>, int);
	void sort();

private:
	Linkedlist<T> merge(Linkedlist<T>&);
	inline Linkedlist<T> nextlink(Linkedlist<T>&, int);
};

// Constructor defaults from Sorting class constructor
template <typename T>
Mergesort_inplace<T>::Mergesort_inplace(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T>
void Mergesort_inplace<T>::sort() {
	std::cout << "Mergesort in place, average case: O(n log n)" << std::endl;

	Linkedlist<T> ll = this->vectortolink();

	this->starttimer();
	ll = merge(ll);
	this->stoptimer("Mergesort in place");

	// Checks if sort was successful
	if (!this->sortedlink(ll))
		std::cout << "Merge sort in place failed" << std::endl;
}

// Gets the newnode
template <typename T>
inline Linkedlist<T> Mergesort_inplace<T>::nextlink(Linkedlist<T> &ll, int lsize) {
	Linkedlist<T> nextll = ll;

	for (int i = 0; i < lsize; i++) {
		ll.tail = nextll.head;
		nextll.head = nextll.head->node;
	}
	nextll.lsize = ll.lsize - lsize;
	ll.tail->node = NULL;

	return nextll;
}

// Main in place merge sort function
template <typename T>
Linkedlist<T> Mergesort_inplace<T>::merge(Linkedlist<T> &ll) {
	if (ll.lsize < 2)
		return ll;

	// Halves the linked list and runs merge recursivly on new halves
	Linkedlist<T> nll = nextlink(ll, (ll.lsize / 2)); //, ll.lsize - m};
	ll.lsize = ll.lsize / 2;

	ll = merge(ll);
	nll = merge(nll);

	// Primes Linkedlist with the first value
	Linkedlist<T> newlink;
	Node<T> *lnode = ll.head, *rnode = nll.head;

	if (ll.head->value < nll.head->value) {
		newlink = (Linkedlist<T>){ lnode, (ll.lsize + nll.lsize), lnode };
		lnode = lnode->node;
	}
	else {
		newlink = (Linkedlist<T>){ rnode, (ll.lsize + nll.lsize), rnode };
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