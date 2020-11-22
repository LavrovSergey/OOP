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
	/*! Designer. Root = 0.*/
	BinaryTree()
	{
		root = NULL;
	}
	Node<U>* GetRoot() {
		return root;
	}
	void SetRoot(Node<U>* node) {
		root=node;
	}
	/*Part1* Find_max() {
		return Find_maxPrivate(root);
	}*/
	/*! Add a node to the tree.
	*We check the tree for fullness 
	*and write down where it is empty
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
	Node<U>* AddLeaf_v(Node<U>* root, U* node) {
		if (root == NULL) {
			Node<U>* cur = new Node<U>;
			cur->data = node;
			return cur;
		}
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
	}
	/*Part1* Find_maxPrivate(Part1* node) {
		if (node == NULL) { return 0; }
		Part1* tmp = Find_maxPrivate(node->left);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		tmp = Find_maxPrivate(node->right);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		return node;
	}*/
	/*! Deleting a node.*/
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
				if (p == parent->left ) {
					RemoveMatch(parent, parent->left, true, a);
				}
				else if( parent->left != NULL) {RemoveNode(p, parent->left, a);}
				if (p == parent->right  ) {
						RemoveMatch(parent, parent->right, false, a);
					}
				else if(parent->right != NULL){ RemoveNode(p, parent->right, a); }
			}
		}
	}
	/*! Creating a node.*/
	U* creat_leaf_v(std::vector<T> v, bool way) {
		U* cur = new U(v, d++, way);
		/*cur->v = vv;
		cur->way = way1;
		cur->id = d++;*/
		return cur;
	};
	/*! Creating a node.*/
	U* creat_leaf(T e, bool way) {
		U* cur = new U(e, d++, way);
		/*cur->data = e;
		cur->way = way1;
		cur->id = d++;*/
		return cur;
	};
private:
	/*! Check the balance of the tree.*/
	int bal(Node<U>* root) {
		if (root == NULL) { return 0; }
		int lheight = height(root->left) + 1;
		int rheight = height(root->right) + 1;
		return(lheight - rheight);
	}
	/*! Check the height of the tree.*/
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
	/*!Check free space.*/
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
	Node<U>* FindSmallestPrivate(Node< U>* node)
	{
		if (node->left != NULL)
		{
			return FindSmallestPrivate(node->left);
		}
		else { return node; };
	}
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