#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template<typename T>
class linkedList
{
private:
	int counter;
	node<T>* next;

public:
	linkedList();
	~linkedList();
	void add(int index, T data);
	void deleted(int index);
	int find(T data);
	int count();
	void empty();
	void printOut();
	bool isEmpty();
	void setData(int index, T data);
	T getData(int index);
};

template<typename T>
linkedList<T>::linkedList()
{
	counter = 0;
	next = nullptr;
}

template<typename T>
linkedList<T>::~linkedList() {}

template<typename T>
void linkedList<T>::add(int index, T data)
{
	try
	{
		//add in front
		if (index == 0)
		{

			node<T>* tmp = next;
			next = new node<T>(data);
			next->setNext(tmp);
			counter++;

		}
		//add at back
		else if (index == counter)
		{
			node<T>* ptr = next;

			for (int i = 0; i < index - 1; i++)
			{
				ptr = ptr->getNext();
			}
			ptr->setNext(new node<T>(data));
			counter++;

		}
		//add in the middle 
		else if (index > 0 && index < counter)
		{
			node<T>* ptr = next;

			for (int i = 1; i < index; i++)
			{
				ptr = ptr->getNext();
			}
			node<T>* tmp = ptr->getNext();
			node<T>* nptr = new node<T>(data);
			nptr->setNext(tmp);
			ptr->setNext(nptr);

			counter++;
		}
		else
		{
			throw "wrong index";
		}
	}
	catch (const char* err)
	{
		cout << err << endl;
	}

}

template<typename T>
void linkedList<T>::deleted(int index)
{
	try
	{
		if (counter == 0)
		{
			throw("cannot delete empty linkedlist");
		}

		if (index == 0)
		{
			node<T> *temp = next;
			next = next->getNext();
			delete temp;
			counter--;
		}
		else if (index == counter - 1)
		{
			node<T>* temp = next;

			for (int count = 0; count < counter - 2; count++)
			{
				temp = temp->getNext();
			}
			delete temp->getNext();
			temp->setNext(NULL);
			counter--;
		}
		else if (index > 0 && index < counter - 1)
		{
			node<T>* curr;
			node<T>* prev = next;
			node<T>* temp;

			for (int count = 0; count < index - 1; count++)
			{
				prev = prev->getNext();
			}
			curr = prev->getNext();
			temp = curr->getNext();
			delete curr;
			prev->setNext(temp);
			counter--;
		}
		else
		{
			throw "wrong index";
		}
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}

template<typename T>
int linkedList<T>::find(T data)
{
	node<T>* ptr = next;
	for (int i = 0; i < counter; i++)
	{
		if (ptr->getData() == data)
		{
			return i + 1;
		}
		ptr = ptr->getNext();
	}
	return -1;
}

template<typename T>
int linkedList<T>::count()
{
	return counter;
}

template<typename T>
void linkedList<T>::empty()
{
	node<T> *temp;

	while (next != NULL)
	{
		temp = next;
		next = next->getNext();
		delete temp;
	}
	counter = 0;
}

template<typename T>
void linkedList<T>::printOut()
{
	node<T>* ptr = next;
	while (ptr != NULL)
	{
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
}

template<typename T>
bool linkedList<T>::isEmpty()
{
	return counter == 0;
}

template<typename T>
void linkedList<T>::setData(int index, T data)
{
	node<T>* ptr = next;
	try {
		if (index >= counter)
		{
			throw "index out of bond";
		}
		for (int i = 0; i < index; i++) {
			ptr = ptr->getNext();
		}
		ptr->setData(data);
	}
	catch (const char* err) {
		cout << err << endl;
	}
}

template<typename T>
T linkedList<T>::getData(int index)
{
	node<T>* ptr = next;
	try
	{
		if (index >= counter)
		{
			throw "invalid index";
		}

		for (int i = 0; i < index; i++)
		{
			ptr = ptr->getNext();
		}
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	return ptr->getData();
}
