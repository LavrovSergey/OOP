#pragma once
#include "Node1.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary tree*/
class BinaryTree {
public:
	int d = 1;
	U* root;
	/*! Designer. Root = 0.*/
	BinaryTree()
	{
		root = NULL;
	}
	/*Node* Find_max() {
		return Find_maxPrivate(root);
	}*/
	/*! Find the smallest value of the tree to rebuild after deletion.*/
	U* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	/*! Add a node to the tree.*/
	U* AddLeaf(U* root, U* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) { root->right = AddLeaf(root->right, node); root->right->way = 1; }
		else if (bal(root) == 0) { root->left = AddLeaf(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1 && check(root->left)) { root->left = AddLeaf(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1) { root->right = AddLeaf(root->right, node); root->right->way = 1; }
		return root;
	}
	U* AddLeaf_v(U* root, U* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) {
			root->right = AddLeaf_v(root->right, node);
			root->right->way = 1;
		}
		else if (bal(root) == 0) {
			root->left = AddLeaf_v(root->left, node);
			root->left->way = 0;
		}
		else if (bal(root) == 1 && check(root->left)) {
			root->left = AddLeaf_v(root->left, node);
			root->left->way = 0;
		}
		else if (bal(root) == 1) {
			root->right = AddLeaf_v(root->right, node);
			root->right->way = 1;
		}
		return root;
	}
	/*Node* Find_maxPrivate(Node* node) {
		if (node == NULL) { return 0; }
		Node* tmp = Find_maxPrivate(node->left);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		tmp = Find_maxPrivate(node->right);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		return node;
	}*/
	/*! Deleting a node.*/
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
	U* creat_leaf_v(std::vector<T> v, bool way1) {
		U* cur = new Node<T>;
		for (int i = 0; i < v.size(); i++) { cur->v[i] = v[i]; }
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
	/*! Creating a node.*/
	U* creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data = e;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
private:
	/*! Check the balance of the tree.*/
	int bal(U* root) {
		if (root == NULL) { return 0; }
		int lheight = height(root->left) + 1;
		int rheight = height(root->right) + 1;
		return(lheight - rheight);
	}
	/*! Check the height of the tree.*/
	int height(U* root) {
		if (root == NULL)
		{
			return 0;
		}
		else {
			int lheight = height(root->left) + 1;
			int rheight = height(root->right) + 1;

			return(lheight > rheight) ? lheight : rheight;
		}
	}
	bool check(U* root) {
		if (root == NULL) { return false; }
		bool x = check(root->left);
		if (bal(root))
		{
			return true;
		}
		bool y = check(root->right);
		return x || y;
	}
	U* Find_smallestPrivate(U* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	void RemoveRoot_vect() {
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
				match->v[i]=p->v[i];
			}
		}
	}
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
};