#pragma once
#include "hashNode.h"

#include <functional>
template<typename K, typename V>
class hashtable
{
private:
	hashNode<K, V>** bucketList;
	int numBuckets;
	int sizes;
	size_t hashCode(K key);
	int getBucketIndex(K key);

public:

	hashtable();
	int size();
	bool isEmpty();
	void remove(K key);
	void add(K key, V value);
	bool hasKey(K key);
	V get(K key);
};

template<typename K, typename V>
inline hashtable<K, V>::hashtable()
{
	bucketList = new hashNode<K, V>*[10];
	numBuckets = 10;
	sizes = 0;

	for (int i = 0; i < numBuckets; i++) {
		bucketList[i] = nullptr;
	}
}

template<typename K, typename V>
int hashtable<K, V>::size()
{
	return sizes;
}

template<typename K, typename V>
bool hashtable<K, V>::isEmpty()
{
	return size() == 0;
}

template<typename K, typename V>
size_t hashtable<K, V>::hashCode(K key) {
	hash<K> hash1;

	return hash1(key);
}
template<typename K, typename V>
int hashtable<K, V>::getBucketIndex(K key)
{
	size_t hashV = hashCode(key);
	int index = (int)(hashV % numBuckets);

	return index;
}

template<typename K, typename V>
void hashtable<K, V>::remove(K key)
{
	int bucketIndex = getBucketIndex(key);

	hashNode<K, V>* head = bucketList[bucketIndex];
	hashNode<K, V>* prev = nullptr;
	while (head) {
		if (head->getKey() == key) {
			break;
		}
		prev = head;
		head = head->getNext();
	}

	if (!head) {
		return;
	}

	sizes--;

	if (prev) {
		prev->setNext(head->getNext());
	}
	else {
		bucketList[bucketIndex] = head->getNext();
	}

}

template<typename K, typename V>
void hashtable<K, V>::add(K key, V value) {
	int bucketIndex = getBucketIndex(key);
	hashNode<K, V>* head = bucketList[bucketIndex];


	while (head != nullptr) {
		if (head->getKey() == key) {
			head->setValue(value);
			return;
		}
		head = head->getNext();
	}

	sizes++;
	head = bucketList[bucketIndex];
	hashNode<K, V>* newNode = new hashNode<K, V>(key, value);
	newNode->setNext(head);
	bucketList[bucketIndex] = newNode;

	if ((1.0*sizes) / numBuckets >= 0.7) {
		hashNode<K, V>** tmp = bucketList;
		bucketList = new hashNode<K, V>*[2 * numBuckets];
		numBuckets = 2 * numBuckets;
		sizes = 0;
		for (int i = 0; i < numBuckets; i++)
		{
			bucketList[i] = nullptr;
		}

		for (int i = 0; i < numBuckets / 2; i++) {
			hashNode<K, V>* headNode = tmp[i];
			while (headNode) {
				add(headNode->getKey(), headNode->getValue());
				headNode = headNode->getNext();
			}
		}
	}
}
template<typename K, typename V>
bool hashtable<K, V>::hasKey(K key)
{
	int bucketIndex = getBucketIndex(key);
	hashNode<K, V>* head = bucketList[bucketIndex];

	while (head) {
		if (head->getKey() == key) {
			return true;
		}
		head = head->getNext();
	}
	return false;
}

template<typename K, typename V>
V hashtable<K, V>::get(K key) {
	int bucketIndex = getBucketIndex(key);

	hashNode<K, V>* head = bucketList[bucketIndex];

	while (head) {
		if (head->getKey() == key) {
			return head->getValue();
		}
		head = head->getNext();
	}

	try {
		if (!head) {
			throw "cannot find the key";
		}
		return head->getValue();
	}
	catch (const char*  err) {
		cout << err << endl;
	}

}
