#pragma once
#include "Part1.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary tree*/
class BinaryTree {
public:
	/*id for part1*/
	int d = 1;
	/*! Conctructer. Root = 0.*/
	BinaryTree()
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
	/**
	*Root of tree(it`a not a new root. We just need it to build tree)
	* @param pointer to node of new root
	*/
	void SetRoot(Node<U>* node) {
		root = node;
	}
	/*! Add a node to the tree.
	*We check the tree for fullness
	*and write down where it is empty
	* @param root of tree
	* @param node that we add to tree
	* @return root
	*/
	Node<U>* AddLeaf(Node<U>* root, U* node) {
		if (root == NULL) {
			Node<U>* cur = new Node<U>;
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
	/*! Search a position of node we want to delete.
	* @param node to delete
	* @param node that hane to be parent of node we want to delete
	* @param 1-delete node, 2-delete node and all under it 
	*/
	void RemoveNode(Node<U>* p, Node<U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p == parent->left) {
					RemoveMatch(parent, parent->left, true, a);
				}
				else if (parent->left != NULL) { RemoveNode(p, parent->left, a); }
				if (p == parent->right) {
					RemoveMatch(parent, parent->right, false, a);
				}
				else if (parent->right != NULL) { RemoveNode(p, parent->right, a); }
			}
		}
	}
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object 
	*/
	U* creat_leaf_v(std::vector<T> v, bool way) {
		U* cur = new U(v, d++, way);
		return cur;
	};
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object
	*/
	U* creat_leaf(T e, bool way) {
		U* cur = new U(e, d++, way);
		return cur;
	};
private:
	/*! Check the balance of the tree.
	* @param root of tree
	* @return height difference
	*/
	int bal(Node<U>* root) {
		if (root == NULL) { return 0; }
		int lheight = height(root->left) + 1;
		int rheight = height(root->right) + 1;
		return(lheight - rheight);
	}
	/*! Check the height of the tree.
	* @param root
	* @return height of the heighest subtree
	*/
	int height(Node<U>* root) {
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
	/*!Check free space.
	* @param root
	* @return where is free space
	*/
	bool check(Node<U>* root) {
		if (root == NULL) { return false; }
		bool x = check(root->left);
		if (bal(root))
		{
			return true;
		}
		bool y = check(root->right);
		return x || y;
	}
	/*! Find the smallest in right subtree to rebuild tree
	* @param root->right
	* @return the smallest node
	*/
	Node<U>* FindSmallestPrivate(Node< U>* node)
	{
		if (node->left != NULL)
		{
			return FindSmallestPrivate(node->left);
		}
		else { return node; };
	}
	/*! Deleting of root
	* @param how to remove
	*/
	void RemoveRoot(int a) {
		Node<U>* delPtr = root;
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete delPtr;
		}
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;

		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
		}
		else
		{
			Node<U>* p = FindSmallestPrivate(root->right);
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	/*! Creating a odject of part1.
	* @param parent of node we want to delete
	* @param node that we delete
	* @param if we have left node
	* @param how to delete
	* @return object
	*/
	void RemoveMatch(Node<U>* parent, Node<U>* match, bool left, int a) {
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
			Node<U>* p = FindSmallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data = p->data;
		}
	}
	Node<U>* root;
};