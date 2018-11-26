#include <iostream>
#include "BST.cpp"

using namespace std;

void main()
{
	BST<int> B;

	B.Insert(63);
	B.Insert(41);
	B.Insert(74);
	B.Insert(16);
	B.Insert(53);
	B.Insert(65);
	B.Insert(25);
	B.Insert(46);
	B.Insert(55);
	B.Insert(64);
	B.Insert(70);
	B.Insert(11);
	B.Insert(81);


	B.VisualizeTree();

	system("pause");
}