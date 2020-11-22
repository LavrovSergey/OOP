#pragma once
/*! @param T -data type
* @param U -object.*/
template< class U>
/*! Template node class.*/
class Node {
public:
	U* data;
	Node< U>* left;
	Node<U>* right;
	Node() : data(nullptr), left(nullptr),right(nullptr) {}
};