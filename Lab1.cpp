#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <conio.h>
#include "windows.h"

using namespace std;
int id = 0;
template<class T>
class BinarySearchTree
{
	public:
		struct Node {
			T data;
			vector<T> v;
			int id;
			bool way;
			Node* left;
			Node* right;
		};
	Node* root;
	BinarySearchTree() 
	{
		root = NULL;
	}
	
	/*void Find() {
		int count = 0;
		T e;
		cout << "Введите слово, перевод которого хотите узнать" << endl;
		cin >> e;
		count = FindPrivate(e, root, count);
		if (count == 0) { cout << "Такого нема"; }
		system("pause");
	}*/
	/*Node* Find_max() {
		return Find_maxPrivate(root);
	}*/
	Node* Find_smallest()
	{
		return Find_smallestPrivate(root);
	}
	void AddLeafPrivate(T e, Node* node) {
		if (root == NULL)
		{
			root = creat_leaf(e, 0);
		}
		else if (e <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeafPrivate(e, node->left);
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
				AddLeafPrivate(e, node->right);
			}
			else
			{
				node->right = creat_leaf(e, 1);
			}
		}
	}
	void AddLeafPrivate_v(vector<T> v, Node* node) {
		if (root == NULL)
		{
			root = creat_leaf_v(v, 0);
		}
		else if (v[0] <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeafPrivate_v(v, node->left);
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
				AddLeafPrivate_v(v, node->right);
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
	
	void RemoveRootPrivate(Node* p, Node* parent)
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
						RemoveRootPrivate(p, parent->left);
				}
				else if (p->data > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false) :
						RemoveRootPrivate(p, parent->right);
				}
			}
		}
	}
	void RemoveRoot() {
		Node* delPtr = root;
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
			Node* p = Find_smallest();
			RemoveRootPrivate(p, root);
			root->data = p->data;
		}
	}
	void RemoveMatch(Node* parent, Node* match, bool left) {

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
			Node* p = Find_smallestPrivate(match->right);
			RemoveRootPrivate(p, match);
			match->data = p->data;
		}
	}
	void RemoveRootPrivate_vect(Node* p, Node* parent)
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
						RemoveRootPrivate_vect(p, parent->left);
				}
				else if (p->v[0] > parent->data && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch_vect(parent, parent->right, false) :
						RemoveRootPrivate_vect(p, parent->right);
				}
			}
		}
	}
	void RemoveRoot_vect() {
		Node* delPtr = root;
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
			Node* p = Find_smallest();
			RemoveRootPrivate_vect(p, root);
			root->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				root->v[i] = p->v[i];
			}
		}
	}
	void RemoveMatch_vect(Node* parent, Node* match, bool left) {

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
			Node* p = Find_smallestPrivate_vect(match->right);
			RemoveRootPrivate(p, match);
			match->v.resize(p->v.size());
			for (int i = 0; i < root->v.size(); i++) {
				match->v[i] = p->v[i];
			}
		}
	}
	private:
		Node* Find_smallestPrivate(Node* node)
		{
			if (node->left != NULL)
			{
				return Find_smallestPrivate(node->left);
			}
			else { return node; };
		}
		Node* creat_leaf(T e, bool way1) {
			Node* cur = new Node;
			cur->data = e;
			cur->way = way1;
			cur->left = NULL;
			cur->right = NULL;
			cur->id = id++;
			return cur;
		};
		Node* creat_leaf_v(vector<T> v, bool way1) {
			Node* cur = new Node;
			cur->v = v;
			cur->way = way1;
			cur->left = NULL;
			cur->right = NULL;
			return cur;
		};
		
		
		
};
template <class T>
class Functions1 :public BinarySearchTree<int> {
public:
	void FindByTheWay() {
		int count = 0, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (FindByTheWayPrivate(mas, root, count, i, n) == 0)
		{
			cout << "Такого нема";
		}
		delete[]mas;
		system("pause");
	}
	void Delete()
	{
		Node* ptr;
		T inf;
		cout << "Введите, что хотите удалить" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(RemoveNode(ptr));
	}
	void AddLeaf() {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		AddLeafPrivate(inf, root);
	}
	void AddLeaf_vect() {
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
		AddLeafPrivate_v(v, root);
	}
	void Find() {
		Node* ptr;
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(cout << ptr->id << ". " << ptr->data << endl);
		system("pause");
	}
	void PrintInOrder() {
		PrintInOrderPrivate(root);
		system("pause");
	}
	void PrintInOrder_vect() {
		PrintInOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPostOrder() {
		PrintPostOrderPrivate(root);
		system("pause");
	}
	void PrintPostOrder_vect() {
		PrintPostOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPreOrder() {
		PrintPreOrderPrivate(root);
		system("pause");
	}
	void PrintPreOrder_vect() {
		PrintPreOrderPrivate_vect(root);
		system("pause");
	}
	void Find_vect() {
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else{
			cout << ptr->id << ". ";
			for (int i = 0; i < n; i++)
			{
				cout<< v[i];
			}
	         }
		system("pause");
	}
	void Delete_vect()
	{
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(RemoveNode(ptr));
	}
private:

	int FindByTheWayPrivate(bool* mas, Node* node, int count, int i, int n) {
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
					FindByTheWayPrivate(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPostOrderPrivate(Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate(Node* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate_vect(Node* node) {
		if (node != NULL)
		{
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate_vect(struct Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate_vect(node->right);
			}
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] <<' '<<endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate_vect(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node* FindPrivate(T e, Node* node)
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
					FindPrivate(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node* FindPrivate_vect(vector<T> v, Node* node)
	{
		if (node != NULL)
		{

			if (v.size() == node->v.size() && v==node->v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->data)
				{
					FindPrivate_vect(v, node->left);
				}
				else if (v[0] > node->data)
				{
					FindPrivate_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	void RemoveNode(Node* p) {
		RemoveRootPrivate(p, root);
	}
	void RemoveNode_vect(Node* p) {
		RemoveRootPrivate_vect(p, root);
	}
	
};
template <class T>
class Functions2 :public BinarySearchTree<double> {
public:
	void FindByTheWay() {
		int count = 0, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (FindByTheWayPrivate(mas, root, count, i, n) == 0)
		{
			cout << "Такого нема";
		}
		delete[]mas;
		system("pause");
	}
	void Delete()
	{
		Node* ptr;
		T inf;
		cout << "Введите, что хотите удалить" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(RemoveNode(ptr));
	}
	void AddLeaf() {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		AddLeafPrivate(inf, root);
	}
	void AddLeaf_vect() {
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
		AddLeafPrivate_v(v, root);
	}
	void Find() {
		Node* ptr;
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(cout << ptr->id << ". " << ptr->data << endl);
		system("pause");
	}
	void PrintInOrder() {
		PrintInOrderPrivate(root);
		system("pause");
	}
	void PrintInOrder_vect() {
		PrintInOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPostOrder() {
		PrintPostOrderPrivate(root);
		system("pause");
	}
	void PrintPostOrder_vect() {
		PrintPostOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPreOrder() {
		PrintPreOrderPrivate(root);
		system("pause");
	}
	void PrintPreOrder_vect() {
		PrintPreOrderPrivate_vect(root);
		system("pause");
	}
	void Find_vect() {
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
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
	void Delete_vect()
	{
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(RemoveNode(ptr));
	}
private:

	int FindByTheWayPrivate(bool* mas, Node* node, int count, int i, int n) {
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
					FindByTheWayPrivate(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPostOrderPrivate(Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate(Node* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate_vect(Node* node) {
		if (node != NULL)
		{
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate_vect(struct Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate_vect(node->right);
			}
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate_vect(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node* FindPrivate(T e, Node* node)
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
					FindPrivate(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node* FindPrivate_vect(vector<T> v, Node* node)
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
					FindPrivate_vect(v, node->left);
				}
				else if (v[0] > node->data)
				{
					FindPrivate_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	void RemoveNode(Node* p) {
		RemoveRootPrivate(p, root);
	}
	void RemoveNode_vect(Node* p) {
		RemoveRootPrivate_vect(p, root);
	}
};
template <class T>
class Functions3 :public BinarySearchTree<string> {
public:
	void FindByTheWay() {
		int count = 0, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (FindByTheWayPrivate(mas, root, count, i, n) == 0)
		{
			cout << "Такого нема";
		}
		delete[]mas;
		system("pause");
	}
	void Delete()
	{
		Node* ptr;
		T inf;
		cout << "Введите, что хотите удалить" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(RemoveNode(ptr));
	}
	void AddLeaf() {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		AddLeafPrivate(inf, root);
	}
	void AddLeaf_vect() {
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
		AddLeafPrivate_v(v, root);
	}
	void Find() {
		Node* ptr;
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		ptr = FindPrivate(inf, root);
		if (ptr == NULL) { cout << "Такого нема" << endl; }
		else(cout << ptr->id << ". " << ptr->data << endl);
		system("pause");
	}
	void PrintInOrder() {
		PrintInOrderPrivate(root);
		system("pause");
	}
	void PrintInOrder_vect() {
		PrintInOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPostOrder() {
		PrintPostOrderPrivate(root);
		system("pause");
	}
	void PrintPostOrder_vect() {
		PrintPostOrderPrivate_vect(root);
		system("pause");
	}
	void PrintPreOrder() {
		PrintPreOrderPrivate(root);
		system("pause");
	}
	void PrintPreOrder_vect() {
		PrintPreOrderPrivate_vect(root);
		system("pause");
	}
	void Find_vect() {
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
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
	void Delete_vect()
	{
		vector<T> v;
		int n;
		Node* ptr;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		ptr = FindPrivate_vect(v, root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(RemoveNode(ptr));
	}
private:

	int FindByTheWayPrivate(bool* mas, Node* node, int count, int i, int n) {
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
					FindByTheWayPrivate(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintPostOrderPrivate(Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate(node->right);
			}
			cout << node->id << ".";
			cout << node->data << endl;
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate(Node* node) {
		if (node != NULL)
		{
			cout << node->id << ".";
			cout << node->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPreOrderPrivate_vect(Node* node) {
		if (node != NULL)
		{
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintPostOrderPrivate_vect(struct Node* node)
	{
		if (node != NULL)
		{
			if (node->left != NULL)
			{
				PrintPostOrderPrivate_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPostOrderPrivate_vect(node->right);
			}
			cout << node.id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate_vect(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->id << ". "; for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	Node* FindPrivate(T e, Node* node)
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
					FindPrivate(e, node->left);
				}
				else if (e > node->data)
				{
					FindPrivate(e, node->right);
				}
			}
		}
		else { return node; }
	}
	Node* FindPrivate_vect(vector<T> v, Node* node)
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
					FindPrivate_vect(v, node->left);
				}
				else if (v[0]> node->data)
				{
					FindPrivate_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	void RemoveNode(Node* p) {
		RemoveRootPrivate(p, root);
	}
	void RemoveNode_vect(Node* p) {
		RemoveRootPrivate_vect(p, root);
	}
};

int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 9) % 9;
		if (key == 0) cout << "-> Записать int" << endl;
		else  cout << "   Записать int" << endl;
		if (key == 1) cout << "-> Записать string" << endl;
		else  cout << "   Записать string" << endl;
		if (key == 2) cout << "-> Вывести дерево int" << endl;
		else  cout << "   Вывести дерево int" << endl;
		if (key == 3) cout << "-> Вывести дерево string" << endl;
		else  cout << "   Вывести дерево string" << endl;
		if (key == 4) cout << "-> Найти int" << endl;
		else  cout << "   Найти int" << endl;
		if (key == 5) cout << "-> Найти string" << endl;
		else  cout << "   Найти string" << endl;
		if (key == 6) cout << "-> Найти int по пути" << endl;
		else  cout << "   Найти int по пути" << endl;
		if (key == 7) cout << "-> Выход" << endl;
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
	Functions1<int> i;
	Functions2<double> d;
	Functions3<string> s;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0: i.AddLeaf(); break;
		case 1: i.PrintInOrder(); break;
		case 2: i.PrintPreOrder(); break;
		case 3: i.PrintPostOrder(); break;
		case 4: i.Find(); break;
		case 5: i.PrintInOrder(); i.Delete();  break;
		case 6: i.AddLeaf_vect(); break;
		case 7: i.PrintInOrder_vect(); break;
		case 8: i.Find_vect(); break;
		case 9: i.PrintInOrder_vect(); i.Delete_vect(); break;
		case 10: i.FindByTheWay(); break;
		case 11: d.AddLeaf(); break;
		case 12: d.PrintInOrder(); break;
		case 13: d.PrintPreOrder(); break;
		case 14: d.PrintPostOrder(); break;
		case 15: d.Find(); break;
		case 16: d.PrintInOrder(); i.Delete();  break;
		case 17: d.AddLeaf_vect(); break;
		case 18: d.PrintInOrder_vect(); break;
		case 19: d.Find_vect(); break;
		case 20: d.PrintInOrder_vect(); i.Delete_vect(); break;
		case 21: d.FindByTheWay(); break;
		case 22: s.AddLeaf(); break;
		case 23: s.PrintInOrder(); break;
		case 24: s.PrintPreOrder(); break;
		case 25: s.PrintPostOrder(); break;
		case 26: s.Find(); break;
		case 27: s.PrintInOrder(); i.Delete();  break;
		case 28: s.AddLeaf_vect(); break;
		case 29: s.PrintInOrder_vect(); break;
		case 30: s.Find_vect(); break;
		case 31: s.PrintInOrder_vect(); i.Delete_vect(); break;
		case 32: s.FindByTheWay(); break;

	/*	case 6: d.AddLeaf_vect(); break;
		case 7: d.PrintInOrder_vect(); break;
		case 8: s.AddLeaf(); break;
		case 9: s.PrintInOrder(); break;
		case 10: s.AddLeaf_vect(); break;
		case 11: s.PrintInOrder_vect(); break;*/

		/*case 4:tree1.Find(); break;
		case 5:tree2.Find(); break;*/
		
		case 40: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}