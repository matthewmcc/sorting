#include <iostream>
#include <vector>

// Linkedlist node structure
template <typename T> 
struct Node {
	Node<T> *node;
	T value;
};

// Linkedlist structure
template <typename T> 
struct Linkedlist {
	Node<T> *head;
	T lsize;
	Node<T> *tail;
};

// BST structure
template <typename T>
struct BSTree {
	T value;
	BSTree<T> *left;
	BSTree<T> *right;
};

// Parent sorting class for sorting algrithms
template <typename T> 
class Sorting {

protected:
	explicit Sorting(std::vector<T>, int);
	bool sorted();
	bool sortedlink(Linkedlist<T>&);
	Linkedlist<T> vectortolink();
	void starttimer();
	double stoptimer(std::string);

	std::vector<T> list;
	int listsize;
	std::clock_t start;
};

// Constructor to be used by inherited classes
template <typename T>
Sorting<T>::Sorting(std::vector<T> l, int s) {
	list = l;
	listsize = s;
}

// Checks if vector is sorted
template <typename T>
bool Sorting<T>::sorted() {
	for(int i = 0; i < listsize - 1; i++) {
		if (list[i] > list[i + 1]) {
			std::cout << "Failure at index: " << i << std::endl;
			std::cout << list[i] << " : " << list[i + 1] << std::endl;

			for(int j = 0; j < list.size(); j++) {
				std::cout << list[j] << std::endl;
			}
			return false;
		}
	}

	return true;
}

// Checks if linked list is correctly sorted
template <typename T>
bool Sorting<T>::sortedlink(Linkedlist<T> &ll) {
	Node<T> *p = ll.head;

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
template <typename T>
Linkedlist<T> Sorting<T>::vectortolink() {
	Node<T> *n = new Node<T>;
	*n = (Node<T>){ new Node<T>, list[0] };
	Linkedlist<T> ll = { n, listsize };

	// Loops through all values in the vector adding them to the new Linkedlist
	for (int i = 1; i < listsize; i++) {
		*n->node = (Node<T>){ new Node<T>, list[i] };
		n = n->node;
	}

	n->node = NULL;
	ll.tail = n;
	return ll;
}

// Functions used for timing the algorithms
template <typename T>
void Sorting<T>::starttimer() {
    start = std::clock();
}

template <typename T>
double Sorting<T>::stoptimer(std::string sortname) {
	double duration = ( std::clock() - this->start ) / (double) CLOCKS_PER_SEC;
    std::cout << '\r' << sortname << " duration: " << duration << " secs" << std::endl;
    return duration;
}