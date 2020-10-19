#pragma once


template <class T>
class TreeChildrenList {
public:
	struct Node3
	{
		T data;
		vector<T> v;
		int id = 0;
		bool way;
		struct Node3* next;
		struct Node3* child;
	};
	int d = 0;
	Node3* root;
	void AddLeaf(T e, Node3* node) {
		bool c = false;
		if (root == NULL)
		{
			root = creat_leaf(e, 0);
		}
		else if (node->child)
		{
			if (e > node->child->data) {
				node = node->child;
				while (node->next)
				{
					node = node->next;
					if (node->data > e) {
						if (node->child) { AddLeaf(e, node); c = true; }
						else {
							node->child = creat_leaf(e, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->next = creat_leaf(e, 1); }
			}
			else {
				node->child->child = creat_leaf(e, 0);
			}
		}
		else(node->child = creat_leaf(e, 0));
	}
	void AddLeaf_v(vector<T> v, Node3* node) {
		bool c = false;
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (node->child)
		{
			if (v[0] > node->child->data) {
				node = node->child;
				while (node->next)
				{
					node = node->next;
					if (node->data > v[0]) {
						if (node->child) { AddLeaf_v(v, node); c = true; }
						else {
							node->child = creat_leaf_v(v, 0);
							c = true;
							break;
						}
					}
				}
				if (c == false) { node->next = creat_leaf_v(v, 1); }
			}
			else {
				node->child->child = creat_leaf_v(v, 0);
			}
		}
		else(node->child = creat_leaf_v(v, 0));
	}
	Node3* newNode(int data)
	{
		Node3* newNode = new Node3;
		newNode->next = newNode->child = NULL;
		newNode->data = data;
		return newNode;
	}
	void RemoveNode(Node3* p, Node3* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else if (root != p && parent->child != p && parent->next != p)
			{
				if (parent->child)
				{
					if (p->data <= parent->child->data)
					{
						RemoveNode(p, parent->child, a);
					}
					else if (p->data > parent->child->data)
					{
						if (parent == root) { RemoveNode(p, parent->child->next, a); }
						else(RemoveNode(p, parent->next, a));
					}
				}
				else(RemoveNode(p, parent->next, a));

			}
			if (parent->child == p) {
				RemoveMatch(parent, parent->child, a);
			}
			else if (parent->next == p) {
				RemoveMatch(parent, parent->next, a);
			}
		}
	}
	void RemoveNode_vect(Node3* p, Node3* parent, int a)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot(a);
			}
			else if (root != p && parent->child != p && parent->next != p)
			{
				if (parent->child)
				{
					if (p->data <= parent->child->data)
					{
						RemoveNode(p, parent->child, a);
					}
					else if (p->data > parent->child->data)
					{
						if (parent == root) { RemoveNode(p, parent->child->next, a); }
						else(RemoveNode(p, parent->next, a));
					}
				}
				else(RemoveNode(p, parent->next, a));

			}
			if (parent->child == p) {
				RemoveMatch(parent, parent->child, a);
			}
			else if (parent->next == p) {
				RemoveMatch(parent, parent->next, a);
			}
		}
	}
private:
	Node3* creat_leaf(T e, bool way1) {
		Node3* cur = new Node3;
		cur->data = e;
		cur->way = way1;
		cur->next = NULL;
		cur->child = NULL;
		cur->id = d++;
		return cur;
	};
	Node3* creat_leaf_v(vector<T> v, bool way1) {
		Node3* cur = new Node3;
		cur->v = v;
		cur->way = way1;
		cur->next = NULL;
		cur->child = NULL;
		cur->id = d++;
		return cur;
	};
	void RemoveMatch(Node3* parent, Node3* match, int a) {
		if (parent == root)
		{
			if (a == 1) {
				if (match->child) {
					parent->child = match->child;
					match->child->next = match->next;
				}
				else {
					parent->child = match->next;
				}
			}
			else {
				parent->child = match->next;
			}
		}
		else if (parent->next == match)
		{
			if (a == 1) {
				if (match->child) {
					parent->next = match->child;
					while (parent->next)
					{
						parent = parent->next;
					}
					parent->next = match->next;
				}
				else {
					parent->next = match->next;
				}
			}
			else {
				parent->next = match->next;
			}
		}
		else if (parent->child == match)
		{
			if (a == 1) {
				if (match->next)
				{
					parent->child = match->next;
					while (parent->child) {
						parent = parent->child;
					}
					parent->child = match->child;
				}
				else {
					parent->child = match->child;
				}
			}
			else { parent->child = match->next; }
		}
	}
	void RemoveRoot(int a) {
		Node3* node;
		if (root->child == NULL)
		{
			root = NULL;

		}
		else if (root->child != NULL && root->child->child != NULL)
		{
			node = root->child->child;
			root = root->child;
			while (node->next)
			{
				node = node->next;
			}
			node->next = root->next;
			root->next = NULL;
		}
		else if (root->child != NULL && root->child->child == NULL)
		{
			root = root->child;
			root->child = root->next;
			root->next = NULL;
		}
	}
};