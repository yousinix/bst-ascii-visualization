#pragma once
#include "node.h"

template <class T>
class bst
{
	node<T>* root_ = nullptr;

	// Create Balanced Tree Helper Function
	void insert_middle_element(int, int, T*, bst<T>*);

	// Remove Helper Functions
	node<T>* find_min(node<T>*);
	node<T>* find_parent(T);

public:

	bst() = default;
	~bst() = default;

	// Create Balanced Tree Function
	bst<T> create_balanced_tree(T*, int);

	// Main Functions
	node<T>* get_root();
	bool contains(T);
	node<T>* find_node(T);
	void insert(T);
	void remove(T);

	// Display Functions
	void traverse(int);
	void in_order(node<T>*);
	void pre_order(node<T>*);
	void post_order(node<T>*);

	// Count Function
	int count_nodes(node<T>*);

};

