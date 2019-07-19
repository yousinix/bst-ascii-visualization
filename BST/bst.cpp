#include "bst.h"
#include "node.cpp"
#include <cassert>
#include <iostream>
using namespace std;


////// Create Balanced Tree Helper Function //////

template <class T>
void bst<T>::insert_middle_element(int start_index, int end_index, T* values, bst<T>* balanced_tree)
{
	// This function gets the middleIndex between startIndex and endIndex
	// then insert the elements at that index from the given array
	// to the given Binary Search Tree

	// Get the Number of elements between the startIndex and the endIndex
	const auto number_of_elements_in_between = end_index - start_index - 1;

	// If numberOfElementsInBetween is odd number
	// then we need to ceil the integer division
	// That's why a one is added before the division

	// e.g. if numberOfElementsInBetween is 3 (odd)
	// [ ] [ ] [ ] [S] [M] [ ] [ ] [E] -------->  3      / 2 = 1 + S
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [E] --------> (3 + 1) / 2 = 2 + S (Desired output)

	// e.g. if numberOfElementsInBetween is 4 (even)
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [ ] [E] ---->  4      / 2 = 2 + S
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [ ] [E] ----> (4 + 1) / 2 = 2 + S (Desired output)

	auto middle_index = ((number_of_elements_in_between + 1) / 2) + start_index;

	if (number_of_elements_in_between < 0)
	{
		// In case startIndex equals endIndex
		balanced_tree->insert(values[start_index]);
	}
	else if (number_of_elements_in_between == 0)
	{
		// In case there is no elements between startIndex and endIndex
		balanced_tree->insert(values[start_index]);
		balanced_tree->insert(values[end_index]);
	}
	else
	{
		// In case there is more then one element between startIndex and endIndex
		balanced_tree->insert(values[middle_index]);
		// Slice the array into two parts and repeat the previous function on each part
		// First part starts from startIndex to the element before the middleIndex
		insert_middle_element(start_index, middle_index - 1, values, balanced_tree);
		// Second part starts from the element after  the middleIndex to the endIndex
		insert_middle_element(middle_index + 1, end_index, values, balanced_tree);
	}
}


////// Create Balanced Tree Function //////

template <class T>
bst<T> bst<T>::create_balanced_tree(T* values, int array_size)
{
	// Takes an array of elements and its size then inserts
	// those elements to an initially Empty tree making sure that
	// the resulting tree is balanced, then returns the new tree.
	// (WARNING: ORIGINAL TREE WILL BE LOST!)

	// STEP 0: Create an empty tree
	bst<T> balanced_tree;

	// STEP 1: Sort the given array in ascending order
	sort(values, values + array_size);

	// STEP 2: Insert Middle elements to the created tree
	insert_middle_element(0, array_size - 1, values, &balanced_tree);

	return balanced_tree;
}


////// Remove Helper Functions //////

template <class T>
node<T>* bst<T>::find_min(node<T>* start)
{
	node<T>* min_node = start;
	while (min_node->get_left() != nullptr)
		min_node = min_node->get_left();
	return min_node;
}

template <class T>
node<T>* bst<T>::find_parent(T value)
{
	node<T>* first = root_;
	node<T>* second = nullptr;

	while (first != nullptr && first->get_value() != value)
	{
		second = first;
		if (first->get_value() > value)
			first = first->get_left();
		else
			first = first->get_right();
	}
	return second;
}


////// Main Functions //////

template <class T>
node<T>* bst<T>::get_root()
{
	return root_;
}

template <class T>
bool bst<T>::contains(T value)
{
	node<T>* temp = find_node(value);
	return (temp != nullptr);
}

template <class T>
node<T>* bst<T>::find_node(T value)
{
	node<T>* temp = root_;

	while (temp != nullptr && temp->get_value() != value)
		if (temp->get_value() > value)
			temp = temp->get_left();
		else
			temp = temp->get_right();

	return temp;
}

template <class T>
void bst<T>::insert(T value)
{
	assert(!contains(value));

	auto* new_node = new node<T>(value);

	if (root_ == nullptr)
	{
		root_ = new_node;
		return;
	}

	node<T>* temp = root_;
	while (temp != nullptr)
	{
		if (temp->get_value() > value)
		{
			if (temp->get_left() == nullptr)
			{
				temp->set_left(new_node);
				break;
			}
			temp = temp->get_left();
		}
		else if (temp->get_right() == nullptr)
		{
			temp->set_right(new_node);
			break;
		}
		else
			temp = temp->get_right();
	}
}

template <class T>
void bst<T>::remove(T value)
{
	node<T>* del_node = find_node(value);

	if (del_node == nullptr)
	{
		cout << "Node does not exist! Cannot remove node." << endl;
		return;
	}

	if (del_node->get_left() == nullptr && del_node->get_right() == nullptr) // Deleting a leaf node
	{
		node<T>* parent = find_parent(value);
		if (del_node == root_)
			root_ = nullptr;
		else
		{
			if (value < parent->get_value())
				parent->get_left() = nullptr;
			else
				parent->get_right() = nullptr;
		}
		delete del_node;
	}
	else if (del_node->get_left() == nullptr && del_node->get_right() != nullptr)
	{
		node<T>* parent = find_parent(value);
		if (del_node == root_)
			root_ = del_node->get_right();
		else
		{
			if (value < parent->get_value())
				parent->get_left() = del_node->get_right();
			else
				parent->get_right() = del_node->get_right();
		}
		delete del_node;
	}
	else if (del_node->get_left() != nullptr && del_node->get_right() == nullptr)
	{
		node<T>* parent = find_parent(value);
		if (del_node == root_)
			root_ = del_node->get_left();
		else
		{
			if (value < parent->get_value())
				parent->get_left() = del_node->get_left();
			else
				parent->get_right() = del_node->get_left();
		}
		delete del_node;
	}
	else
	{
		node<T>* min_node = find_min(del_node->get_right());
		node<T>* parent = find_parent(min_node->get_value());
		del_node->get_value() = min_node->get_value();

		if (parent == del_node)
			parent->get_right() = min_node->get_right();
		else
			parent->get_left() = min_node->get_right();
		delete min_node;
	}
}


////// Display Functions //////

template <class T>
void bst<T>::traverse(const int order)
{
	switch (order)
	{
	case 1:
		in_order(root_);
		break;
	case 2:
		pre_order(root_);
		break;
	case 3:
		post_order(root_);
		break;
	default: 
		cout << "Invalid traverse order!";
	}
}

template <class T>
void bst<T>::in_order(node<T>* start)
{
	if (start != nullptr)
	{
		in_order(start->get_left());
		cout << start->get_value() << endl;
		in_order(start->get_right());
	}
}

template <class T>
void bst<T>::pre_order(node<T>* start)
{
	if (start != nullptr)
	{
		cout << start->get_value() << endl;
		pre_order(start->get_left());
		pre_order(start->get_right());
	}
}

template <class T>
void bst<T>::post_order(node<T>* start)
{
	if (start != nullptr)
	{
		post_order(start->get_left());
		post_order(start->get_right());
		cout << start->get_value() << endl;
	}
}


////// Count Function //////

template <class T>
int bst<T>::count_nodes(node<T>* start)
{
	if (start == nullptr) return 0;

	auto counter = 1;
	if (start->get_left()  != nullptr) counter += count_nodes(start->get_left());
	if (start->get_right() != nullptr) counter += count_nodes(start->get_right());

	return counter;
}