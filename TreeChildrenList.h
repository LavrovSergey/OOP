#pragma once
#include "Node1.h"
/*! @param T -data type
* @param U -object.*/
template <class T, class U>
/*! Tree class with any number of children based on the list.*/
class TreeChildrenList {
public:
	int d = 0;
	U* root;
	TreeChildrenList()
	{
		root = NULL;
	}
	/*! Adding a Node.*/
	void AddLeaf(T e, U* node) {
		bool c = false;
		if (root == NULL)
		{
			root = creat_leaf(e, 0); 
		}
		else if (node->left)
		{
			if (e > node->left->data) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data > e) {
						if (node->left) { AddLeaf(e, node); c = true; }
						else {
							node->left = creat_leaf(e, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right = creat_leaf(e, 1); }
			}
			else {
				node->left->left = creat_leaf(e, 0);
			}
		}
		else(node->left = creat_leaf(e, 0));
	}
	void AddLeaf_v(std::vector<T> v, U* node) {
		bool c = false;
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (node->left)
		{
			if (v[0] > node->left->data) {
				node = node->left;
				while (node->right)
				{
					node = node->right;
					if (node->data > v[0]) {
						if (node->left) { AddLeaf_v(v, node); c = true; }
						else {
							node->left = creat_leaf_v(v, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->right = creat_leaf_v(v, 1); }
			}
			else {
				node->left->left = creat_leaf_v(v, 0);
			}
		}
		else(node->left = creat_leaf_v(v, 0));
	}
	/*! Deleting the Node.*/
	void RemoveNode(U* p, U* parent, int a)
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
					if (p->data <= parent->left->data)
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data > parent->left->data)
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
	void RemoveNode_vect(U* p, U* parent, int a)
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
					if (p->data <= parent->left->data)
					{
						RemoveNode(p, parent->left, a);
					}
					else if (p->data > parent->left->data)
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
	U* creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data = e;
		cur->way = way1;
		cur->right = NULL;
		cur->left = NULL;
		cur->id = d++;
		return cur;
	};
	U* creat_leaf_v(std::vector<T> v, bool way1) {
		U* cur = new U;
		cur->v = v;
		cur->way = way1;
		cur->right = NULL;
		cur->left = NULL;
		cur->id = d++;
		return cur;
	};
	/*! Delete the node that was found before.*/
	void RemoveMatch(U* parent, U* match, int a) {
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
	/*! Deleting the root.*/
	void RemoveRoot(int a) {
		U* node;
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