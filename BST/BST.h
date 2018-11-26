#pragma once
#include <iostream>
#include <assert.h>

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
	bool Contains(T val);
	Node<T>* FindNode(T val);
	void Insert(T val);
	void Remove(T val);

	// Remove Helper functions
	Node<T>* FindParent(T val);
	Node<T>* FindMin(Node<T>* start);

	// Display Functions
	void Traverse(int order);
	void InOrder(Node<T>* start);
	void PreOrder(Node<T>* start);
	void PostOrder(Node<T>* start);

	~BST(void);
};

