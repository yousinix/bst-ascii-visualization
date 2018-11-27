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

////// Constructor //////

template <class T>
BST<T>::BST(void)
{
	root = NULL;
}



////// Main Funtions //////

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



////// Remove Helper Functions //////

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



////// Count Funtion //////

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



////// Count Funtion //////

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



////// VisualizeTree Funtion //////

template <class T>
void BST<T>::VisualizeTree()
{
	// Visualizes a Tree of any Height
	// with nodes' values from 0 to 999
	// or any 3 digits value.

	int totalNumberOfLevels = TreeHeight();
	string** levelsArray = InitializeValuesArray();

	for (int currentLevel = 0; currentLevel < totalNumberOfLevels; currentLevel++)
	{

		// Print Level Header
		int currentLevelIndentation  = LevelIndentation(currentLevel);
		int previousLevelIndentation = LevelIndentation(currentLevel - 1);

		cout << string(currentLevelIndentation, ' ');

		for (int nodeNumber = 0; nodeNumber < LevelNodes(currentLevel); nodeNumber++)
		{
			cout << setw(3) << setfill('0') << levelsArray[currentLevel][nodeNumber];
			cout << string(previousLevelIndentation, ' ');
		}

		cout << '\n';

		// Print Branches
		int branchWidth = 1;
		int branchIndentation = currentLevelIndentation;
		int spacesInBetween = previousLevelIndentation;

		for (int branchHeight = 0; branchHeight < BranchHeight(currentLevel); branchHeight++)
		{
			cout << string(branchIndentation, ' ');

			for (int nodeNumber = 0; nodeNumber < LevelNodes(currentLevel); nodeNumber++)
			{
				// Print Left Branch
				if (levelsArray[currentLevel + 1][2 * nodeNumber] == "   ")
					cout << " ";
				else
					cout << "/";

				// Print Branch Width
				cout << string(branchWidth, ' ');

				// Print Right Branch
				if (levelsArray[currentLevel + 1][2 * nodeNumber + 1] == "   ")
					cout << " ";
				else
					cout << "\\";

				// Print space between current node's branch and next node's branch
				if (currentLevel != 0)
					cout << string(spacesInBetween, ' ');
			}

			branchIndentation--;
			branchWidth += 2;
			spacesInBetween -= 2;
			cout << '\n';
		}
	}
}



////// VisualizeTree Helper Functions //////

template <class T>
int BST<T>::NodeHeight(Node<T>* start)
{
	if (start == NULL)
		return 0;
	else
	{
		// Get the height of each subtree from start node
		int leftHeight = NodeHeight(start->left);
		int rightHeight = NodeHeight(start->right);

		// Use the larger height
		if (leftHeight > rightHeight)
			return(leftHeight + 1);
		else
			return(rightHeight + 1);
	}
}

template <class T>
int BST<T>::TreeHeight()
{
	return NodeHeight(root);
}

template <class T>
int BST<T>::TreeBaseWidth()
{
	return (SubtreeBaseWidth(levelNumber) * 2) + 3;
}


template <class T>
int BST<T>::LevelNodes(int levelNumber)
{
	return (int)pow(2, levelNumber);
}

template <class T>
int BST<T>::TreeNodes()
{
	return (int)pow(2, TreeHeight()) - 1;
}


template <class T>
int BST<T>::LevelsBelow(int levelNumber)
{
	return TreeHeight() - levelNumber - 1;

}

template <class T>
int BST<T>::SubtreeBaseWidth(int levelNumber)
{
	// (Node/Space Width) * [(Number of nodes in subtree base) + (Number of spaces in subtree base)]
	return 3 * (pow(2, LevelsBelow(levelNumber)) + (pow(2, LevelsBelow(levelNumber)) - 2));

}

template <class T>
int BST<T>::BranchHeight(int levelNumber)
{
	if (levelNumber == TreeHeight() - 1)
		return 0;
	else
		return (SubtreeBaseWidth(levelNumber) / 4) + 1;
}

template <class T>
int BST<T>::LevelIndentation(int levelNumber)
{
	if (levelNumber == -1)
		return 0;
	else
		return SubtreeBaseWidth(levelNumber) / 2;
}


