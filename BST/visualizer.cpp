#include "visualizer.h"
#include <iomanip>
#include <iostream>

template <class T>
visualizer<T>::visualizer(bst<T> tree, int node_length /* = -1 */, int space_length /* = -1 */)
{

	auto min_node_len = 0;
	auto min_space_len = 0;

	// Initialize tree-related variables
	tree_                 = tree;
	tree_root_            = tree_.get_root();
	tree_height_          = get_tree_height(tree_root_);
	tree_nodes_           = get_nodes_count(tree_height_) - 1;
	queue<node<T>*> nodes = breadth_first_search();

	// Initialize values_ array
	values_ = new string*[tree_nodes_];
	for (auto level = 0; level < tree_height_; level++)
	{
		values_[level] = new string[get_nodes_count(level)];
		for (auto node = 0; node < get_nodes_count(level); node++)
		{
			// Convert node to string and add it to values vector
			// also add empty string if node is empty
			auto value = nodes.front() == nullptr ? "" : to_string(nodes.front()->get_value());
			values_[level][node] = value;
			nodes.pop();

			// Calculate minimum required node length
			const int length = value.length();
			if (min_node_len < length) min_node_len = length;
		}
	}

	// Initialize node-related variables
	node_length_        = node_length > min_node_len ? node_length : min_node_len;       // Choose suitable node length
	node_type_          = node_length_ % 2;                                              // ZERO if length is even and ONE if odd
	node_shift_factor_  = node_length_ / 2;                                              // Shifting factor used in visualizing
	empty_node_         = string(node_length_, ' ');                                     // Represents an empty node

	// Initialize space-related variables
	min_space_len       = node_type_ ? 3 : 4;                                            // Calculate minimum required space length
	space_length_       = space_length > min_space_len ? space_length : min_space_len;   // Choose suitable node length
	space_shift_factor_ = space_length_ / 2;                                             // Shifting factor used in visualizing

	// Make sure that that both values are either even or odd
	assert(node_type_ == space_length_ % 2);
}

template <class T>
queue<node<T>*> visualizer<T>::breadth_first_search()
{
	queue<node<T>*> temp, nodes;
	temp.push(tree_root_);

	for (auto i = 0; i < tree_nodes_; i++)
	{
		node<T>* current = temp.front();
		temp.pop();
		nodes.push(current);

		if (current == nullptr)
		{
			temp.push(nullptr);
			temp.push(nullptr);
		}
		else
		{
			temp.push(current->get_left());
			temp.push(current->get_right());
		}
	}

	return nodes;
}

template <class T>
int visualizer<T>::get_tree_height(node<T>* root) const
{
	if (root == nullptr) return 0;
	const int left_height  = get_tree_height(root->get_left());
	const int right_height = get_tree_height(root->get_right());
	return left_height > right_height ? left_height + 1 : right_height + 1;
}

template <class T>
int visualizer<T>::get_nodes_count(const int level) const
{
	return int(pow(2, level));
}

template <class T>
int visualizer<T>::get_subtree_width(const int level) const
{
	const auto levels_below = tree_height_ - level - 1;
	const auto nodes_count  = get_nodes_count(levels_below);
	const auto spaces_count = nodes_count - 1;
	return node_length_ * nodes_count + space_length_ * spaces_count;
}

template <class T>
void visualizer<T>::visualize() const
{

	const auto last_level = tree_height_ - 1;

	for (auto level = 0; level < tree_height_; level++)
	{
		const auto nodes_count      = get_nodes_count(level);
		const auto last_node        = nodes_count - 1;
		const auto subtree_width    = get_subtree_width(level);
		const auto node_indentation = subtree_width / 2 - node_shift_factor_;
		const auto nodes_spacing    = subtree_width - 2 * (node_shift_factor_ - space_shift_factor_);
		const auto branch_height    = (subtree_width + 1) / 4;

		cout << string(node_indentation, ' ');

		for (auto node = 0; node < nodes_count; node++)
		{
			const auto node_value = values_[level][node].empty() ? empty_node_ : values_[level][node];
			cout << setw(node_length_) << setfill('0') << node_value;
			cout << string(nodes_spacing * (node != last_node), ' ');
		}

		cout << endl;

		for (auto i = 0; i < branch_height && level != last_level; i++)
		{
			const auto branch_indentation = subtree_width / 2 - 1 - i;
			cout << string(branch_indentation, ' ');

			for (auto node = 0; node < nodes_count; node++)
			{
				const auto has_left_child   = !values_[level + 1][2 * node    ].empty();
				const auto has_right_child  = !values_[level + 1][2 * node + 1].empty();
				const auto branch_width     = node_type_ + 2 * i;
				const auto branches_spacing = nodes_spacing + 2 * (node_shift_factor_ - 1 - i);

				cout << (has_left_child ? '/' : ' ');
				cout << string(branch_width, ' ');
				cout << (has_right_child ? '\\' : ' ');
				cout << string(branches_spacing * (node != last_node), ' ');
			}

			cout << endl;
		}
	}

}
