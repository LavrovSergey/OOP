﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"

using namespace std;

class Tree
{
  private:
	struct Node {
		char eng[50];
		char ukr[50];
		int counter;
		Node* left;
		Node* right;
	};
	Node* root;
	void AddLeafPrivate(char e[], char u[], Node* node, int c) {
		if (root == NULL)
		{
			root = creat_leaf(e, u, c);
		}
		else if (e[0] <= node->eng[0])
		{
			if (node->left != NULL)
			{
				AddLeafPrivate(e, u, node->left, c);
			}
			else
			{
				node->left = creat_leaf(e, u, c);
			}
		}
		else if (e[0] > node->eng[0])
		{
			if (node->right != NULL)
			{
				AddLeafPrivate(e, u, node->right, c);
			}
			else
			{
				node->right = creat_leaf(e, u, c);
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
			cout << node->eng << "-" << node->ukr << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}

		}
		else(cout << "Пусто" << endl);
	};
	int FindPrivate(char e[], Node* node, int count)
	{
		if (node != NULL)
		{

			if (!strcmp(node->eng, e))
			{
				node->counter++;
				cout << node->ukr << endl;
				count++;
			}
			else
			{
				if (e[0] <= node->eng[0])
				{
					node->counter++;
					FindPrivate(e, node->left, count);
				}
				else if (e[0] > node->eng[0])
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
				if (p->eng[0] <= parent->eng[0] && parent->left != NULL)
				{
					parent->left == p ?
						RemoveMatch(parent, parent->left, true) :
						RemoveRootPrivate(p, parent->left);
				}
				else if (p->eng[0] > parent->eng[0] && parent->right != NULL)
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
	Node* creat_leaf(char e[], char u[], int c) {
		Node* cur = new Node;
		strcpy(cur->eng, e);
		strcpy(cur->ukr, u);
		cur->counter = c;
		cur->left = NULL;
		cur->right = NULL;
		return cur;
	};
	void AddLeaf() {
		char e[50], u[50];
		int c;
		cout << "Введите английское слово" << endl;
		cin >> e;
		cout << "Введите украинский перевод" << endl;
		cin >> u;
		cout << "Введите счетчик" << endl;
		cin >> c;
		AddLeafPrivate(e, u, root, c);
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
			strcpy(root->eng, p->eng);
			strcpy(root->ukr, p->ukr);
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
			strcpy(match->eng, p->eng);
			strcpy(match->ukr, p->ukr);
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
		if (key == 0) cout << "-> Добавить слово" << endl;
		else  cout << "   Добавить слово" << endl;
		if (key == 1) cout << "-> Вывести исходный словарь" << endl;
		else  cout << "   Вывести исходный словарь" << endl;
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
	Tree tree;
	int a1 = 0, a2 = 0;
	Tree1 tree1;
	Tree2 tree2;
	Node* p;
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
		case 0:tree1.add_leaf(); break;
		case 1:tree1.PrintInOrder(); break;
		case 2:if (a1 > a2 || (a1 > 0 && a2 > 0 && a1 == a2)) { tree2.find(); a2 = a1; }
			   else(tree1.find()); break;
		case 3:
		{   a1++;
		while (tree1.root != NULL)
		{
			max = 0;
			p = tree1.find_max();
			tree2.add_leaf_new(p);
			tree1.RemoveNode(p);
		}
		tree2.PrintInOrder();
		break;
		}
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}