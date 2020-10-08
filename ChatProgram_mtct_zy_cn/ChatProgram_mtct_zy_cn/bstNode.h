#pragma once
#include <iostream>
using namespace std;

template<typename T>
class bstNode
{
protected:
	T root;
	bstNode<T>* left;
	bstNode<T>* right;

public:
	bstNode();
	bstNode(T data);
	~bstNode();
	bstNode<T>* getLeft();
	bstNode<T>* getRight();
	T getData();
	void setLeft(bstNode<T>* tmp);
	void setRight(bstNode<T>* tmp);
	void setRoot(T data);

};

template<typename T>
inline bstNode<T>::bstNode()
{
}

template<typename T>
inline bstNode<T>::bstNode(T data)
{
	root = data;
	left = nullptr;
	right = nullptr;
}

template<typename T>
inline bstNode<T>::~bstNode()
{
}

template<typename T>
inline bstNode<T>* bstNode<T>::getLeft()
{
	return left;
}

template<typename T>
inline bstNode<T>* bstNode<T>::getRight()
{
	return right;
}

template<typename T>
inline T bstNode<T>::getData()
{
	return root;
}

template<typename T>
inline void bstNode<T>::setLeft(bstNode<T>* tmp)
{
	left = tmp;
}

template<typename T>
inline void bstNode<T>::setRight(bstNode<T>* tmp)
{
	right = tmp;
}

template<typename T>
inline void bstNode<T>::setRoot(T data)
{
	root = data;
}


