#pragma once
#include "bst.h"
#include "node.h"
#include <string>
#include <queue>
using namespace std;

template <class T>
class visualizer
{

	bst<T> tree_;
	node<T>* tree_root_;
	int tree_height_;
	int tree_nodes_;
	string** values_;

	int node_length_;
	int node_type_;
	int node_shift_factor_;
	string empty_node_;

	int space_length_;
	int space_shift_factor_;

	queue<node<T>*> breadth_first_search();
	int get_tree_height(node<T>*) const;
	int get_nodes_count(int) const;
	int get_subtree_width(int) const;

public:

	explicit visualizer(bst<T>, int = -1, int = -1);
	~visualizer() = default;
	void visualize() const;

};