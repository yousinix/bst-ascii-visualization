#include "node.h"

template <class T>
node<T>::node()
{
	left_ = right_ = nullptr;
}

template <class T>
node<T>::node(T value)
{
	value_ = value;
	left_ = right_ = nullptr;
}

template <class T>
T node<T>::get_value()
{
	return value_;
}

template <class T>
node<T>* node<T>::get_left()
{
	return left_;
}

template <class T>
node<T>* node<T>::get_right()
{
	return right_;
}

template <class T>
void node<T>::set_left(node<T>* node)
{
	left_ = node;
}

template <class T>
void node<T>::set_right(node<T>* node)
{
	right_ = node;
}
