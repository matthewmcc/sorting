#include <iostream>
#include <vector>

// BST sort class implementing sorting
template <typename T> 
class BST: public Sorting<T> {
public:
	BST(std::vector<T>, int);
	void sort();

private:
	void bST();
	void insert(BSTree<T>&, int);
	void treetovector(const BSTree<T>*);
};


// Constructor defaults from Sorting class constructor
template <typename T>
BST<T>::BST(std::vector<T> unsortedlist, int unsortlistsize) 
: Sorting<T>::Sorting(unsortedlist, unsortlistsize) {}

// Function that calls sort function and deals with sort timing
template <typename T> 
void BST<T>::sort() {
	this->starttimer();
	std::cout << "BST sort, average case: O(n log n)" << std::endl;

	bST();

	this->stoptimer("BST sort");

	// Checks if sort was successful
	if (!this->sorted())
		std::cout << "BST sort failed" << std::endl;
}

// Binary search tree sort. Loads all values into a BST, then does a...
// ... inorder traversal of the BST while pushing the values on to a vector
template <typename T> 
void BST<T>::bST() {
	// Prime the root of the BST
	BSTree<T> root = { this->list[0], NULL, NULL};

	for (int i = 1; i < this->listsize; i++) {
		insert(root, this->list[i]);
	}

	this->list.clear();
	treetovector(&root);
}

// Inserts new node into the BST
template <typename T> 
void BST<T>::insert(BSTree<T> &root, int data) {
	// New node to be inserted
	BSTree<T> *node = new BSTree<T>, *parent, *cur;
	*node = (BSTree<T>){ data, NULL, NULL};
	cur = &root;

	// Finds the node to add new node to
	while (cur) {
		parent = cur;
		if (data < cur->value) 
			cur = cur->left;
		else
			cur = cur->right;
	}

	// Adds new node to BST
	if (data < parent->value)
		parent->left = node;
	else
		parent->right = node;
}

// In order traversal of tree adding values to this->list in order
template <typename T> 
void BST<T>::treetovector(const BSTree<T> *node) {
	if (node->left)
		treetovector(node->left);

	this->list.push_back(node->value);

	if (node->right)
		treetovector(node->right);
}