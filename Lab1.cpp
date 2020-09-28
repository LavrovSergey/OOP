#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <conio.h>
#include "windows.h"

using namespace std;
template<class T>
class BinarySearchTree
{
public:
	  struct Node {
		  T data;
		  vector<T> v;
		  bool way;
		  int counter;
		  Node* left;
		  Node* right;
	  };
	  Node* creat_leaf(T e, bool way1) {
		  Node* cur = new Node;
		  cur->data = e;
		  cur->way = way1;
		  cur->left = NULL;
		  cur->right = NULL;
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
	/*void PrintInOrderPrivate(Node* node)
	{
		if (root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			cout << node->data << "-" << node->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}

		}
		else(cout << "Пусто" << endl);
	};*/
	int FindPrivate(T e, Node* node, int count)
	{
		if (node != NULL)
		{

			if (node->data==e)
			{
				node->counter++;
				cout << node->data << endl;
				count++;
			}
			else
			{
				if (e <= node->data)
				{
					node->counter++;
					FindPrivate(e, node->left, count);
				}
				else if (e > node->data)
				{
					node->counter++;
					FindPrivate(e, node->right, count);
				}
			}
		}
		else { return count; }
	}
	Node* Find_maxPrivate(Node* node) {
		if (node == NULL) { return 0; }
		Node* tmp = Find_maxPrivate(node->left);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		tmp = Find_maxPrivate(node->right);
		if (tmp != NULL && tmp->counter > node->counter) { node = tmp; }
		return node;
	}
	Node* Find_smallestPrivate(Node* node) {
		if (node->left != NULL)
		{
			return Find_smallestPrivate(node->left);
		}
		else
		{
			return node;
		}
	}
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
				if (p->data[0] <= parent->data[0] && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true) :
						RemoveRootPrivate(p, parent->left);
				}
				else if (p->data[0] > parent->data[0] && parent->right != NULL)
				{
					parent->right == p ?
						RemoveMatch(parent, parent->right, false) :
						RemoveRootPrivate(p, parent->right);
				}
			}
		}
	}
	int FindByTheWayPrivate(bool*mas, Node* node, int count, int i, int n) {
			if (node != NULL)
			{
				if ( i==n)
				{
					cout << node->data << endl;
					count++;
				}
				else
				{
					if (mas[i]==0)
					{
						i++;
						FindByTheWayPrivate(mas, node->left, count, i,n);
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
	
	  Node* root;
	BinarySearchTree() 
	{
		root = NULL;
	}
	
	/*void PrintInOrder() {
		PrintInOrderPrivate(root);
		system("pause");
	}*/
	/*void Find() {
		int count = 0;
		T e;
		cout << "Введите слово, перевод которого хотите узнать" << endl;
		cin >> e;
		count = FindPrivate(e, root, count);
		if (count == 0) { cout << "Такого нема"; }
		system("pause");
	}*/
	Node* Find_max() {
		return Find_maxPrivate(root);
	}
	Node* Find_smallest()
	{
		return Find_smallestPrivate(root);
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
			strcpy(root->data, p->data);
			strcpy(root->data, p->data);
			root->counter = p->counter;

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
			strcpy(match->data, p->data);
			strcpy(match->data, p->data);
			match->counter = p->counter;
		}
	}
	void RemoveNode(Node* p) {
		RemoveRootPrivate(p, root);
	}
	void FindByTheWay() {
		int count = 0, i=0;
		int n;
		cout << "Введите длину маршрута"<<endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n;j++) {
			cin >> mas[j];
		}
		if (FindByTheWayPrivate(mas, root, count, i, n) == 0) 
		{ 
			cout << "Такого нема"; 
		}
		delete[]mas;
		system("pause");
	}
};
template <class T>
class Functions :private BinarySearchTree<int> {
public:
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
	Functions<int>f;
	vector<int>a;
	BinarySearchTree<int> tree1;
	BinarySearchTree<decltype(a)> tree2;                         //vector dont want to work
	int a1 = 0, a2 = 0;
	int max = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0: f.AddLeaf(); break;
		/*case 1:tree1.PrintInOrder(); break;*/
		case 2:f.AddLeaf_vect(); break;
		//case 3:tree2.PrintInOrder(); break;
		/*case 4:tree1.Find(); break;
		case 5:tree2.Find(); break;*/
		case 6:tree1.FindByTheWay();break; 
		case 7: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}