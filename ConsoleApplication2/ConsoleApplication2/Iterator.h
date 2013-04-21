#pragma once
#include"stdafx.h"

template<class Data>
class Iterator
{
	template<class Data> friend class List;
private:
	Node<Data> *it;

public:
	Iterator();
	Iterator(Node<Data> *node);

	Iterator operator++(int i);
	Iterator operator--(int i);
	Data& operator*();
	bool operator==(const Iterator& it);
	bool operator!=(const Iterator& it);
	Node<Data>* operator ->();
};

template<class Data>
Iterator<Data>::Iterator() { }

template<class Data>
Iterator<Data>::Iterator(Node<Data> *node) : it(node) { }

template<class Data>
Iterator<Data> Iterator<Data>::operator++(int i)
{
	it = it->next;
	return *this;
}

template<class Data>
Iterator<Data> Iterator<Data>::operator--(int i)
{
	it = it->prev;
	return *this;
}

template<class Data>
Data& Iterator<Data>::operator*()
{
	return it->d;
}

template<class Data>
bool Iterator<Data>::operator==(const Iterator<Data>& it)
{
	return this->it == it.it;
}

template<class Data>
bool Iterator<Data>::operator!=(const Iterator<Data>& it)
{
	return this->it != it.it;
}

template<class Data>
Node<Data>* Iterator<Data>::operator ->()
{
		return it;
}