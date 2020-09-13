#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;


template<class I, class C>
class Tree
{
  private:
	struct Node {
		I data;
		C inf[10] = {};
		int counter;
		Node* left;
		Node* right;
	};
	Node* root;
	void AddLeafPrivate(C e[], Node* node) {
		if (root == NULL)
		{
			root = creat_leaf(e);
		}
		else if (e[0] <= node->inf[0])
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
		else if (e[0] > node->inf[0])
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
			cout << node->inf << "-" << node->inf << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}

		}
		else(cout << "Пусто" << endl);
	};
	int FindPrivate(C e[], Node* node, int count)
	{
		if (node != NULL)
		{

			if (!strcmp(node->inf, e))
			{
				node->counter++;
				cout << node->inf << endl;
				count++;
			}
			else
			{
				if (e[0] <= node->inf[0])
				{
					node->counter++;
					FindPrivate(e, node->left, count);
				}
				else if (e[0] > node->inf[0])
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
				if (p->inf[0] <= parent->inf[0] && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true) :
						RemoveRootPrivate(p, parent->left);
				}
				else if (p->inf[0] > parent->inf[0] && parent->right != NULL)
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

	Node* creat_leaf(C e[]) {
		Node* cur = new Node;
		strcpy(cur->inf, e);
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	};
	void AddLeaf() {
		char e[50];
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
		char e[50];
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
			strcpy(root->inf, p->inf);
			strcpy(root->inf, p->inf);
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
			strcpy(match->inf, p->inf);
			strcpy(match->inf, p->inf);
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
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Записать в дерево" << endl;
		else  cout << "   Записать в дерево" << endl;
		if (key == 1) cout << "-> Вывести дерево" << endl;
		else  cout << "   Вывести дерево" << endl;
		if (key == 2) cout << "-> Найти перевод слова" << endl;
		else  cout << "   Найти перевод слова" << endl;
		if (key == 3) cout << "-> Вывести новый словарь" << endl;
		else  cout << "   Вывести новый словарь" << endl;
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
	Tree<int, char> tree;
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
		case 0:tree.AddLeaf(); break;
		case 1:tree.PrintInOrder(); break;
		case 2:if (a1 > a2 || (a1 > 0 && a2 > 0 && a1 == a2)) { tree.Find(); a2 = a1; }
			   else(tree.Find()); break;
		//case 3:
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
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}