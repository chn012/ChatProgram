#pragma once
#include "bstNode.h"
#include <iomanip>
#define COUNT 10 

template<typename T>
class bst {

public:
	bstNode<T>* root;
	bst();
	~bst();
	bst(T data);
	bstNode<T>* insert(bstNode<T>* node, T key);
	bstNode<T>* deleteNode(bstNode<T>* node, T key);
	bool search(T data);
	void breadthTraversal(bstNode<T>* node);
	void printCurrentLvl(bstNode<T>* node, int level, int height);
	int getHeight(bstNode<T>* node);
	void print2DUtil(bstNode<T>*, int space);
	void print2D(bstNode<T>* root);
};

template<typename T>
inline bst<T>::bst()
{
	root = nullptr;
}

template<typename T>
inline bst<T>::bst(T data)
{
	root = new bstNode<T>(data);
}

template<typename T>
inline bst<T>::~bst()
{
}

template<typename T>
inline bstNode<T>* bst<T>::insert(bstNode<T>* node, T key)
{
	if (node == NULL) {
		bstNode<T>* n = new bstNode<T>(key);
		return n;
	}
	if (key->getUsrName() < node->getData()->getUsrName()) {
		node->setLeft(insert(node->getLeft(), key));
	}
	else
	{
		node->setRight(insert(node->getRight(), key));
	}
	return node;

}


template<typename T>
inline bstNode<T>*  bst<T>::deleteNode(bstNode<T>* node, T key)
{
	if (node == NULL) {
		return node;
	}
	if (key < node->getData()) {
		node->setLeft(deleteNode(node->getLeft(), key));
		return node;
	}
	else if (key > node->getData()) {
		node->setRight(deleteNode(node->getRight(), key));
		return node;
	}
	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (node->getLeft() == NULL)
		{
			bstNode<T> *temp = node->getRight();
			delete node;
			return temp;
		}
		else if (node->getRight() == NULL)
		{
			bstNode<T> *temp = node->getLeft();
			delete node;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		bstNode<T> *currentNode = node->getRight();
		bstNode<T> *tmp = node->getRight();
		while (currentNode->getLeft() != NULL) {
			tmp = currentNode;
			currentNode = currentNode->getLeft();

		}
		tmp->setLeft(currentNode->getRight());
		// Copy the inorder successor's content to this node 
		node->setRoot(currentNode->getData());

		// Delete the inorder successor 
		delete currentNode;
		return node;
	}
}

template<typename T>
inline bool bst<T>::search(T data)
{
	bstNode<T> *currentNode = root;

	while (currentNode != NULL) {
		if (currentNode->getData() > data) {
			currentNode = currentNode->getLeft();
		}  //else go to right tree
		if (currentNode->getData() < data) {
			currentNode = currentNode->getRight();
		}
		else {
			return true;
		}
	}
	return false;
}

//print out 
template<typename T>
inline void bst<T>::breadthTraversal(bstNode<T>* node) {
	int h = getHeight(node);
	cout << "height" << h << endl;
	int formatSpace;
	for (int i = 1;i <= h;i++) {
		formatSpace = (pow(2, h - 1)*5) / (1+pow(2,i-1));
		//formatSpace = h*2* 15/ (1 + pow(2, i - 1));
		//formatSpace = 10;
		//formatSpace = formatSpace = 10 * h / (i + 2);
		//formatSpace = 15 * h / (1 + pow(2, i - 1));
		//formatSpace = h
		printCurrentLvl(node, i, formatSpace);
		cout << endl;
	}
}

//go to the desired level and print out that level with proper spacing
template<typename T>
inline void bst<T>::printCurrentLvl(bstNode<T>* node, int level, int formatSpace) {
	if (node == NULL) {
		if (level == 1) {
			cout << right << setw(formatSpace) << "";
		}
		else {
			for (int i = level;i > 0;i--) {
				cout << right << setw(formatSpace) << "";
				//cout << right << setw(formatSpace) << "";
			}
		}
		return;
	}
	if (level == 1) {
		string str1 = ((node->getData())->getUsrName()).substr(0, 5);
		cout << right << setw(formatSpace) << str1;
	}
	else if (level > 1) {
		printCurrentLvl(node->getLeft(), level - 1, formatSpace);
		printCurrentLvl(node->getRight(), level - 1, formatSpace);
	}
}


//get the height of the tree
template<typename T>
inline int bst<T>::getHeight(bstNode<T>* node) {
	if (node == NULL)
		return 0;
	
	int lh = getHeight(node->getLeft());
	int rh = getHeight(node->getRight());
	if (lh > rh)
		return (lh + 1);
	return (rh + 1);
}

template<typename T>
void bst<T>::print2DUtil(bstNode<T>* root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->getRight(), space);

	// Print current node after space 
	// count 
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	cout << ((root->getData())->getUsrName()) << "\n";

	// Process left child 
	print2DUtil(root->getLeft(), space);
}

// Wrapper over print2DUtil() 
template<typename T>
void bst<T>::print2D(bstNode<T>* root)
{
	// Pass initial space count as 0 
	print2DUtil(root, 0);
}
