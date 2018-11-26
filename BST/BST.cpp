#include "BST.h"

/************** NODE CLASS **************/

template <class T>
Node<T>::Node()
{
	left = right = NULL;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	left = right = NULL;
}



/************** BST CLASS **************/

template <class T>
BST<T>::BST(void)
{
	root = NULL;
}

template <class T>
Node<T>* BST<T>::Root()
{
	return root;
}

template <class T>
bool BST<T>::Contains(T val)
{
	Node<T>* tmp = FindNode(val);

	return (tmp != NULL);
}

template <class T>
Node<T>* BST<T>::FindNode(T val)
{
	Node<T>* tmp = root;

	while ((tmp != NULL) && (tmp->value != val))
		if (tmp->value > val)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	return tmp;
}

template <class T>
void BST<T>::Insert(T val)
{
	assert(!Contains(val));
	Node<T>* tmp = root;
	Node<T>* newNode = new Node<T>(val);
	if (root == NULL)
		root = newNode;
	else
	{
		while (tmp != NULL)
		{
			if (tmp->value > val)
				if (tmp->left == NULL)
				{
					tmp->left = newNode;
					break;
				}
				else
					tmp = tmp->left;
			else
				if (tmp->right == NULL)
				{
					tmp->right = newNode;
					break;
				}
				else
					tmp = tmp->right;
		}
	}
}

template <class T>
void BST<T>::Remove(T val)
{
	Node<T>* n = findNode(val);
	if (n == NULL)
	{
		cout << "Node does not exist! Cannot remove node." << endl;
		return;
	}
	else
	{
		if ((n->left == NULL) && (n->right == NULL)) //deleting a leaf node
		{
			if (n == root)
				root = NULL;
			else
			{
				Node<T>* parent = findParent(val);
				if (val < parent->value)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			delete n;
		}
		else if ((n->left == NULL) && (n->right != NULL))
		{
			Node<T>* parent = findParent(val);
			if (n == root)
				root = n->right;
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
			Node<T>* parent = findParent(val);
			if (n == root)
				root = n->left;
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
			Node<T>* minNode = findMin(n->right);
			Node<T>* parent = findParent(minNode->value);
			n->value = minNode->value;

			if (parent == n)
				parent->right = minNode->right;
			else
				parent->left = minNode->right;
			delete minNode;
		}
	}
}

template <class T>
Node<T>* BST<T>::FindMin(Node<T>* start)
{
	Node<T>* minNode = start;
	while (minNode->left != NULL)
		minNode = minNode->left;
	return minNode;
}

template <class T>
Node<T>* BST<T>::FindParent(T val)
{
	Node<T>* a, *b;
	a = root;
	b = NULL;
	while ((a != NULL) && (a->value != val))
	{
		b = a;
		if (a->value > val)
			a = a->left;
		else
			a = a->right;
	}
	return b;
}

template <class T>
void BST<T>::Traverse(int order)
{
	if (order == 1)
		InOrder(root);
	else if (order == 2)
		PreOrder(root);
	else
		PostOrder(root);
}

template <class T>
void BST<T>::InOrder(Node<T>* start)
{
	if (start != NULL)
	{
		InOrder(start->left);
		cout << start->value << endl;
		InOrder(start->right);
	}
}

template <class T>
void BST<T>::PreOrder(Node<T>* start)
{
	if (start != NULL)
	{
		cout << start->value << endl;
		PreOrder(start->left);
		PreOrder(start->right);
	}
}

template <class T>
void BST<T>::PostOrder(Node<T>* start)
{
	if (start != NULL)
	{
		PostOrder(start->left);
		PostOrder(start->right);
		cout << start->value << endl;
	}
}


template <class T>
int BST<T>::CountNodes(Node<T>* start)
{
	int nodesCounter;

	if (start != NULL)
	{
		nodesCounter = 1;

		if (start->left == NULL)
		{
			nodesCounter += 0;
		}
		else
		{
			nodesCounter += CountNodes(start->left);
		}

		if (start->right == NULL)
		{
			nodesCounter += 0;
		}
		else
		{
			nodesCounter += CountNodes(start->right);
		}
	}
	else
	{
		nodesCounter = 0;
	}

	return nodesCounter;
}

template <class T>
BST<T>::~BST(void)
{
}
