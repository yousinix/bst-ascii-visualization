#include "bst.cpp"
#include "visualizer.cpp"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleTitle("BST ASCII Visualization");

	// Initialize Array
	int arr[] = { 10, 7, 9, 6, 1, 19, 20, 21, 22, 23, 8, 11, 2, 0, 28, 29,
		          4, 5, 3, 12, 13, 14, 15, 16, 17, 18, 24, 25, 26, 27, 30 };

	// Get Array size
	const int arr_size = sizeof arr / sizeof arr[0];

	// Create a balanced tree from the previous array
	bst<int> tree;
	tree = tree.create_balanced_tree(arr, arr_size);

	// Visualize the resulting tree
	const visualizer<int> v(tree);
	cout << endl << endl;
	v.visualize();
	cout << endl << endl;

	system("Pause");
	return 0;

}
