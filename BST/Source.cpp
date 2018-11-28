#include <iostream>
#include <Windows.h>
#include "BST.cpp"

using namespace std;

void main()
{
	SetConsoleTitle("Binary Search Tree");

	// Initialize Array
	int arr[] = { 10, 7, 9, 6, 1, 19, 20, 21, 22, 23, 8, 11, 2, 0, 28, 29,
		          4, 5, 3, 12, 13, 14, 15, 16, 17, 18, 24, 25, 26, 27, 30 };

	// Get Array size
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	cout << endl << endl;

	BST<int> Tree;

	// Create a balanced tree from the previous array
	Tree = Tree.CreateBalancedTree(arr, arrSize);

	// Visualize the resulting tree
	Tree.VisualizeTree();

	cout << endl << endl;

	system("Pause");

}