#pragma once
#include <vector>
template<class T, class U> class BinarySearchTree;
template<class T, class U> class BinaryTree;
template<class T, class U> class TreeChildrenList;

template<class T>
class Node {
	friend class BinarySearchTree<T, Node<T>>;
	friend class BinaryTree<T, Node<T>>;
	friend class TreeChildrenList<T, Node<T>>;
public:
	Node<T>* left;
	Node<T>* right;
	T data;
	std::vector<T> v;
	int id = 0;
	bool way; 
};