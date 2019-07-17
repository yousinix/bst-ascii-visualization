#pragma once
#include "bst.h"
#include <string>
using namespace std;

template <class T>
class visualizer
{
	bst<T> tree_;

	int get_node_height(node<T>*);
	int get_tree_height();
	int get_tree_width();

	int get_level_nodes(int) const;
	int get_tree_nodes();

	int get_levels_below(int);
	int get_subtree_width(int);
	int get_branch_height(int);
	auto get_level_indentation(int) -> int;

	string** initialize_values_array();

public:

	explicit visualizer(bst<T>);
	~visualizer();

	void visualize();

};