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

template <class Data>
class List
{
	
private:
	Node<Data> *pbeg, *pend;
	void remove(Node<Data> *node);

public:
	List(void);
	~List(void);

	void operator *();
	void add(Data d);
	void add_first(Data d);
	Node<Data> * find(Data i);
	Node<Data> * insert(int key, Data d);
	bool remove1(Data key);
	bool remove(Iterator<Data> it);
	void print();
	void del();
	void print_back();
	Iterator<Data> begin();											
	Iterator<Data> end();
	typedef Iterator<Data> iterator; 

};

template <class Data>
List <Data>::List()
{
	if (pbeg != 0)
	{
		Node<Data> *pv = pbeg;
		while (pv)
		{
			pv = pv->next;
			delete pbeg;
			pbeg = pv;
		}
	}
}

template <class Data>
Iterator<Data> List<Data>::begin()
{
	Iterator<Data> it(pbeg);
	return it;
}

template <class Data>
Iterator<Data> List<Data>::end()
{
	Iterator<Data> it(pend);
	return it;
}


template <class Data>
void List <Data>::add_first(Data d)
{
	Node<Data> *pv = new Node<Data>(d);
	if (pbeg == 0)
		pbeg = pend = pv;
	else
	{
		pv->next=pbeg;
		pbeg->next = pv;
		pend=pbeg;
	}
}

template <class Data>
void List <Data>::add(Data d)
{
	Node<Data> *pv = new Node<Data>(d);
	if (pbeg == 0)pbeg = pend = pv;
	else
	{
		pv->prev=pend;
		pend->next = pv;
		pend = pv;
	}
}

template <class Data>
void List <Data>::print()
{
	Node<Data> *pv = pbeg;
	std::cout << std::endl << "list: ";
	while (pv)
	{
		std::cout << pv->d<< ' ';
		pv = pv->next;
	}
	std::cout << std::endl;
}

template <class Data>
void List <Data>::del()
{
	if (pbeg)
	{
		Node<Data> *pv = pbeg;
		while (pv)
		{
			pv = pv->next;
			delete pbeg;
			pbeg = pv;
		}
	}
}


template <class Data>
void List <Data>::print_back()
{
	Node<Data> *pv = pend;
	std::cout << std::endl << "list reverse: ";
	while (pv)
	{
		std::cout << pv->d<< ' ';
		pv = pv->prev;
	}
	std::cout << std::endl;
}


template <class Data>
Node<Data> * List <Data>::find(Data d)
{
	Node<Data> *pv = pbeg;
	while (pv)
	{
		if(pv->d == d) 
		{
			std::cout<<"I'm here!";
			break;
		}
		pv = pv->next;
		 
		
	}
	return pv;
}

template <class Data>
Node<Data> * List<Data>::insert(int key, Data d)
{
	if (Node<Data> *pkey = find(key))
	{
		Node<Data> *pv = new Node<Data>(d);
		pv->next = pkey->next;
		pv ->prev = pkey;
		pkey->next = pv;
		if (pkey != pend)(pv->next)->prev = pv;
		else pend = pv;
		return pv;
	 }
	if (key == 0)
		{
			Node<Data> *pv = new Node<Data>(d);
			pv->next=pbeg;
			pbeg->prev=pv;
			Node<Data> *tmp = pbeg;
			pbeg=pv;
			pbeg->next = tmp;
			return pv;
		}

	return 0;
}

template <class Data>
bool List<Data>::remove1(Data key)
{
	if (Node<Data> *pkey = find(key))
	{
		if (pkey == pbeg)
		{
			pbeg=pbeg->next; pbeg->prev = 0;
		}
		else if (pkey == pend)
		{
			pend = pend->prev; pend->next = 0;
		}
		else 
		{
			(pkey->prev )->next = pkey->next;
			(pkey->next)->prev = pkey->prev;
		}
		delete pkey; return true;
	}
	return false;
}

template <class Data>
void List<Data>::remove(Node<Data> *node)
{
	if(!(node == pbeg))
	{
		node->prev->next = node->next;
	}
	else
	{
		pbeg = node->next;
	}
	
	if(!(node == pend))
	{
		node->next->prev = node->prev;
	}
	else
	{
		pend = node->prev;
	}

	delete node;
}

template <class Data>

bool List<Data>::remove(Iterator<Data> it)
{
	remove(it.it);

	return true;
}


template <class Data>
void List<Data>::operator *()
{
	Node<Data> * current =pbeg;
	Node<Data> * next =NULL;
	Node<Data> * prev =NULL;
while(current)
	{
		next = current->next;
		current->prev = next;
		current->next = prev;
		prev = current;
		current = next;
	}
	pbeg=prev;
	delete current,prev,next;	
}


// править принт back
// править (спрятать Node)

