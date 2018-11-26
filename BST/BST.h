#pragma once
#include <iostream>
#include <assert.h>

/*For VisualizeTree Funtion*/
#include <iomanip>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

template <class T>
class Node
{
public:
	T value;
	Node<T>* left, *right;
	Node();
	Node(T val);
};

template <class T>
class BST
{
	Node<T>* root;

public:
	BST(void);

	// Main Functions
	Node<T>* Root();
	bool Contains(T val);
	Node<T>* FindNode(T val);
	void Insert(T val);
	void Remove(T val);

	// Remove Helper functions
	Node<T>* FindParent(T val);
	Node<T>* FindMin(Node<T>* start);

	// Count Function
	int CountNodes(Node<T>* start);

	// Display Functions
	void Traverse(int order);
	void InOrder(Node<T>* start);
	void PreOrder(Node<T>* start);
	void PostOrder(Node<T>* start);

	// VisualizeTree Funtion
	void VisualizeTree();

	// VisualizeTree Helper Functions
	int NodeHeight(Node<T>* start);
	int TreeHeight();
	int TreeBaseWidth();

	int LevelNodes(int levelNumber);
	int TreeNodes();

	int LevelsBelow(int levelNumber);
	int SubtreeBaseWidth(int levelNumber);
	int BranchHeight(int levelNumber);
	int LevelIndentation(int levelNumber);

	string** InitializeValuesArray();

	~BST(void);
};

