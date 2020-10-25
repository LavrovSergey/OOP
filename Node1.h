##pragma once
#include <vector>
template<class T>
class Node {
	friend class BinarySearchTree<T>;
	friend class BinaryTree<T>;
	friend class TreeChildrenList<T>;
protected:
	Node<T>* left;
	Node<T>* right;
	T data;
	vector<T> v;
	int id = 0;
	bool way;
};