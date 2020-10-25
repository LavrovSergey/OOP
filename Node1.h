#pragma once
#include <vector>
template<class T> class BinarySearchTree;
template<class T> class BinaryTree;
template<class T> class TreeChildrenList;

template<class T>
class Node {
	friend class BinarySearchTree<T>;
	friend class BinaryTree<T>;
	friend class TreeChildrenList<T>;
public:
	Node<T>* left;
	Node<T>* right;
	T data;
	std::vector<T> v;
	int id = 0;
	bool way;
};