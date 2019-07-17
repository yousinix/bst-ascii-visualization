#pragma once
#include "bst.h"
#include <string>
using namespace std;

template <class T>
class visualizer
{
	int tree_height_;
	int tree_nodes_;
	int nodes_length_ = 3;
	bst<T> tree_;
	node<T>* tree_root_;
	string** values_{};

	void init_values();
	int get_node_height(node<T>*) const;
	int get_nodes_in_level(int) const;
	int get_levels_below(int) const;
	int get_subtree_width(int) const;
	int get_branch_height(int) const;
	int get_level_indentation(int) const;
	static int is_empty(const string&);

public:

	explicit visualizer(bst<T>);
	~visualizer();
	void visualize() const;

};