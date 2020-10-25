#pragma once
#include "Node1.h"
template<class T>
class BinarySearchTree
{
public:
	int d = 1;
	Node<T>* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	Node<T>* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	void AddLeaf(T e, Node<T>* node) {
		if (root == NULL)
		{
			root = creat_leaf(e, 0);
		}
		else if (e <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeaf(e, node->left);
			}
			else
			{
				node->left = creat_leaf(e, 0);
			}
		}
		else if (e > node->data)
		{
			if (node->right != NULL)
			{
				AddLeaf(e, node->right);
			}
			else
			{
				node->right = creat_leaf(e, 1);
			}
		}
	}
	void AddLeaf_v(vector<T> v, Node<T>* node) {
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (v[0] <= node->v[0])
		{
			if (node->left != NULL)
			{
				AddLeaf_v(v, node->left);
			}
			else
			{
				node->left = creat_leaf_v(v, 0);
			}
		}
		else if (v[0] > node->v[0])
		{
			if (node->right != NULL)
			{
				AddLeaf_v(v, node->right);
			}
			else
			{
				node->right = creat_leaf_v(v, 1);
			}
		}
	}
	void RemoveNode(Node<T>* p, Node<T>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p->data <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true, a) :
						RemoveNode(p, parent->left, a);
				}
				else if (p->data > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false, a) :
						RemoveNode(p, parent->right, a);
				}
			}
		}
	}
	void RemoveNode_vect(Node<T>* p, Node<T>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p->v[0] <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch_vect(parent, parent->left, true, a) :
						RemoveNode_vect(p, parent->left, a);
				}
				else if (p->v[0] > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch_vect(parent, parent->right, false, a) :
						RemoveNode_vect(p, parent->right, a);
				}
			}
		}
	}
private:
	Node<T>* creat_leaf(T e, bool way1) {
		Node<T>* cur = new Node<T>;
		cur->data = e;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
	Node<T>* creat_leaf_v(vector<T> vv, bool way1) {
		Node<T>* cur = new Node<T>;
		cur->v = vv;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
	Node<T>* Find_smallestPrivate(Node<T>* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	void RemoveRoot(int a) {
		Node<T>* delPtr = root;
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;

		}
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;

		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;

		}
		else
		{
			Node<T>* p = Find_smallest();
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	void RemoveMatch(Node<T>* parent, Node<T>* match, bool left, int a) {

		if (match->left == NULL && match->right == NULL)
		{
			left == true ? parent->left = NULL : parent->right = NULL;
		}
		else if (match->left == NULL && match->right != NULL && a == 1)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
		}
		else if (match->left != NULL && match->right == NULL && a == 1)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
		}
		else if (a == 2)
		{
			if (parent->left == match) { parent->left = NULL; }
			else(parent->right = NULL);
		}
		else
		{
			Node<T>* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data = p->data;
		}
	}
	void RemoveRoot_vect(int a) {
		Node<T>* delPtr = root;
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;

		}
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;

		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;

		}
		else
		{
			Node<T>* p = Find_smallest();
			RemoveNode_vect(p, root);
			root->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				root->v[i] = p->v[i];
			}
		}
	}
	void RemoveMatch_vect(Node<T>* parent, Node<T>* match, bool left, int a) {

		if (match->left == NULL && match->right == NULL)
		{
			left == true ? parent->left = NULL : parent->right = NULL;
		}
		else if (match->left == NULL && match->right != NULL && a == 1)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
		}
		else if (match->left != NULL && match->right == NULL && a == 1)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
		}
		else if (a == 2) {
			if (parent->left == match) { parent->left = NULL; }
			else(parent->right = NULL);
		}
		else
		{
			Node<T>* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				match->v[i] = p->v[i];
			}
		}
	}
};