#pragma once
#include "Part1.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary tree*/
class BinaryTree {
public:
	int d = 1;
	Node<T, U>* root;
	/*! Designer. Root = 0.*/
	BinaryTree()
	{
		root = NULL;
	}
	/*Part1* Find_max() {
		return Find_maxPrivate(root);
	}*/
	/*! Find the smallest value of the tree to rebuild after deletion.*/
	Node<T, U>* Find_smallest()
	{
		return Find_smallestPrivate(root->right);
	}
	/*! Add a node to the tree.
	*We check the tree for fullness 
	*and write down where it is empty
	*/
	Node<T, U>* AddLeaf(Node<T, U>* root, U* node) {
		if (root == NULL) {
			Node<T, U>* cur = new Node<T, U>;
			cur->data = node;
			return cur;
		}
		else if (bal(root) == 0 && check(root->right)) {
			root->right = AddLeaf(root->right, node);
			root->right->data->way = 1;
		}
		else if (bal(root) == 0) {
			root->left = AddLeaf(root->left, node);
			root->left->data->way = 0;
		}
		else if (bal(root) == 1 && check(root->left)) {
			root->left = AddLeaf(root->left, node);
			root->left->data->way = 0;
		}
		else if (bal(root) == 1) {
			root->right = AddLeaf(root->right, node);
			root->right->data->way = 1;
		}
		return root;
	}
	/*Node<T, U>* AddLeaf_v(Node<T, U>* root, Node<T, U>* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) {
			root->right = AddLeaf_v(root->right, node);
			root->right->data->way = 1;
		}
		else if (bal(root) == 0) {
			root->left = AddLeaf_v(root->left, node);
			root->left->data->way = 0;
		}
		else if (bal(root) == 1 && check(root->left)) {
			root->left = AddLeaf_v(root->left, node);
			root->left->data->way = 0;
		}
		else if (bal(root) == 1) {
			root->right = AddLeaf_v(root->right, node);
			root->right->data->way = 1;
		}
		return root;
	}*/
	/*Part1* Find_maxPrivate(Part1* node) {
		if (node == NULL) { return 0; }
		Part1* tmp = Find_maxPrivate(node->left);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		tmp = Find_maxPrivate(node->right);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		return node;
	}*/
	/*! Deleting a node.*/
	void RemoveNode(Node<T, U>* p, Node<T, U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p->data->data <= parent->data->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true, a) :
						RemoveNode(p, parent->left, a);
				}
				else if (p->data->data > parent->data->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false, a) :
						RemoveNode(p, parent->right, a);
				}
			}
		}
	}
	void RemoveNode_vect(Node<T, U>* p, Node<T, U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p->data->v[0] <= parent->data->v[0] && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch_vect(parent, parent->left, true, a) :
						RemoveNode_vect(p, parent->left, a);
				}
				else if (p->data->v[0] > parent->data->v[0] && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch_vect(parent, parent->right, false, a) :
						RemoveNode_vect(p, parent->right, a);
				}
			}
		}
	}
	/*! Creating a node.*/
	U* creat_leaf_v(std::vector<T> v, bool way1) {
		U* cur = new Part1<T>;
		for (int i = 0; i < v.size(); i++) { cur->v[i] = v[i]; }
		cur->way = way1;
		cur->id = d++;
		return cur;
	};
	/*! Creating a node.*/
	U* creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data = e;
		cur->way = way1;
		cur->id = d++;
		return cur;
	};
private:
	/*! Check the balance of the tree.*/
	int bal(Node<T, U>* root) {
		if (root == NULL) { return 0; }
		int lheight = height(root->left) + 1;
		int rheight = height(root->right) + 1;
		return(lheight - rheight);
	}
	/*! Check the height of the tree.*/
	int height(Node<T, U>* root) {
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
	bool check(Node<T, U>* root) {
		if (root == NULL) { return false; }
		bool x = check(root->left);
		if (bal(root))
		{
			return true;
		}
		bool y = check(root->right);
		return x || y;
	}
	Node<T, U>* Find_smallestPrivate(Node<T, U>* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	void RemoveRoot_vect() {
		Node<T, U>* delPtr = root;
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
			Node<T, U>* p = Find_smallest();
			RemoveNode_vect(p, root);
			root->data->v.resize(p->data->v.size());
			for (int i = 0; i < root->data->v.size(); i++) {
				root->data->v[i] = p->data->v[i];
			}
		}
	}
	void RemoveMatch_vect(Node<T, U>* parent, Node<T, U>* match, bool left, int a) {
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
			if (root = match) { root = NULL; }
			else if (parent->left == match) { parent->left = NULL; }
			else(parent->right = NULL);
		}
		else
		{
			Node<T, U>* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data->v.resize(p->data->v.size());
			for (int i = 0; i < root->data->v.size(); i++) {
				match->data->v[i] = p->data->v[i];
			}
		}
	}
	void RemoveRoot(int a) {
		Node<T, U>* delPtr = root;
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
			Node<T, U>* p = Find_smallest();
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	void RemoveMatch(Node<T, U>* parent, Node<T, U>* match, bool left, int a) {
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
			if (root = match) { root = NULL; }
			else if (parent->left == match) { parent->left = NULL; }
			else(parent->right = NULL);
		}
		else
		{
			Node<T, U>* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data->data = p->data->data;
		}
	}
};