#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;


template<class T>
class Tree
{
  private:
	struct Node {
		T data;
		int counter;
		Node* left;
		Node* right;
	};
	Node* root;
	void AddLeafPrivate(T e, Node* node) {
		if (root == NULL)
		{
			root = creat_leaf(e);
		}
		else if (e <= node->data)
		{
			if (node->left != NULL)
			{
				AddLeafPrivate(e, node->left);
			}
			else
			{
				node->left = creat_leaf(e);
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
				node->right = creat_leaf(e);
			}
		}
	}
	void PrintInOrderPrivate(Node* node)
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
	};
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

  public:
	Tree() 
	{
		root = NULL;
	}

	Node* creat_leaf(T e) {
		Node* cur = new Node;
		cur->data=e;
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	};
	void AddLeaf() {
		T e;
		cout << "Введите информацию" << endl;
		cin >> e;
		AddLeafPrivate(e, root);
	};
	void PrintInOrder() {
		PrintInOrderPrivate(root);
		system("pause");
	}
	void Find() {
		int count = 0;
		T e;
		cout << "Введите слово, перевод которого хотите узнать" << endl;
		cin >> e;
		count = FindPrivate(e, root, count);
		if (count == 0) { cout << "Такого нема"; }
		system("pause");
	}
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
		if (key == 6) cout << "-> Вывести новый словарь" << endl;
		else  cout << "   Вывести новый словарь" << endl;
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
	Tree<int> tree1;
	Tree<string> tree2;
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
		case 0:tree1.AddLeaf(); break;
		case 1:tree1.PrintInOrder(); break;
		case 2:tree2.AddLeaf(); break;
		case 3:tree2.PrintInOrder(); break;
		case 4:tree1.Find(); break;
		case 5:tree2.Find(); break;
		//case 6:
		//{   a1++;
		//while (tree.root != NULL)
		//{
		//	max = 0;
		//	p = tree1.find_max();
		//	tree2.add_leaf_new(p);
		//	tree1.RemoveNode(p);
		//}
		//tree2.PrintInOrder();
		//break;
		//}
		case 7: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}