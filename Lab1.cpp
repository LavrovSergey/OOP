#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <conio.h>
#include "windows.h"
#include <queue>
using namespace std;

template<class T>
class BinarySearchTree
{
	public:	
		struct Node1 {
			T data;
			vector<T> v;
			int id = 0;
			bool way;
			Node1* left;
			Node1* right;
		};
	Node1* root;
	BinarySearchTree() 
	{
		root = NULL;
	}
	Node1* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	void AddLeaf(T e, Node1* node) {
		if (root == NULL)
		{
			root = creat_leaf(e, 0);
		}
		else if (e <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeaf(e, node->left);
			}
			else
			{
				node->left = creat_leaf(e, 0);
			}
		}
		else if (e > node->data)
		{
			if (node->right != NULL)
			{
				AddLeaf(e, node->right);
			}
			else
			{
				node->right = creat_leaf(e, 1);
			}
		}
	}
	void AddLeaf_v(vector<T> v, Node1* node) {
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (v[0] <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeaf_v(v, node->left);
			}
			else
			{
				node->left = creat_leaf_v(v, 0);
			}
		}
		else if (v[0] > node->data)
		{
			if (node->right != NULL)
			{
				AddLeaf_v(v, node->right);
			}
			else
			{
				node->right = creat_leaf_v(v, 1);
			}
		}
	}
	void RemoveNode(Node1* p, Node1* parent)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot();
			}
			else
			{
				if (p->data <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true) :
						RemoveNode(p, parent->left);
				}
				else if (p->data > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false) :
						RemoveNode(p, parent->right);
				}
			}
		}
	}
	void RemoveNode_vect(Node1* p, Node1* parent)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot();
			}
			else
			{
				if (p->v[0] <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch_vect(parent, parent->left, true) :
						RemoveNode_vect(p, parent->left);
				}
				else if (p->v[0] > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch_vect(parent, parent->right, false) :
						RemoveNode_vect(p, parent->right);
				}
			}
		}
	}
	private:
		Node1* Find_smallestPrivate(Node1* node)
		{
			if (node->left != NULL)
			{
				return Find_smallestPrivate(node->left);
			}
			else { return node; };
		}
		Node1* creat_leaf(T e, bool way1) {
			Node1* cur = new Node1;
			cur->data = e;
			cur->way = way1;
			cur->left = NULL;
			cur->right = NULL;
			cur->id = cur->id++;
			return cur;
		};
		Node1* creat_leaf_v(vector<T> v, bool way1) {
			Node1* cur = new Node1;
			cur->v = v;
			cur->way = way1;
			cur->left = NULL;
			cur->right = NULL;

			cur->id = cur->id++;
			return cur;
		};
		void RemoveRoot() {
			Node1* delPtr = root;
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
				Node1* p = Find_smallest();
				RemoveNode(p, root);
				root->data = p->data;
			}
		}
		void RemoveMatch(Node1* parent, Node1* match, bool left) {

			if (match->left == NULL && match->right == NULL)
			{
				left == true ? parent->left = NULL : parent->right = NULL;

			}
			else if (match->left == NULL && match->right != NULL)
			{
				left == true ? parent->left = match->right : parent->right = match->right;
				match->right = NULL;


			}
			else if (match->left != NULL && match->right == NULL)
			{
				left == true ? parent->left = match->left : parent->right = match->left;
				match->left = NULL;
			}
			else
			{
				Node1* p = Find_smallestPrivate(match->right);
				RemoveNode(p, match);
				match->data = p->data;
			}
		}
		void RemoveRoot_vect() {
			Node1* delPtr = root;
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
				Node1* p = Find_smallest();
				RemoveNode_vect(p, root);
				root->v.resize(p->v.size());
				for (int i = 0; i < root->v.size(); i++) {
					root->v[i] = p->v[i];
				}
			}
		}
		void RemoveMatch_vect(Node1* parent, Node1* match, bool left) {

			if (match->left == NULL && match->right == NULL)
			{
				left == true ? parent->left = NULL : parent->right = NULL;

			}
			else if (match->left == NULL && match->right != NULL)
			{
				left == true ? parent->left = match->right : parent->right = match->right;
				match->right = NULL;


			}
			else if (match->left != NULL && match->right == NULL)
			{
				left == true ? parent->left = match->left : parent->right = match->left;
				match->left = NULL;
			}
			else
			{
				Node1* p = Find_smallestPrivate(match->right);
				RemoveNode(p, match);
				match->v.resize(p->v.size());
				for (int i = 0; i < root->v.size(); i++) {
					match->v[i] = p->v[i];
				}
			}
		}
};
template<class T>
class BinaryTree{
public:
	struct Node2 {
		T data;
		vector<T> v;
		int id;
		bool way;
		Node2* left;
		Node2* right;
	};
	int d=1;
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
		else if (bal(root) == 0 && check(root->right)) { root->right = AddLeaf1(root->right, node); root->right->way = 1;  }
		else if (bal(root) == 0) { root->left = AddLeaf1(root->left, node); root->left->way = 0;  }
		else if (bal(root) == 1 && check(root->left)) { root->left = AddLeaf1(root->left, node); root->left->way = 0; }
		else if (bal(root) == 1 ) { root->right = AddLeaf1(root->right, node); root->right->way = 1; }
		return root;
	}
	void AddLeaf_v(vector<T> v, Node2* node) {
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (v[0] <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeaf_v(v, node->left);
			}
			else
			{
				node->left = creat_leaf_v(v, 0);
			}
		}
		else if (v[0] > node->data)
		{
			if (node->right != NULL)
			{
				AddLeaf_v(v, node->right);
			}
			else
			{
				node->right = creat_leaf_v(v, 1);
			}
		}
	}
	/*Node* Find_maxPrivate(Node* node) {
		if (node == NULL) { return 0; }
		Node* tmp = Find_maxPrivate(node->left);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		tmp = Find_maxPrivate(node->right);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		return node;
	}*/
	void RemoveNode(Node2* p, Node2* parent)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot();
			}
			else
			{
				if (p->data <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true) :
						RemoveNode(p, parent->left);
				}
				else if (p->data > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false) :
						RemoveNode(p, parent->right);
				}
			}
		}
	}
	void RemoveNode_vect(Node2* p, Node2* parent)
	{
		if (root != NULL)
		{
			if (root == p)
			{
				RemoveRoot();
			}
			else
			{
				if (p->v[0] <= parent->data && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch_vect(parent, parent->left, true) :
						RemoveNode_vect(p, parent->left);
				}
				else if (p->v[0] > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch_vect(parent, parent->right, false) :
						RemoveNode_vect(p, parent->right);
				}
			}
		}
	}
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
	int bal(Node2* root){
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
	Node2* creat_leaf_v(vector<T> v, bool way1) {
		Node2* cur = new Node2;
		cur->v = v;
		cur->way = way1;
		cur->left = NULL;
		cur->right = NULL;

		cur->id = cur->id++;
		return cur;
	};
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
	void RemoveMatch_vect(Node2* parent, Node2* match, bool left) {

		if (match->left == NULL && match->right == NULL)
		{
			left == true ? parent->left = NULL : parent->right = NULL;

		}
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;


		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
		}
		else
		{
			Node2* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match);
			match->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				match->v[i] = p->v[i];
			}
		}
	}
	void RemoveRoot() {
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
			RemoveNode(p, root);
			root->data = p->data;
		}
	}
	void RemoveMatch(Node2* parent, Node2* match, bool left) {

		if (match->left == NULL && match->right == NULL)
		{
			left == true ? parent->left = NULL : parent->right = NULL;

		}
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;


		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
		}
		else
		{
			Node2* p = Find_smallestPrivate(match->right);
			RemoveNode(p, match);
			match->data = p->data;
		}
	}
};
template <class T>
class Functions1 :public BinarySearchTree<int>, public BinaryTree<int> {
	public:
		void FindByTheWay(int a) {
			int count = 0, i = 0;
			int n;
			cout << "Введите длину маршрута" << endl;
			cin >> n;
			bool* mas = new bool[n];
			cout << "Заполните маршрут" << endl;
			for (int j = 0; j < n; j++) {
				cin >> mas[j];
			}
			if (a == 1) {
				if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
				{
					cout << "Такого нема";
				}
			}
			else if (a == 2) {
				if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
				{
					cout << "Такого нема";
				}
			}
			delete[]mas;
			system("pause");
		}
		void Delete(int a)
		{
			T inf;
			cout << "Введите, что хотите удалить" << endl;
			cin >> inf;
			if (a == 1)
			{
				Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root));
			}
			else if (a == 2)
			{
				Node2* ptr = FindPrivate2(inf, BinaryTree::root); 
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree::RemoveNode(ptr, BinaryTree::root));
			}
		}
		void AddLeaf(int a) {
			T inf;
			cout << "Введите информацию" << endl;
			cin >> inf;
			if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
			else if (a == 2) {
				BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0));
			}
		}
		void AddLeaf_vect(int a) {
			int n;
			T inf;
			vector<T> v;
			cout << "Размер вектора: " << endl;
			cin >> n;
			cout << "Заполните вектор" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1) { BinarySearchTree::AddLeaf_v(v,BinarySearchTree:: root);}
			else if (a == 2) { BinaryTree::AddLeaf_v(v, BinaryTree::root); }
		}
		void Find(int a) {
			T inf;
			cout << "Введите, что хотите найти" << endl;
			cin >> inf;
			if (a == 1) 
			{
				Node1* ptr = FindPrivate1(inf, BinarySearchTree:: root); 
                if (ptr == NULL) { cout << "Такого нема" << endl; }
			    else(cout << ptr->id << ". " << ptr->data << endl);
				system("pause");
			}
			else if (a == 2)
			{
				Node2* ptr= FindPrivate2(inf, BinaryTree::root); 
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else(cout << ptr->id << ". " << ptr->data << endl);
				system("pause");
			}
		}
		void PrintInOrder(int a) {
			if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
			else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
			system("pause");
		}
		void PrintInOrder_vect(int a) {
				if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
				else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
				system("pause");
			}
		void PrintPostOrder(int a) {
				if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
				else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
				system("pause");
			}
		void PrintPostOrder_vect(int a) {
				if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
				else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
				system("pause");
			}
		void PrintPreOrder(int a) {
				if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
				else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
				system("pause");
			}
		void PrintPreOrder_vect(int a) {
			if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
			else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
			system("pause");
			}
		void Find_vect(int a) {
				vector<T> v;
				int n;
				cout << "Введите размер вектора" << endl;
				cin >> n;
				cout << "Введите, что хотите найти" << endl;
				for (int i = 0; i < n; i++)
				{
					cin >> v[i];
				}
				if (a == 1)
				{
					Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
					if (ptr == NULL) { cout << "Такого нема" << endl; }
					else {
						cout << ptr->id << ". ";
						for (int i = 0; i < n; i++)
						{
							cout << v[i];
						}
					}
					system("pause");
				}
				if (a == 2)
				{
					Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
					if (ptr == NULL) { cout << "Такого нема" << endl; }
					else {
						cout << ptr->id << ". ";
						for (int i = 0; i < n; i++)
						{
							cout << v[i];
						}
					}
					system("pause");
				}
			}
		void Delete_vect(int a)
			{
				vector<T> v;
				int n;
				cout << "Введите размер вектора" << endl;
				cin >> n;
				cout << "Введите, что хотите найти" << endl;
				for (int i = 0; i < n; i++)
				{
					cin >> v[i];
				}
				if (a == 1)
				{
					Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
					if (ptr == NULL) { cout << "Такого нема" << endl; }
					else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root));
				}
				else if (a == 2)
				{
					Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
					if (ptr == NULL) { cout << "Такого нема" << endl; }
					else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root));
				}
			}
		private:
		int FindByTheWayPrivate1(bool* mas, Node1* node, int count, int i, int n) {
				if (node != NULL)
				{
					if (i == n)
					{
						cout << node->data << endl;
						count++;
					}
					else
					{
						if (mas[i] == 0)
						{
							i++;
							FindByTheWayPrivate1(mas, node->left, count, i, n);
						}
						else
						{
							i++;
							FindByTheWayPrivate1(mas, node->right, count, i, n);
						}
					}
				}
				else { return count; }
			}
		int FindByTheWayPrivate2(bool* mas, Node2* node, int count, int i, int n) {
				if (node != NULL)
				{
					if (i == n)
					{
						cout << node->data << endl;
						count++;
					}
					else
					{
						if (mas[i] == 0)
						{
							i++;
							FindByTheWayPrivate2(mas, node->left, count, i, n);
						}
						else
						{
							i++;
							FindByTheWayPrivate2(mas, node->right, count, i, n);
						}
					}
				}
				else { return count; }
			}
		void PrintInOrderPrivate1(Node1* node)
		{
			if (BinarySearchTree::root != NULL)
			{
				if (node->left != NULL)
				{
					PrintInOrderPrivate1(node->left);
				}
				cout << node->id << ". ";
				cout << node->data << endl;
				if (node->right != NULL)
				{
					PrintInOrderPrivate1(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		}
		void PrintInOrderPrivate2(Node2* node) {
			if (BinaryTree::root != NULL)
			{
				if (node->left != NULL)
				{
					PrintInOrderPrivate2(node->left);
				}
				cout << node->id << ". ";
				cout << node->data << endl;
				if (node->right != NULL)
				{
					PrintInOrderPrivate2(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		};
		void PrintPreOrderPrivate1(Node1* node) {
			if (node != NULL)
			{
				cout << node->id << ".";
				cout << node->data << endl;
				if (node->left != NULL)
				{
					PrintPreOrderPrivate1(node->left);
				}
				if (node->right != NULL)
				{
					PrintPreOrderPrivate1(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPreOrderPrivate2(Node2* node) {
			if (node != NULL)
			{
				cout << node->id << ".";
				cout << node->data << endl;
				if (node->left != NULL)
				{
					PrintPreOrderPrivate2(node->left);
				}
				if (node->right != NULL)
				{
					PrintPreOrderPrivate2(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPostOrderPrivate1(Node1* node)
		{
			if (node != NULL)
			{
				if (node->left != NULL)
				{
					PrintPostOrderPrivate1(node->left);
				}
				if (node->right != NULL)
				{
					PrintPostOrderPrivate1(node->right);
				}
				cout << node->id << ".";
				cout << node->data << endl;
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPostOrderPrivate2(Node2* node)
		{
			if (node != NULL)
			{
				if (node->left != NULL)
				{
					PrintPostOrderPrivate2(node->left);
				}
				if (node->right != NULL)
				{
					PrintPostOrderPrivate2(node->right);
				}
				cout << node->id << ".";
				cout << node->data << endl;
			}
			else(cout << "Пусто" << endl);
		}
	    void PrintPreOrderPrivate1_vect(Node1* node) {
			if (node != NULL)
			{
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
				if (node->left != NULL)
				{
					PrintPreOrderPrivate1_vect(node->left);
				}
				if (node->right != NULL)
				{
					PrintPreOrderPrivate1_vect(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPreOrderPrivate2_vect(Node2* node) {
			if (node != NULL)
			{
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
				if (node->left != NULL)
				{
					PrintPreOrderPrivate2_vect(node->left);
				}
				if (node->right != NULL)
				{
					PrintPreOrderPrivate2_vect(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPostOrderPrivate1_vect( Node1* node)
		{
			if (node != NULL)
			{
				if (node->left != NULL)
				{
					PrintPostOrderPrivate1_vect(node->left);
				}
				if (node->right != NULL)
				{
					PrintPostOrderPrivate1_vect(node->right);
				}
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			}
			else(cout << "Пусто" << endl);
		}
		void PrintPostOrderPrivate2_vect(Node2* node)
		{
			if (node != NULL)
			{
				if (node->left != NULL)
				{
					PrintPostOrderPrivate2_vect(node->left);
				}
				if (node->right != NULL)
				{
					PrintPostOrderPrivate2_vect(node->right);
				}
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			}
			else(cout << "Пусто" << endl);
		}
		void PrintInOrderPrivate1_vect(Node1* node)
		{
			if (BinarySearchTree::root != NULL)
			{
				if (node->left != NULL)
				{
					PrintInOrderPrivate1(node->left);
				}
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
				if (node->right != NULL)
				{
					PrintInOrderPrivate1(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		};
		void PrintInOrderPrivate2_vect(Node2* node)
		{
			if (BinaryTree::root != NULL)
			{
				if (node->left != NULL)
				{
					PrintInOrderPrivate2(node->left);
				}
				cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
				if (node->right != NULL)
				{
					PrintInOrderPrivate2(node->right);
				}
			}
			else(cout << "Пусто" << endl);
		};
		Node1* FindPrivate1(T e, Node1* node)
		{
			if (node != NULL)
			{
				if (node->data == e)
				{
					return node;
				}
				else
				{
					if (e <= node->data)
					{
						FindPrivate1(e, node->left);
					}
					else if (e > node->data)
					{
						FindPrivate1(e, node->right);
					}
				}
			}
			else { return node; }
		}
		bool compare(vector<T> v1, vector<T> v2)
		{
			for (int i = 0; i < v1.size(); i++)
			{
				if (v1[i] != v2[i]) { return false; }
			}
			return true;
		}
		Node2* FindPrivate2(T inf, Node2* node)
		{
			if (node == NULL) return node;
			
				if (inf == node->data) {
					return node;
				    }
				Node2* tmp1 = FindPrivate2(inf, node->left);
				if (tmp1!=NULL) {
					if(inf == tmp1->data){return tmp1;}
				}
				Node2* tmp2 = FindPrivate2(inf, node->right);
				if (  tmp2 != NULL) {
					if(inf == tmp2->data){return tmp2;}
				}
		}
		Node1* FindPrivate1_vect(vector<T> v, Node1* node)
		{
			if (node != NULL)
			{

				if (v.size() == node->v.size() && v == node->v)
				{
					return node;
				}
				else
				{
					if (v[0] <= node->data)
					{
						FindPrivate1_vect(v, node->left);
					}
					else if (v[0] > node->data)
					{
						FindPrivate1_vect(v, node->right);
					}
				}
			}
			else { return node; }
		}
		Node2* FindPrivate2_vect(vector<T> v, Node2* node)
		{
			if (node == NULL) return node;

			if (v.size() == node->v.size()) {
				if(compare(v, node->v)){return node;}
			}
			Node2* tmp1 = FindPrivate2_vect(v, node->left);
			if (tmp1 != NULL) {
				if (v.size() == tmp1->v.size()) 
				{ 
					if(compare(v, tmp1->v))
					{
						return tmp1; }
				    }
			}
			Node2* tmp2 = FindPrivate2_vect(v, node->right);
			if (tmp2 != NULL) {
				if (v.size() == tmp2->v.size())
				{
					if (compare(v, tmp2->v))
					{
						return tmp2;
					}
				}
			}

		}
	};
template <class T>
class Functions2 :public BinarySearchTree<double>, public BinaryTree<double> {
public:
	void FindByTheWay(int a) {
		int count = 0, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	void Delete(int a)
	{
		T inf;
		cout << "Введите, что хотите удалить" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root));
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else (BinaryTree::RemoveNode(ptr, BinaryTree::root));
		}
	}
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
		else if (a == 2) {
			BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0));
		}
	}
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Размер вектора: " << endl;
		cin >> n;
		cout << "Заполните вектор" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree::AddLeaf_v(v, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::AddLeaf_v(v, BinaryTree::root); }
	}
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void Find_vect(int a) {
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	void Delete_vect(int a)
	{
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root));
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root));
		}
	}
private:
	int FindByTheWayPrivate1(bool* mas, Node1* node, int count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count++;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	int FindByTheWayPrivate2(bool* mas, Node2* node, int count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count++;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate2(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate2(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node2* node) {
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPreOrderPrivate1(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate1(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate1_vect(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate1_vect(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate1_vect(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(Node2* node)
	{
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node1* FindPrivate1(T e, Node1* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	bool compare(vector<T> v1, vector<T> v2)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i]) { return false; }
		}
		return true;
	}
	Node2* FindPrivate2(T inf, Node2* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		Node2* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		Node2* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	Node1* FindPrivate1_vect(vector<T> v, Node1* node)
	{
		if (node != NULL)
		{

			if (v.size() == node->v.size() && v == node->v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->data)
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->data)
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	Node2* FindPrivate2_vect(vector<T> v, Node2* node)
	{
		if (node == NULL) return node;

		if (v.size() == node->v.size()) {
			if (compare(v, node->v)) { return node; }
		}
		Node2* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size())
			{
				if (compare(v, tmp1->v))
				{
					return tmp1;
				}
			}
		}
		Node2* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size())
			{
				if (compare(v, tmp2->v))
				{
					return tmp2;
				}
			}
		}

	}
};
template <class T>
class Functions3 :public BinarySearchTree<string>, public BinaryTree<string> {
public:
	void FindByTheWay(int a) {
		int count = 0, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	void Delete(int a)
	{
		T inf;
		cout << "Введите, что хотите удалить" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree::RemoveNode(ptr, BinarySearchTree::root));
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else (BinaryTree::RemoveNode(ptr, BinaryTree::root));
		}
	}
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree::AddLeaf(inf, BinarySearchTree::root); }
		else if (a == 2) {
			BinaryTree::root = AddLeaf1(BinaryTree::root, BinaryTree::creat_leaf(inf, 0));
		}
	}
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Размер вектора: " << endl;
		cin >> n;
		cout << "Заполните вектор" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree::AddLeaf_v(v, BinarySearchTree::root); }
		else if (a == 2) { BinaryTree::AddLeaf_v(v, BinaryTree::root); }
	}
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node1* ptr = FindPrivate1(inf, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2(inf, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree::root); }
		system("pause");
	}
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree::root); }
		system("pause");
	}
	void Find_vect(int a) {
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else {
				cout << ptr->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	void Delete_vect(int a)
	{
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		if (a == 1)
		{
			Node1* ptr = FindPrivate1_vect(v, BinarySearchTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree::RemoveNode_vect(ptr, BinarySearchTree::root));
		}
		else if (a == 2)
		{
			Node2* ptr = FindPrivate2_vect(v, BinaryTree::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else (BinaryTree::RemoveNode_vect(ptr, BinaryTree::root));
		}
	}
private:
	int FindByTheWayPrivate1(bool* mas, Node1* node, int count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count++;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate1(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate1(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	int FindByTheWayPrivate2(bool* mas, Node2* node, int count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count++;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate2(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate2(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node2* node) {
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". ";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPreOrderPrivate1(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate1(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate1_vect(Node1* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node2* node) {
		if (node != NULL)
		{
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate1_vect(Node1* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate1_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node2* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate2_vect(node->right);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate1_vect(Node1* node)
	{
		if (BinarySearchTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(Node2* node)
	{
		if (BinaryTree::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node1* FindPrivate1(T e, Node1* node)
	{
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else
			{
				if (e <= node->data)
				{
					FindPrivate1(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate1(e, node->right);
				}
			}
		}
		else { return node; }
	}
	bool compare(vector<T> v1, vector<T> v2)
	{
		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i] != v2[i]) { return false; }
		}
		return true;
	}
	Node2* FindPrivate2(T inf, Node2* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		Node2* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		Node2* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	Node1* FindPrivate1_vect(vector<T> v, Node1* node)
	{
		if (node != NULL)
		{

			if (v.size() == node->v.size() && v == node->v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->data)
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->data)
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	Node2* FindPrivate2_vect(vector<T> v, Node2* node)
	{
		if (node == NULL) return node;

		if (v.size() == node->v.size()) {
			if (compare(v, node->v)) { return node; }
		}
		Node2* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size())
			{
				if (compare(v, tmp1->v))
				{
					return tmp1;
				}
			}
		}
		Node2* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size())
			{
				if (compare(v, tmp2->v))
				{
					return tmp2;
				}
			}
		}

	}
};

int menu_console() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 43) % 43;
		if (key == 0) cout << "-> Записать int" << endl;
		else  cout << "   Записать int" << endl;
		if (key == 1) cout << "-> Вывести InOrder int" << endl;
		else  cout << "   Вывести InOrder int" << endl;
		if (key == 2) cout << "-> Вывести PreOrder int" << endl;
		else  cout << "   Вывести PreOrder int" << endl;
		if (key == 3) cout << "-> Вывести PostOrder int" << endl;
		else  cout << "   Вывести PostOrder int" << endl;
		if (key == 4) cout << "-> Найти по пути int" << endl;
		else  cout << "   Найти по пути int" << endl;
		if (key == 5) cout << "-> Найти int" << endl;
		else  cout << "   Найти int" << endl;
		if (key == 6) cout << "-> Удалить int" << endl;
		else  cout << "   Удалить int" << endl;
		if (key == 7) cout << "-> Записать vector int" << endl;
		else  cout << "   Записать vector int" << endl;
		if (key == 8) cout << "-> Вывести InOrder vector int" << endl;
		else  cout << "   Вывести InOrder vector int" << endl;
		if (key == 9) cout << "-> Вывести PreOrder vector int" << endl;
		else  cout << "   Вывести PreOrder vector int" << endl;
		if (key == 10) cout << "-> Вывести PostOrder vector int" << endl;
		else  cout << "   Вывести PostOrder vector int" << endl;
		if (key == 11) cout << "-> Найти по пути vector int" << endl;
		else  cout << "   Найти по пути vector int" << endl;
		if (key == 12) cout << "-> Найти vector int" << endl;
		else  cout << "   Найти vector int" << endl;
		if (key == 13) cout << "-> Удалить vector int" << endl;
		else  cout << "   Удалить vector int" << endl;
		if (key == 14) cout << "-> Записать double" << endl;
		else  cout << "   Записать double" << endl;
		if (key == 15) cout << "-> Вывести InOrder double" << endl;
		else  cout << "   Вывести InOrder double" << endl;
		if (key == 16) cout << "-> Вывести PreOrder double" << endl;
		else  cout << "   Вывести PreOrder double" << endl;
		if (key == 17) cout << "-> Вывести PostOrder double" << endl;
		else  cout << "   Вывести PostOrder double" << endl;
		if (key == 18) cout << "-> Найти по пути double" << endl;
		else  cout << "   Найти по пути double" << endl;
		if (key == 19) cout << "-> Найти double" << endl;
		else  cout << "   Найти double" << endl;
		if (key == 20) cout << "-> Удалить double" << endl;
		else  cout << "   Удалить double" << endl;
		if (key == 21) cout << "-> Записать vector double" << endl;
		else  cout << "   Записать vector double" << endl;
		if (key == 22) cout << "-> Вывести InOrder vector double" << endl;
		else  cout << "   Вывести InOrder vector double" << endl;
		if (key == 23) cout << "-> Вывести PreOrder vector double" << endl;
		else  cout << "   Вывести PreOrder vector double" << endl;
		if (key == 24) cout << "-> Вывести PostOrder vector double" << endl;
		else  cout << "   Вывести PostOrder vector double" << endl;
		if (key == 25) cout << "-> Найти по пути vector double" << endl;
		else  cout << "   Найти по пути vector double" << endl;
		if (key == 26) cout << "-> Найти vector double" << endl;
		else  cout << "   Найти vector double" << endl;
		if (key == 27) cout << "-> Удалить vector double" << endl;
		else  cout << "   Удалить vector double" << endl;
		if (key == 28) cout << "-> Записать string" << endl;
		else  cout << "   Записать string" << endl;
		if (key == 29) cout << "-> Вывести InOrder string" << endl;
		else  cout << "   Вывести InOrder string" << endl;
		if (key == 30) cout << "-> Вывести PreOrder string" << endl;
		else  cout << "   Вывести PreOrder string" << endl;
		if (key == 31) cout << "-> Вывести PostOrder string" << endl;
		else  cout << "   Вывести PostOrder string" << endl;
		if (key == 32) cout << "-> Найти по пути string" << endl;
		else  cout << "   Найти по пути string" << endl;
		if (key == 33) cout << "-> Найти string" << endl;
		else  cout << "   Найти string" << endl;
		if (key == 34) cout << "-> Удалить string" << endl;
		else  cout << "   Удалить string" << endl;
		if (key == 35) cout << "-> Записать vector string" << endl;
		else  cout << "   Записать vector string" << endl;
		if (key == 36) cout << "-> Вывести InOrder vector string" << endl;
		else  cout << "   Вывести InOrder vector string" << endl;
		if (key == 37) cout << "-> Вывести PreOrder vector string" << endl;
		else  cout << "   Вывести PreOrder vector string" << endl;
		if (key == 38) cout << "-> Вывести PostOrder vector string" << endl;
		else  cout << "   Вывести PostOrder vector string" << endl;
		if (key == 39) cout << "-> Найти по пути vector string" << endl;
		else  cout << "   Найти по пути vector string" << endl;
		if (key == 40) cout << "-> Найти vector string" << endl;
		else  cout << "   Найти vector string" << endl;
		if (key == 41) cout << "-> Удалить vector string" << endl;
		else  cout << "   Удалить vector string" << endl;
		/*if (key == 30) cout << "-> Найти string" << endl;
		else  cout << "   Найти string" << endl;
		if (key == 31) cout << "-> Найти int по пути" << endl;
		else  cout << "   Найти int по пути" << endl;*/
		if (key == 42) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int menu(bool isRunning, int a)
{
	 
	Functions1<int> i;
	Functions1<int> i_v;
	Functions2<double> d;
	Functions2<double> d_v;
	Functions3<string> s;
	Functions3<string> s_v;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_console();
		switch (answer)
		{
		case 0: i.AddLeaf(a); break;
		case 1: i.PrintInOrder(a); break;
		case 2: i.PrintPreOrder(a); break;
		case 3: i.PrintPostOrder(a); break;
		case 4: i.FindByTheWay(a); break;
		case 5: i.Find(a); break;
		case 6: i.PrintInOrder(a); i.Delete(a);  break;
		case 7: i_v.AddLeaf_vect(a); break;
		case 8: i_v.PrintInOrder_vect(a); break;
		case 9: i_v.PrintPreOrder_vect(a); break;
		case 10: i_v.PrintPostOrder_vect(a); break;
		case 11: i_v.FindByTheWay(a); break;
		case 12: i_v.Find_vect(a); break;
		case 13: i_v.PrintInOrder_vect(a); i.Delete_vect(a); break;
		case 14: d.AddLeaf(a); break;
		case 15: d.PrintInOrder(a); break;
		case 16: d.PrintPreOrder(a); break;
		case 17: d.PrintPostOrder(a); break;
		case 18: d.FindByTheWay(a); break;
		case 19: d.Find(a); break;
		case 20: d.PrintInOrder(a); i.Delete(a);  break;
		case 21: d_v.AddLeaf_vect(a); break;
		case 22: d_v.PrintInOrder_vect(a); break;
		case 23: d_v.PrintPreOrder_vect(a); break;
		case 24: d_v.PrintPostOrder_vect(a); break;
		case 25: d_v.FindByTheWay(a); break;
		case 26: d_v.Find_vect(a); break;
		case 27: d_v.PrintInOrder_vect(a); i.Delete_vect(a); break;
		case 28: s.AddLeaf(a); break;
		case 29: s.PrintInOrder(a); break;
		case 30: s.PrintPreOrder(a); break;
		case 31: s.PrintPostOrder(a); break;
		case 32: s.FindByTheWay(a); break;
		case 33: s.Find(a); break;
		case 34: s.PrintInOrder(a); i.Delete(a);  break;
		case 35: s_v.AddLeaf_vect(a); break;
		case 36: s_v.PrintInOrder_vect(a); break;
		case 37: s_v.PrintPreOrder_vect(a); break;
		case 38: s_v.PrintPostOrder_vect(a); break;
		case 39: s_v.FindByTheWay(a); break;
		case 40: s_v.Find_vect(a); break;
		case 41: s_v.PrintInOrder_vect(a); i.Delete_vect(a); break;

	/*	case 6: d.AddLeaf_vect(); break;
		case 7: d.PrintInOrder_vect(); break;
		case 8: s.AddLeaf(); break;
		case 9: s.PrintInOrder(); break;
		case 10: s.AddLeaf_vect(); break;
		case 11: s.PrintInOrder_vect(); break;*/

		/*case 4:tree1.Find(); break;
		case 5:tree2.Find(); break;*/
		
		case 42: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}

int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> BinarySearchTree" << endl;
		else  cout << "   BinarySearchTree" << endl;
		if (key == 1) cout << "-> Binary Tree" << endl;
		else  cout << "   Binary Tree" << endl;
		if (key == 2) cout << "-> Tree list of sons" << endl;
		else  cout << "   Tree list of sons" << endl;
		if (key == 3) cout << "-> Part 2" << endl;
		else  cout << "   Part 2" << endl;
		if (key == 4) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
int main(bool isRunning)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0: menu(true, 1); break;
		case 1: menu(true, 2);  break;
		case 2:  break;
		case 3:  break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}