template <class T>
string** BST<T>::InitializeValuesArray()
{
	if (root == NULL)
	{
		return NULL;
	}

	else
	{
		string** valuesArray = new string*[TreeNodes()];

		for (int level = 0; level < TreeHeight(); level++)
		{
			valuesArray[level] = new string[LevelNodes(level)];
		}

		queue<Node<T>*> tempQueue, nodesQueue;
		tempQueue.push(root);

		for (int numberOfNodes = 0; numberOfNodes < TreeNodes(); numberOfNodes++)
		{
			Node<T>* current = tempQueue.front();
			tempQueue.pop();
			nodesQueue.push(current);

			if (current == NULL) {
				tempQueue.push(NULL);
				tempQueue.push(NULL);
			}
			else
			{
				tempQueue.push(current->left);
				tempQueue.push(current->right);
			}
		}

		for (int level = 0; level < TreeHeight(); level++)
		{
			for (int nodeNumber = 0; nodeNumber < LevelNodes(level); nodeNumber++)
			{
				if (nodesQueue.front() == NULL)
					valuesArray[level][nodeNumber] = "   ";
				else
				{
					valuesArray[level][nodeNumber] = to_string(nodesQueue.front()->value);
				}
				nodesQueue.pop();
			}
		}

		return valuesArray;
	}
}



////// Create Balanced Tree Funtion //////

template <class T>
BST<T> BST<T>::CreateBalancedTree(T *vals, int arraySize)
{
	// Takes an array of elements and its size then inserts
	// those elements to an initially Empty tree making sure that
	// the resulting tree is balanced, then returns the new tree.
	// (WARNING: ORIGINAL TREE WILL BE LOST!)

	// STEP 0: Create an empty tree
	BST<T> balancedTree;

	// STEP 1: Sort the given array in ascending order
	sort(vals, vals + arraySize);

	// STEP 2: Insert Middle elements to the created tree
	InsertMiddleElement(0, arraySize - 1, vals, &balancedTree);

	return balancedTree;
}


////// Create Balanced Tree Helper Funtion //////

template <class T>
void BST<T>::InsertMiddleElement(int startIndex, int endIndex, T *vals, BST<T>* balancedTree)
{
	// This function gets the middleIndex between startIndex and endIndex
	// then insert the elements at that index from the given array
	// to the given Binary Search Tree


	// Get the Number of elements between the startIndex and the endIndex
	int numberOfElementsInBetween = endIndex - startIndex - 1;


	// If numberOfElementsInBetween is odd number
	// then we need to ceil the integer divison
	// That's why a one is added before the divison

	// e.g. if numberOfElementsInBetween is 3 (odd)
	// [ ] [ ] [ ] [S] [M] [ ] [ ] [E] -------->  3      / 2 = 1 + S
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [E] --------> (3 + 1) / 2 = 2 + S (Desired output)

	// e.g. if numberOfElementsInBetween is 4 (even)
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [ ] [E] ---->  4      / 2 = 2 + S
	// [ ] [ ] [ ] [S] [ ] [M] [ ] [ ] [E] ----> (4 + 1) / 2 = 2 + S (Desired output)

	int middleIndex = ((numberOfElementsInBetween + 1) / 2) + startIndex;


	// In case startIndex equals endIndex
	if (numberOfElementsInBetween < 0) {
		balancedTree->Insert(vals[startIndex]);
	}

	// In case there is no elements between startIndex and endIndex
	else if (numberOfElementsInBetween == 0) {
		balancedTree->Insert(vals[startIndex]);
		balancedTree->Insert(vals[endIndex]);
	}

	// In case there is more then one element between startIndex and endIndex
	else {
		balancedTree->Insert(vals[middleIndex]);
		// Slice the array into two parts and repeat the previous function on each part
		// First part starts from startIndex to the element before the middleIndex
		InsertMiddleElement(startIndex, middleIndex - 1, vals, balancedTree);
		// Second part starts from the element after  the middleIndex to the endIndex
		InsertMiddleElement(middleIndex + 1, endIndex, vals, balancedTree);
	}
}



////// Destructor  //////

template <class T>
BST<T>::~BST(void)
{
}
