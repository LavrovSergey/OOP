#pragma once
template<class T, class U> class BinarySearchTree;
template<class T, class U> class BinaryTree;
template<class T, class U> class NarrayTree;
/*! @param T -data type
* @param U -object.*/
template< class T, class U>
/*! Template node class.*/
class Node {
	friend class BinarySearchTree<T, Node<T, U>>;
	friend class BinaryTree<T, Node<T, U>>;
	friend class NarrayTree<T, Node<T, U>>;
public:
	U* data;
	Node<T, U>* left = NULL;
	Node<T, U>* right = NULL;
};