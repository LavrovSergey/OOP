#pragma once
#include "Part1.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template <class T, class U>
/*! Tree class with any number of children based on the list.*/
class NarrayTree {
public:
	int d = 0;
	Node<T, U>* root ;
	NarrayTree()
	{
		root = NULL;
	}
	/*! Adding a Node.
	*We add more to the right.
    *If more than the previous one and less than the next,
	*then add the next one as a child
	*/
	void AddLeaf(T inf, Node<T, U>* node) {
		bool c = false;
		if (root == NULL)
		{
			root->data = creat_leaf(inf, 0);
		}
		else if (node->left)
		{
			if (inf > node->left->data->data) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data->data > inf) {
						if (node->left) { AddLeaf(inf, node); c = true; }
						else {
							node->left->data = creat_leaf(inf, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right->data = creat_leaf(inf, 1); }
			}
			else {
				node->left->left->data = creat_leaf(inf, 0);
			}
		}
		else(node->left->data = creat_leaf(inf, 0));
	}
	/*! Adding a Node.
	*We add more to the right.
	*If more than the previous one and less than the next,
	*then add the next one as a child
	*/
	void AddLeaf_v(std::vector<T> v, Node<T, U>* node) {
		bool c = false;
		if (root == NULL)
		{
			root = new Node<T, U>;
			root->data = creat_leaf_v(v, 0);
		}
		else if (node->left)
		{
			if (v[0] > node->left->data->v[0]) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data->v[0] > v[0]) {
						if (node->left) { AddLeaf_v(v, node); c = true; }
						else {
							node->left->data = creat_leaf_v(v, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right->data = creat_leaf_v(v, 1); }
			}
			else {
				node->left->left->data = creat_leaf_v(v, 0);
			}
		}
		else(node->left->data = creat_leaf_v(v, 0));
	}
	/*! Deleting the Node.
	*We are looking for the node 
	*that we will delete, and its parent
	*/
	void RemoveNode(Node<T, U>* p, Node<T, U>* parent, int a)
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
					if (p->data->data <= parent->left->data->data)
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data->data > parent->left->data->data)
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
	/*! Deleting the Node.
	*We are looking for the node
	*that we will delete, and its parent
	*/
	void RemoveNode_vect(Node<T, U>* p, Node<T, U>* parent, int a)
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
					if (p->data->v[0] <= parent->left->data->v[0])
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data->v[0] > parent->left->data->v[0])
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
	/*!Creating a Node.*/
	Node<T, U>* creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data = e;
		cur->way = way1;
		cur->id = d++;
		return cur;
	};
	/*!Creating a Node.*/
	Node<T, U>* creat_leaf_v(std::vector<T> v, bool way1) {
		U* cur = new U;
		cur->v = v;
		cur->way = way1;
		cur->id = d++;
		return cur;
	};
	/*! Delete the node that was found before.
	* à==1 Delete Node
	* else - Delete by parent
	*/
	void RemoveMatch(Node<T, U>* parent, Node<T, U>* match, int a) {
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
	/*! Delete the root*/
	void RemoveRoot(int a) {
		Node<T, U>* node;
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
};