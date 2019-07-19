#pragma once

template <class T>
class node
{
	T value_;
	node<T>* left_;
	node<T>* right_;

public:
	node();
	explicit node(T);
	T get_value();
	node<T>* get_left();
	node<T>* get_right();
	void set_left(node<T>*);
	void set_right(node<T>*);
};