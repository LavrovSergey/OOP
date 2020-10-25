#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <conio.h>
#include "windows.h"
#include "Functions.h"
#include "Node1.h"
using namespace std;
template<class T>
class BinaryTree {
public:
	/*struct Node {
		T data;
		vector<T> v;
		int id;
		bool way;
		Node* left;
		Node* right;
	};*/
	int d = 1;
	Node<T>* root;
	BinaryTree()
	{
		root = NULL;
	}
	/*Node* Find_max() {
		return Find_maxPrivate(root);
	}*/
	Node<T>* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	Node<T>* AddLeaf1(Node<T>* root, Node<T>* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) { root->right = AddLeaf1(root->right, node); root->right->way = 1; }
		else if (bal(root) == 0) { root->left = AddLeaf1(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1 && check(root->left)) { root->left = AddLeaf1(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1) { root->right = AddLeaf1(root->right, node); root->right->way = 1; }
		return root;
	}
	Node<T>* AddLeaf1_v(Node<T>* root, Node<T>* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) {
			root->right = AddLeaf1_v(root->right, node);
			root->right->way = 1;
		}
		else if (bal(root) == 0) {
			root->left = AddLeaf1_v(root->left, node);
			root->left->way = 0;
		}
		else if (bal(root) == 1 && check(root->left)) {
			root->left = AddLeaf1_v(root->left, node);
			root->left->way = 0;
		}
		else if (bal(root) == 1) {
			root->right = AddLeaf1_v(root->right, node);
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
	Node<T>* creat_leaf_v(vector<T> v, bool way1) {
		Node* cur = new Node;
		for (int i = 0; i < v.size(); i++) { cur->v[i] = v[i]; }
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
	Node<T>* creat_leaf(T e, bool way1) {
		Node* cur = new Node;
		cur->data = e;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
private:
	int bal(Node<T>* node) {
		if (node == NULL) { return 0; }
		int lheight = height(node->left) + 1;
		int rheight = height(node->right) + 1;
		return(lheight - rheight);
	}
	int height(Node<T>* node) {
		if (node == NULL)
		{
			return 0;
		}
		else {
			int lheight = height(node->left) + 1;
			int rheight = height(node->right) + 1;

			return(lheight > rheight) ? lheight : rheight;
		}
	}
	bool check(Node<T>* node) {
		if (node == NULL) { return false; }
		bool x = check(node->left);
		if (bal(node))
		{
			return true;
		}
		bool y = check(node->right);
		return x || y;
	}
	Node<T>* Find_smallestPrivate(Node<T>* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	void RemoveRoot_vect() {
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
};
