#include <iostream>
#include "BST.cpp"

using namespace std;

void main()
{
	BST<int> Tree;
	int arr[13] = { 10, 7, 9, 6, 1, 8, 11, 2, 0, 4, 5, 3, 12 };

	// Create a balanced tree from the previous array
	Tree = Tree.CreateBalancedTree(arr, 13);

	// Visualize the resulting tree
	Tree.VisualizeTree();

	cout << endl << endl;

	system("Pause");

}