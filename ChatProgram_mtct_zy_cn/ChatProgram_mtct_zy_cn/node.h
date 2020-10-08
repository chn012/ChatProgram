#pragma once
#include <iostream>
using namespace std;

template<typename T>
class node
{

private:
	T data;
	node<T>* next;

public:
	~node();
	node();
	T getData();
	void setData(T d);
	void setNext(node<T>* pnext);
	node<T>* getNext();
	node(T d);

};

template<typename T>
node<T>::node()
{

}


template<typename T>
T node<T>::getData()
{
	return data;
}

template<typename T>
void node<T>::setData(T d)
{
	data = d;
}

template<typename T>
void node<T>::setNext(node<T>* pnext)
{
	next = pnext;
}

template<typename T>
node<T>* node<T>::getNext()
{
	return next;
}

template<typename T>
node<T>::node(T d)
{
	data = d;
	next = nullptr;
}

template<typename T>
node<T>::~node() {}

