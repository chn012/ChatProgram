#pragma once
#include <iostream>
using namespace std;

template<typename K, typename V>

class hashNode {
protected:
	K key;
	V value;
	hashNode<K, V>* next;
public:

	hashNode(K key, V value);
	K getKey();
	V getValue();
	hashNode<K, V>* getNext();
	void setKey(K k);
	void setValue(V v);
	void setNext(hashNode<K, V>* h);



};

template<typename K, typename V>
hashNode<K, V>::hashNode(K k, V v) {
	key = k;
	value = v;
}

template<typename K, typename V>
K hashNode<K, V>::getKey() {
	return key;
}
template<typename K, typename V>
V hashNode<K, V>::getValue() {
	return value;
}
template<typename K, typename V>
hashNode<K, V>* hashNode<K, V>::getNext() {
	return next;
}
template<typename K, typename V>
void hashNode<K, V>::setKey(K keys) {
	key = keys;
}
template<typename K, typename V>
void hashNode<K, V>::setValue(V values) {
	value = values;
}
template<typename K, typename V>
void hashNode<K, V>::setNext(hashNode<K, V>* h) {
	next = h;
}
