#pragma once

template <class T>
class node
{
public:
	T value;
	node<T>* left, *right;
	node();
	explicit node(T);
};

template <class T>
class bst
{
	node<T>* root_;


	// Remove Helper Functions
	node<T>* find_min(node<T>*);
	node<T>* find_parent(T);

	// Create Balanced Tree Helper Function
	void insert_middle_element(int, int, T*, bst<T>*);

public:

	bst();
	~bst();

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

	// Create Balanced Tree Function
	bst<T> create_balanced_tree(T*, int);

};

