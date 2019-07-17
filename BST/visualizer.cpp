#include "visualizer.h"
#include <iomanip>
#include <iostream>
#include <queue>

template <class T>
visualizer<T>::visualizer(bst<T> tree)
{
	tree_        = tree;
	tree_root_   = tree_.get_root();
	tree_height_ = get_node_height(tree_root_);
	tree_nodes_  = get_nodes_in_level(tree_height_) - 1;
	init_values();
}

template <class T>
visualizer<T>::~visualizer()
= default;

template <class T>
void visualizer<T>::init_values()
{
	if (tree_root_ == nullptr) return;

	values_ = new string*[tree_nodes_];
	for (auto level = 0; level < tree_height_; level++)
	{
		values_[level] = new string[get_nodes_in_level(level)];
	}

	queue<node<T>*> temp_queue, nodes_queue;
	temp_queue.push(tree_root_);

	for (auto i = 0; i < tree_nodes_; i++)
	{
		node<T>* current = temp_queue.front();
		temp_queue.pop();
		nodes_queue.push(current);

		if (current == nullptr)
		{
			temp_queue.push(nullptr);
			temp_queue.push(nullptr);
		}
		else
		{
			temp_queue.push(current->left);
			temp_queue.push(current->right);
		}
	}

	for (auto level = 0; level < tree_height_; level++)
	{
		for (auto node = 0; node < get_nodes_in_level(level); node++)
		{
			values_[level][node] = nodes_queue.front() == nullptr ? string(nodes_length_, ' ') : to_string(nodes_queue.front()->value);
			nodes_queue.pop();
		}
	}

}

template <class T>
int visualizer<T>::get_node_height(node<T>* start) const
{
	if (start == nullptr) return 0;

	const int left_height  = get_node_height(start->left);
	const int right_height = get_node_height(start->right);

	return left_height > right_height ? left_height + 1 : right_height + 1;
}

template <class T>
int visualizer<T>::get_nodes_in_level(const int level_number) const
{
	return int(pow(2, level_number));
}

template <class T>
int visualizer<T>::get_levels_below(const int level_number) const
{
	return tree_height_ - level_number - 1;
}

template <class T>
int visualizer<T>::get_subtree_width(const int level_number) const
{
	const auto number_of_nodes = pow(2, get_levels_below(level_number));
	return nodes_length_ * (2 * number_of_nodes - 2);
}

template <class T>
int visualizer<T>::get_branch_height(const int level_number) const
{
	if (level_number == tree_height_ - 1) return 0;
	return get_subtree_width(level_number) / 4 + 1;
}

template <class T>
int visualizer<T>::get_level_indentation(const int level_number) const
{
	if (level_number < 0) return 0;
	return get_subtree_width(level_number) / 2;
}

template <class T>
int visualizer<T>::is_empty(const string& node)
{
	return node.find_first_not_of(' ') == std::string::npos;
}

template <class T>
void visualizer<T>::visualize() const
{
	for (auto level = 0; level < tree_height_; level++)
	{
		const auto current_level_indentation  = get_level_indentation(level);
		const auto previous_level_indentation = get_level_indentation(level - 1);
		const auto nodes_in_level             = get_nodes_in_level(level);

		cout << string(current_level_indentation, ' ');

		for (auto node = 0; node < nodes_in_level; node++)
		{
			cout << setw(nodes_length_) << setfill('0') << values_[level][node];
			cout << string(previous_level_indentation, ' ');
		}

		cout << '\n';

		for (auto i = 0; i < get_branch_height(level); i++)
		{
			const auto branch_indentation = current_level_indentation - i;
			cout << string(branch_indentation, ' ');

			for (auto node = 0; node < nodes_in_level; node++)
			{
				const auto has_left_child  = !is_empty(values_[level + 1][2 * node]);
				const auto has_right_child = !is_empty(values_[level + 1][2 * node + 1]);
				const auto branch_width    = i * 2 + 1;
				const auto spaces_between  = previous_level_indentation - i * 2 * (level > 0);

				cout << (has_left_child ? '/' : ' ');
				cout << string(branch_width, ' ');
				cout << (has_right_child ? '\\' : ' ');
				cout << string(spaces_between, ' ');
			}

			cout << '\n';
		}
	}
}
