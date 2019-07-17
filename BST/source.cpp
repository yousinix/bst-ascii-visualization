#include <iostream>
#include <Windows.h>
#include "bst.cpp"
#include "visualizer.cpp"

using namespace std;

int main()
{
	SetConsoleTitle("Binary Search Tree");

	// Initialize Array
	int arr[] = { 10, 7, 9, 6, 1, 19, 20, 21, 22, 23, 8, 11, 2, 0, 28, 29,
		          4, 5, 3, 12, 13, 14, 15, 16, 17, 18, 24, 25, 26, 27, 30 };

	// Get Array size
	const int arr_size = sizeof arr / sizeof arr[0];

	cout << endl << endl;

	bst<int> tree;

	// Create a balanced tree from the previous array
	tree = tree.create_balanced_tree(arr, arr_size);

	visualizer<int> v(tree);
	// Visualize the resulting tree
	v.visualize();

	cout << endl << endl;

	system("Pause");
	return 0;

}
