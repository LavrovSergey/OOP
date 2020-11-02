#pragma once
#include "Node1.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary search tree*/
class BinarySearchTree
{
public:
	int d = 1;
	U* root;
	/*! Constructer. Root = 0..*/
	BinarySearchTree()
	{
		root = NULL;
	}
	/*! Find the smallest value of the tree to rebuild after deletion.*/
	U* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	/*!Creating a Node.*/
	void creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data = e;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		AddLeaf(cur, root);
	};
	/*! Adding a Node.*/
	void AddLeaf(U* cur, U* node) {
		if (root == NULL)
		{
			root = cur;
		}
		else if (cur->data <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeaf(cur, node->left);
			}
			else
			{
				node->left = cur;
				cur->way = 0;
			}
		}
		else if (cur->data > node->data)
		{
			if (node->right != NULL)
			{
				AddLeaf(cur, node->right);
			}
			else
			{
				node->right = cur;
				cur->way = 1;
			}
		}
	}
	/*! Ствоюємо вузол для вектора.*/
	void creat_leaf_v(std::vector<T> vv, bool way1) {
		U* cur = new U;
		cur->v = vv;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		AddLeaf_v(cur, root);
	};
	/*! Deleting the Node.*/
	void RemoveNode(U* p, U* parent, int a)
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
	/*! Видалення вузла вектора.*/
	void RemoveNode_vect(U* p, U* parent, int a)
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

	void AddLeaf_v(U* cur, U* node) {
		if (root == NULL)
		{
			root = cur;
		}
		else if (cur->v[0] <= node->v[0])
		{
			if (node->left != NULL)
			{
				AddLeaf_v(cur, node->left);
			}
			else
			{
				node->left = cur;
				cur->way = 0;
			}
		}
		else if (cur->v[0] > node->v[0])
		{
			if (node->right != NULL)
			{
				AddLeaf_v(cur, node->right);
			}
			else
			{
				node->right = cur;
				cur->way = 1;
			}
		}
	}
	U* Find_smallestPrivate(U* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	/*! Deleting the root.*/
	void RemoveRoot(int a) {
		U* delPtr = root;
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
			U* p = Find_smallest();
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	/*! Delete the node that was found before.*/
	void RemoveMatch(U* parent, U* match, bool left, int a) {

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
			U* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data = p->data;
		}
	}
	void RemoveRoot_vect(int a) {
		U* delPtr = root;
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
			U* p = Find_smallest();
			RemoveNode_vect(p, root);
			root->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				root->v[i] = p->v[i];
			}
		}
	}
	void RemoveMatch_vect(U* parent, U* match, bool left, int a) {

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
			U* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				match->v[i] = p->v[i];
			}
		}
	}
};