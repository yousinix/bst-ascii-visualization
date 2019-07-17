#include "bst.h"
#include <cassert>

/************** NODE CLASS **************/

template <class T>
node<T>::node()
{
	left = right = NULL;
}

template <class T>
node<T>::node(T val)
{
	value = val;
	left = right = NULL;
}


/************** BST CLASS **************/

////// Constructor //////

template <class T>
bst<T>::bst()
{
	root_ = NULL;
}

////// Destructor //////

template <class T>
bst<T>::~bst()
= default;


////// Main Functions //////

template <class T>
node<T>* bst<T>::get_root()
{
	return root_;
}

template <class T>
bool bst<T>::contains(T val)
{
	node<T>* tmp = find_node(val);

	return (tmp != nullptr);
}

template <class T>
node<T>* bst<T>::find_node(T val)
{
	node<T>* tmp = root_;

	while ((tmp != nullptr) && (tmp->value != val))
		if (tmp->value > val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	return tmp;
}

template <class T>
void bst<T>::insert(T val)
{
	assert(!contains(val));
	node<T>* tmp = root_;
	node<T>* new_node = new node<T>(val);
	if (root_ == nullptr)
		root_ = new_node;
	else
	{
		while (tmp != nullptr)
		{
			if (tmp->value > val)
			{
				if (tmp->left == NULL)
				{
					tmp->left = new_node;
					break;
				}
				tmp = tmp->left;
			}
			else if (tmp->right == NULL)
			{
				tmp->right = new_node;
				break;
			}
			else
				tmp = tmp->right;
		}
	}
}

template <class T>
void bst<T>::remove(T val)
{
	node<T>* n = findNode(val);
	if (n == nullptr)
	{
		cout << "Node does not exist! Cannot remove node." << endl;
		return;
	}
	if ((n->left == NULL) && (n->right == NULL)) //deleting a leaf node
	{
		if (n == root_)
			root_ = NULL;
		else
		{
			node<T>* parent = findParent(val);
			if (val < parent->value)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		delete n;
	}
	else if ((n->left == NULL) && (n->right != NULL))
	{
		node<T>* parent = findParent(val);
		if (n == root_)
			root_ = n->right;
		else
		{
			if (val < parent->value)
				parent->left = n->right;
			else
				parent->right = n->right;
		}
		delete n;
	}
	else if ((n->left != NULL) && (n->right == NULL))
	{
		node<T>* parent = findParent(val);
		if (n == root_)
			root_ = n->left;
		else
		{
			if (val < parent->value)
				parent->left = n->left;
			else
				parent->right = n->left;
		}
		delete n;
	}
	else
	{
		node<T>* minNode = findMin(n->right);
		node<T>* parent = findParent(minNode->value);
		n->value = minNode->value;

		if (parent == n)
			parent->right = minNode->right;
		else
			parent->left = minNode->right;
		delete minNode;
	}
}


////// Remove Helper Functions //////

template <class T>
node<T>* bst<T>::find_min(node<T>* start)
{
	node<T>* min_node = start;
	while (min_node->left != NULL)
		min_node = min_node->left;
	return min_node;
}

template <class T>
node<T>* bst<T>::find_parent(T val)
{
	node<T>* a = root_;
	node<T>* b = nullptr;
	while ((a != nullptr) && (a->value != val))
	{
		b = a;
		if (a->value > val)
			a = a->left;
		else
			a = a->right;
	}
	return b;
}


////// Display Functions //////

template <class T>
void bst<T>::traverse(const int order)
{
	if (order == 1)
		in_order(root_);
	else if (order == 2)
		pre_order(root_);
	else
		post_order(root_);
}

template <class T>
void bst<T>::in_order(node<T>* start)
{
	if (start != nullptr)
	{
		in_order(start->left);
		cout << start->value << endl;
		in_order(start->right);
	}
}

template <class T>
void bst<T>::pre_order(node<T>* start)
{
	if (start != nullptr)
	{
		cout << start->value << endl;
		pre_order(start->left);
		pre_order(start->right);
	}
}

template <class T>
void bst<T>::post_order(node<T>* start)
{
	if (start != nullptr)
	{
		post_order(start->left);
		post_order(start->right);
		cout << start->value << endl;
	}
}


////// Count Function //////

template <class T>
int bst<T>::count_nodes(node<T>* start)
{
	int nodesCounter;

	if (start != nullptr)
	{
		nodesCounter = 1;

		if (start->left == NULL)
		{
			nodesCounter += 0;
		}
		else
		{
			nodesCounter += count_nodes(start->left);
		}

		if (start->right == NULL)
		{
			nodesCounter += 0;
		}
		else
		{
			nodesCounter += count_nodes(start->right);
		}
	}
	else
	{
		nodesCounter = 0;
	}

	return nodesCounter;
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
