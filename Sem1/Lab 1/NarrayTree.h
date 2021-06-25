#pragma once
#include "Part1.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template <class T, class U>
/*! Tree class with any number of children based on the list.*/
class NarrayTree {
public:
	/*id for part1*/
	int d = 0;
	/*! Conctructer. Root = 0.*/
	NarrayTree()
	{
		root = NULL;
	}
	/**
	* Get a root of tree
	* @return root
	*/
	Node<U>* GetRoot() {
		return root;
	}
	/*! Adding a Node.
	*We add more to the right.
    *If more than the previous one and less than the next,
	*then add the next one as a child
	*  @param object
	* @param node for traveling
	* @return root
	*/
	void AddLeaf(T inf, Node<U>* node) {
		bool c = false;
		if (root == NULL)
		{
			root = new Node<U>;
			root->data = creat_leaf(inf, 0);
		}
		else if (node->left)
		{
			if (inf > node->left->data->GetData(0)) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data->GetData(0) > inf) {
						if (node->left) { AddLeaf(inf, node); c = true; }
						else {
							node->left = new Node<U>;
							node->left->data = creat_leaf(inf, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right = new Node<U>; node->right->data = creat_leaf(inf, 1); }
			}
			else {
				node->left->left = new Node<U>;
				node->left->left->data = creat_leaf(inf, 0);
			}
		}
		else { node->left = new Node<U>; node->left->data = creat_leaf(inf, 0); }
	}
	/*! Adding a Node.
	*We add more to the right.
	*If more than the previous one and less than the next,
	*then add the next one as a child
	*  @param object
	* @param node for traveling
	* @return root
	*/
	void AddLeaf_v(std::vector<T> v, Node< U>* node) {
		bool c = false;
		if (root == NULL)
		{
			root = new Node<U>;
			root->data = creat_leaf_v(v, 0);
		}
		else if (node->left)
		{
			if (v[0] > node->left->data->GetVector(0)) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data->GetVector(0) > v[0]) {
						if (node->left) { AddLeaf_v(v, node); c = true; }
						else {
							node->left = new Node<U>;
							node->left->data = creat_leaf_v(v, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right = new Node<U>; node->right->data = creat_leaf_v(v, 1); }
			}
			else {
				node->left->left = new Node<U>;
				node->left->left->data = creat_leaf_v(v, 0);
			}
		}
		else { node->left = new Node<U>; node->left->data = creat_leaf_v(v, 0); }
	}
	/*! Search a position of node we want to delete.
	* @param node to delete
	* @param node that hane to be parent of node we want to delete
	* @param 1-delete node, 2-delete node and all under it
	*/
	void RemoveNode(Node< U>* p, Node< U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else if (root != p && parent->left != p && parent->right != p)
			{
				if (parent->left)
				{
					if (p->data->GetData(0) <= parent->left->data->GetData(0))
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data->GetData(0) > parent->left->data->GetData(0))
					{
						if (parent == root) { RemoveNode(p, parent->left->right, a); }
						else(RemoveNode(p, parent->right, a));
					}
				}
				else(RemoveNode(p, parent->right, a));
			}
			if (parent->left == p) {
				RemoveMatch(parent, parent->left, a);
			}
			else if (parent->right == p) {
				RemoveMatch(parent, parent->right, a);
			}
		}
	}
	/*! Search a position of node we want to delete.
	* @param node to delete
	* @param node that hane to be parent of node we want to delete
	* @param 1-delete node, 2-delete node and all under it
	*/
	void RemoveNode_vect(Node< U>* p, Node< U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else if (root != p && parent->left != p && parent->right != p)
			{
				if (parent->left)
				{
					if (p->data->GetVector(0) <= parent->left->data->GetVector(0))
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data->GetVector(0) > parent->left->data->GetVector(0))
					{
						if (parent == root) { RemoveNode(p, parent->left->right, a); }
						else(RemoveNode(p, parent->right, a));
					}
				}
				else(RemoveNode(p, parent->right, a));
			}
			if (parent->left == p) {
				RemoveMatch(parent, parent->left, a);
			}
			else if (parent->right == p) {
				RemoveMatch(parent, parent->right, a);
			}
		}
	}
private:
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object
	*/
	U* creat_leaf(T e, bool way) {
		U* cur = new U(e, d++, way);
		return cur;
	};
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object
	*/
	U* creat_leaf_v(std::vector<T> v, bool way) {
		U* cur = new U( v, d++, way);
		return cur;
	};
	/*! Creating a odject of part1.
	* @param parent of node we want to delete
	* @param node that we delete
	* @param how to delete
	*/
	void RemoveMatch(Node<U>* parent, Node< U>* match, int a) {
		if (parent == root)
		{
			if (a == 1) {
				if (match->left) {
					parent->left = match->left;
					match->left->right = match->right;
				}
				else {
					parent->left = match->right;
				}
			}
			else {
				parent->left = match->right;
			}
		}
		else if (parent->right == match)
		{
			if (a == 1) {
				if (match->left) {
					parent->right = match->left;
					while (parent->right)
					{
						parent = parent->right;
					}
					parent->right = match->right;
				}
				else {
					parent->right = match->right;
				}
			}
			else {
				parent->right = match->right;
			}
		}
		else if (parent->left == match)
		{
			if (a == 1) {
				if (match->right)
				{
					parent->left = match->right;
					while (parent->left) {
						parent = parent->left;
					}
					parent->left = match->left;
				}
				else {
					parent->left = match->left;
				}
			}
			else { parent->left = match->right; }
		}
	}
	/*! Deleting of root
	* @param how to remove
	*/
	void RemoveRoot(int a) {
		Node<U>* node;
		if (root->left == NULL)
		{
			root = NULL;
		}
		else if (root->left != NULL && root->left->left != NULL)
		{
			node = root->left->left;
			root = root->left;
			while (node->right)
			{
				node = node->right;
			}
			node->right = root->right;
			root->right = NULL;
		}
		else if (root->left != NULL && root->left->left == NULL)
		{
			root = root->left;
			root->left = root->right;
			root->right = NULL;
		}
	}
	Node<U>* root;
};