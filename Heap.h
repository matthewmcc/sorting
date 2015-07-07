#include <iostream>
#include <vector>

// BST structure
struct BSTree {
	int value;
	BSTree *left;
	BSTree *right;
};

// Heap sort class implementing sorting
class Heap: public Sorting {
public:
	Heap(std::vector<int>, int);
	void sort();
	void heap();
	void treetovector(const BSTree*);
};

Heap::Heap(std::vector<int> l, int s) {
	list = l;
	listsize = s;
}

// Sort funciton
void Heap::sort() {
	starttimer();
	std::cout << "Heap sort, average case: O(n log n)" << std::endl;

	heap();

	stoptimer("Heap sort");

	// Checks if sort was successful
	if (!sorted())
		std::cout << "Heap sort failed" << std::endl;
}

void Heap::heap() {
	// Prime the root of the heap
	BSTree root = { list[0], NULL, NULL}, *parent, *cur;

	for (int i = 1; i < listsize; i++) {
		// New node to be inserted
		BSTree *node = new BSTree;
		*node =  (BSTree){ list[i], NULL, NULL};
		cur = &root;

		// Finds the node to add new node to
		while (cur) {
			parent = cur;
			if (list[i] < cur->value) 
				cur = cur->left;
			else
				cur = cur->right;
		}

		// Adds new node to Heap
		if (list[i] < parent->value)
			parent->left = node;
		else
			parent->right = node;
		}

	list.clear();
	treetovector(&root);
}

// In order traversal of tree adding values to list in order
void Heap::treetovector(const BSTree *node) {
	if (node->left)
		treetovector(node->left);

	list.push_back(node->value);

	if (node->right)
		treetovector(node->right);
}