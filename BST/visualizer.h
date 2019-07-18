#pragma once
#include "bst.h"
#include <string>
using namespace std;

template <class T>
class visualizer
{
	const int node_length_        = 3;
	const int space_length_       = 3;
	const int node_type_          = node_length_  % 2;
	const int node_shift_factor_  = node_length_  / 2;
	const int space_shift_factor_ = space_length_ / 2;
	const string empty_node_      = string(node_length_, ' ');

	int tree_height_;
	int tree_nodes_;
	bst<T> tree_;
	node<T>* tree_root_;
	string** values_{};

	void init_values();
	int get_tree_height(node<T>*) const;
	int get_nodes_count(int) const;
	int get_subtree_width(int) const;

public:

	explicit visualizer(bst<T>);
	~visualizer();
	void visualize() const;

};