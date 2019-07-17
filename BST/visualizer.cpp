#include "visualizer.h"
#include <iomanip>
#include <iostream>
#include <queue>

template <class T>
visualizer<T>::visualizer(bst<T> tree)
{
	tree_ = tree;
}

template <class T>
visualizer<T>::~visualizer()
= default;

template <class T>
int visualizer<T>::get_node_height(node<T>* start)
{
	if (start == nullptr) return 0;

	// Get the height of each subtree from start node
	const int left_height = get_node_height(start->left);
	const int right_height = get_node_height(start->right);

	// Use the larger height
	return left_height > right_height ? left_height + 1 : right_height + 1;
}

template <class T>
int visualizer<T>::get_tree_height()
{
	return get_node_height(tree_.get_root());
}

template <class T>
int visualizer<T>::get_tree_width()
{
	return (get_subtree_width(get_tree_height()) * 2) + 3;
}


template <class T>
int visualizer<T>::get_level_nodes(const int level_number) const
{
	return int(pow(2, level_number));
}

template <class T>
int visualizer<T>::get_tree_nodes()
{
	return int(pow(2, get_tree_height())) - 1;
}


template <class T>
int visualizer<T>::get_levels_below(const int level_number)
{
	return get_tree_height() - level_number - 1;
}

template <class T>
int visualizer<T>::get_subtree_width(const int level_number)
{
	// (Node/Space Width) * [(Number of nodes in subtree base) + (Number of spaces in subtree base)]
	return 3 * (pow(2, get_levels_below(level_number)) + (pow(2, get_levels_below(level_number)) - 2));
}

template <class T>
int visualizer<T>::get_branch_height(const int level_number)
{
	if (level_number == get_tree_height() - 1) return 0;
	return get_subtree_width(level_number) / 4 + 1;
}

template <class T>
int visualizer<T>::get_level_indentation(const int level_number)
{
	if (level_number == -1) return 0;
	return get_subtree_width(level_number) / 2;
}


template <class T>
string** visualizer<T>::initialize_values_array()
{
	if (tree_.get_root() == nullptr)
	{
		return nullptr;
	}

	const auto values_array = new string*[get_tree_nodes()];

	for (auto level = 0; level < get_tree_height(); level++)
	{
		values_array[level] = new string[get_level_nodes(level)];
	}

	queue<node<T>*> temp_queue, nodes_queue;
	temp_queue.push(tree_.get_root());

	for (auto number_of_nodes = 0; number_of_nodes < get_tree_nodes(); number_of_nodes++)
	{
		node<T>* current = temp_queue.front();
		temp_queue.pop();
		nodes_queue.push(current);

		if (current == nullptr)
		{
			temp_queue.push(NULL);
			temp_queue.push(NULL);
		}
		else
		{
			temp_queue.push(current->left);
			temp_queue.push(current->right);
		}
	}

	for (auto level = 0; level < get_tree_height(); level++)
	{
		for (auto node_number = 0; node_number < get_level_nodes(level); node_number++)
		{
			if (nodes_queue.front() == NULL)
				values_array[level][node_number] = "   ";
			else
			{
				values_array[level][node_number] = to_string(nodes_queue.front()->value);
			}
			nodes_queue.pop();
		}
	}

	return values_array;
}

template <class T>
void visualizer<T>::visualize()
{
	// Visualizes a Tree of any Height
	// with nodes' values from 0 to 999
	// or any 3 digits value.

	const auto total_number_of_levels = get_tree_height();
	const auto levels_array = initialize_values_array();

	for (auto current_level = 0; current_level < total_number_of_levels; current_level++)
	{
		// Print Level Header
		const auto current_level_indentation = get_level_indentation(current_level);
		const auto previous_level_indentation = get_level_indentation(current_level - 1);

		cout << string(current_level_indentation, ' ');

		for (auto node_number = 0; node_number < get_level_nodes(current_level); node_number++)
		{
			cout << setw(3) << setfill('0') << levels_array[current_level][node_number];
			cout << string(previous_level_indentation, ' ');
		}

		cout << '\n';

		// Print Branches
		auto branch_width = 1;
		auto branch_indentation = current_level_indentation;
		auto spaces_in_between = previous_level_indentation;

		for (auto branch_height = 0; branch_height < get_branch_height(current_level); branch_height++)
		{
			cout << string(branch_indentation, ' ');

			for (auto node_number = 0; node_number < get_level_nodes(current_level); node_number++)
			{
				// Print Left Branch
				if (levels_array[current_level + 1][2 * node_number] == "   ")
					cout << " ";
				else
					cout << "/";

				// Print Branch Width
				cout << string(branch_width, ' ');

				// Print Right Branch
				if (levels_array[current_level + 1][2 * node_number + 1] == "   ")
					cout << " ";
				else
					cout << "\\";

				// Print space between current node's branch and next node's branch
				if (current_level != 0)
					cout << string(spaces_in_between, ' ');
			}

			branch_indentation--;
			branch_width += 2;
			spaces_in_between -= 2;
			cout << '\n';
		}
	}
}