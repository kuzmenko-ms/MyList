#pragma once
#include "stdafx.h"

template<class Data>
class Node
{
	template<class Data> friend class List;
	template<class Data> friend class Iterator;
private:
	Data d;
	Node *next, *prev;
public:
		
	Node() { next = prev = NULL; }
	Node(Data dat)
	{
		d=dat; next = 0; prev = 0;
	}
};