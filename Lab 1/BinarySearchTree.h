#pragma once
#include "Part1.h"
#include "Book.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary search tree*/
class BinarySearchTree
{
public:
	/*id for part1*/
	int d = 1;
	/*! Constructer. Root = 0.*/
	BinarySearchTree()
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
	void SetRoot() {
		root=NULL;
	}
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object
	*/
	void creat_leaf(T e, bool way) {
		U* cur = new U(e, d++, way);
		AddLeaf(cur, root);
	};
	/*! Add a node for series of books to the tree.
	* @param root of tree
	* @param node that we add to tree
	*/
	void AddLeafDate(U* cur, Node<U>* node) {
		if (root == NULL)
		{
			root = new Node<U>;
			root->data = cur;
		}
		else if (cur->GetData(0) <= node->data->GetData(0))
		{
			if (node->left != NULL)
			{
				AddLeaf(cur, node->left);
			}
			else
			{
				node->left = new Node<U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->GetData(0) > node->data->GetData(0))
		{
			if (node->right != NULL)
			{
				AddLeaf(cur, node->right);
			}
			else
			{
				node->right = new Node<U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}


	}
	/*! Add a node to the tree.
	* @param root of tree
	* @param node that we add to tree
	*/
	void AddLeaf(U* cur, Node<U>* node) {
		if (root == NULL)
		{
			root = new Node<U>;
			root->data = cur;
		}
		else if (cur->GetData(0) <= node->data->GetData(0))
		{
			if (node->left != NULL)
			{
				AddLeaf(cur, node->left);
			}
			else
			{
				node->left = new Node<U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->GetData(0) > node->data->GetData(0))
		{
			if (node->right != NULL)
			{
				AddLeaf(cur, node->right);
			}
			else
			{
				node->right = new Node<U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}
	}
	/*! Creating a odject of part1.
	* @param vector
	* @param way shows where our node(left or right from parent)
	* @return object
	*/
	void creat_leaf_v(std::vector<T> v, bool way) {
		U* cur = new U(v, d++, way);
		/*cur->v = vv;
		cur->way = way1;
		cur->id = d++;*/
		AddLeaf_v(cur, root);
	};
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
				if (p->data->GetData(0) <= parent->data->GetData(0) && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true, a) :
						RemoveNode(p, parent->left, a);
				}
				else if (p->data->GetData(0) > parent->data->GetData(0) && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false, a) :
						RemoveNode(p, parent->right, a);
				}
			}
		}
	}
	/*! Search a position of node we want to delete.
	* @param node to delete
	* @param node that hane to be parent of node we want to delete
	* @param 1-delete node, 2-delete node and all under it
	*/
	void RemoveNode_vect(Node<U>* p, Node<U>* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else
			{
				if (p->data->GetVector(0) <= parent->data->GetVector(0) && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true, a) :
						RemoveNode_vect(p, parent->left, a);
				}
				else if (p->data->GetVector(0) > parent->data->GetVector(0) && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false, a) :
						RemoveNode_vect(p, parent->right, a);
				}
			}
		}
	}
private:
	/*! Add a node to the tree.
	* @param root of tree
	* @param node that we add to tree
	*/
	void AddLeaf_v(U* cur, Node<U>* node) {
		if (root == NULL)
		{
			root = new Node<U>;
			root->data = cur;
		}
		else if (cur->GetVector(0) <= node->data->GetVector(0))
		{
			if (node->left != NULL)
			{
				AddLeaf_v(cur, node->left);
			}
			else
			{
				node->left = new Node<U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->GetVector(0) > node->data->GetVector(0))
		{
			if (node->right != NULL)
			{
				AddLeaf_v(cur, node->right);
			}
			else
			{
				node->right = new Node<U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}
	}
	/*! Find the smallest in right subtree to rebuild tree
	* @param root->right
	* @return the smallest node
	*/
	Node<U>* FindSmallestPrivate(Node<U>* node)
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
		else if (a == 2) { root = NULL; }
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