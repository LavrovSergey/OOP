#pragma once

template<class T>
class BinaryTree {
public:
	struct Node2 {
		T data;
		vector<T> v;
		int id;
		bool way;
		Node2* left;
		Node2* right;
	};
	int d = 1;
	Node2* root;
	BinaryTree()
	{
		root = NULL;
	}
	/*Node* Find_max() {
		return Find_maxPrivate(root);
	}*/
	Node2* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	Node2* AddLeaf1(Node2* root, Node2* node) {
		if (root == NULL) { return node; }
		else if (bal(root) == 0 && check(root->right)) { root->right = AddLeaf1(root->right, node); root->right->way = 1; }
		else if (bal(root) == 0) { root->left = AddLeaf1(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1 && check(root->left)) { root->left = AddLeaf1(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1) { root->right = AddLeaf1(root->right, node); root->right->way = 1; }
		return root;
	}
	Node2* AddLeaf1_v(Node2* root, Node2* node) {
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
	void RemoveNode(Node2* p, Node2* parent, int a)
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
	void RemoveNode_vect(Node2* p, Node2* parent, int a)
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
	Node2* creat_leaf_v(vector<T> v, bool way1) {
		Node2* cur = new Node2;
		for (int i = 0; i < v.size(); i++) { cur->v[i] = v[i]; }
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
	Node2* creat_leaf(T e, bool way1) {
		Node2* cur = new Node2;
		cur->data = e;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;
		cur->id = d++;
		return cur;
	};
private:
	int bal(Node2* root) {
		if (root == NULL) { return 0; }
		int lheight = height(root->left) + 1;
		int rheight = height(root->right) + 1;
		return(lheight - rheight);
	}
	int height(Node2* root) {
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
	bool check(Node2* root) {
		if (root == NULL) { return false; }
		bool x = check(root->left);
		if (bal(root))
		{
			return true;
		}
		bool y = check(root->right);
		return x || y;
	}
	Node2* Find_smallestPrivate(Node2* node)
	{
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else { return node; };
	}
	void RemoveRoot_vect() {
		Node2* delPtr = root;
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
			Node2* p = Find_smallest();
			RemoveNode_vect(p, root);
			root->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				root->v[i] = p->v[i];
			}
		}
	}
	void RemoveMatch_vect(Node2* parent, Node2* match, bool left, int a) {

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
			Node2* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				match->v[i] = p->v[i];
			}
		}
	}
	void RemoveRoot(int a) {
		Node2* delPtr = root;
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
			Node2* p = Find_smallest();
			RemoveNode(p, root, a);
			root->data = p->data;
		}
	}
	void RemoveMatch(Node2* parent, Node2* match, bool left, int a) {

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
			Node2* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match, a);
			match->data = p->data;
		}
	}
};