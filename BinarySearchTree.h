#pragma once
#pragma once
#include "Node1.h"
#include "Node.h"
/*! @param T -data type
* @param U -object.*/
template<class T, class U>
/*! Class binary search tree*/
class BinarySearchTree
{
public:
	int d = 1;
	Node<T, U>* root;
	/*! Constructer. Root = 0.*/
	BinarySearchTree()
	{
		root = NULL;
	}
	/*! Find the smallest value of the tree to rebuild after deletion.*/
	Node<T, U>* Find_smallest()
	{
		return Find_smallestPrivate(root->right);
	}
	/*!Creating a Part1.*/
	void creat_leaf(T e, bool way1) {
		U* cur = new U;
		cur->data=e;
		cur->way = way1;
		cur->id = d++;
		AddLeaf(cur, root);
	};
	/*! Adding a Part1.*/
	void AddLeaf(U* cur, Node<T, U>* node) {
		if (root == NULL)
		{
			root = new Node<T, U>;
			root->data = cur;
		}
		else if (cur->data <= node->data->data)
		{
			if (node->left != NULL)
			{
				AddLeaf(cur, node->left);
			}
			else
			{
				node->left =new Node<T, U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->data > node->data->data)
		{
			if (node->right != NULL)
			{
				AddLeaf(cur, node->right);
			}
			else
			{
				node->right = new Node<T, U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}
	}
	/*! Create a node for the vector.*/
	void creat_leaf_v(std::vector<T> vv, bool way1) {
		U* cur = new U;
		cur->v = vv;
		cur->way = way1;
		cur->id = d++;
		AddLeaf_v(cur, root);
	};
	/*! Deleting the Part1.*/
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
	/*! Deleting a vector node.*/
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
private:
	void AddLeaf_v(U* cur, Node<T, U>* node) {
		if (root == NULL)
		{
			root = new Node<T, U>;
			root->data = cur;
		}
		else if (cur->v[0] <= node->data->v[0])
		{
			if (node->left != NULL)
			{
				AddLeaf_v(cur, node->left);
			}
			else
			{
				node->left = new Node<T, U>;
				node->left->data = cur;
				cur->way = 0;
			}
		}
		else if (cur->v[0] > node->data->v[0])
		{
			if (node->right != NULL)
			{
				AddLeaf_v(cur, node->right);
			}
			else
			{
				node->right = new Node<T, U>;
				node->right->data = cur;
				cur->way = 1;
			}
		}
	}
	Node<T, U>* Find_smallestPrivate(Node<T, U>* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	/*! Deleting the root.*/
	void RemoveRoot(int a) {
		Node<T, U>* delPtr = root;
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
			Node<T, U>* p = Find_smallest();
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	/*! Delete the node that was found before.*/
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
			match->data = p->data;
		}
	}
	void RemoveRoot_vect(int a) {
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
};