/*! Class for working with a template node.*/
#pragma once
#include "Node1.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "TreeChildrenList.h"
#include <iostream>
using namespace std;
/*! @param T -data type
* @param U -object.*/
template <class T, class U>
class Functions: public BinarySearchTree<T, U>, public BinaryTree<T, U>, public TreeChildrenList<T, U>
{
public:
	friend class Node<T>; 
	/*! Search by the way.*/
	void FindByTheWay(int a) {
		bool count = false, i = 0;
		int n;
		cout << "Введите длину маршрута" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Заполните маршрут" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree<T, U>::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree<T, U>::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		else {
			if (FindByTheWayPrivate3(mas, TreeChildrenList<T, U>::root, count, i, n) == 0)
			{
				cout << "Такого нема";
			}
		}
		delete[]mas;
		system("pause");
	}
	/*! All ways to delete.*/
	void Delete(int a, int b)
	{
		if (b == 1) {
			T inf;
			cout << "Введите, что хотите удалить" << endl;
			cin >> inf;
			if (a == 1)
			{
				U* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivate2(inf, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 1));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivate3(inf, TreeChildrenList<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList<T, U>::RemoveNode(ptr, TreeChildrenList<T, U>::root, 1));
			}
		}
		else if (b == 2) {
			PrintPreOrder(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 1));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivateId3(id, TreeChildrenList<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList<T, U>::RemoveNode(ptr, TreeChildrenList<T, U>::root, 1));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 2));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 2));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivateId3(id, TreeChildrenList<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList<T, U>::RemoveNode(ptr, TreeChildrenList<T, U>::root, 2));
			}
		}
	}
	/*! Adding a node.*/
	void AddLeaf(int a) {
		T inf;
		cout << "Введите информацию" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree<T, U>::creat_leaf(inf, 0); }
		else if (a == 2) { BinaryTree<T, U>::root = BinaryTree<T, U>::AddLeaf(BinaryTree<T, U>::root, BinaryTree<T, U>::creat_leaf(inf, 0)); }
		else if (a == 3) { TreeChildrenList<T, U>::AddLeaf(inf, TreeChildrenList<T, U>::root); }
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
		if (a == 1) { BinarySearchTree<T, U>::creat_leaf_v(v, 0); }
		else if (a == 2) { BinaryTree<T, U>::root = BinaryTree<T, U>::AddLeaf_v(BinaryTree<T, U>::root, BinaryTree<T, U>::creat_leaf_v(v, 0)); }
		else if (a == 3) { TreeChildrenList<T, U>::AddLeaf_v(v, TreeChildrenList<T, U>::root); }
	}
	/*! Search by the information.*/
	void Find(int a) {
		T inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
		if (a == 1)
		{
			U* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			U* ptr = FindPrivate2(inf, BinaryTree<T, U>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
		else if (a == 3)
		{
			U* ptr = FindPrivate3(inf, TreeChildrenList<T, U>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else(cout << ptr->id << ". " << ptr->data << endl);
			system("pause");
		}
	}
	/*! Print.*/
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(TreeChildrenList<T, U>::root); }
		system("pause");
	}
	void Find_vect(int a) {
		T inf;
		vector<T> v;
		int n;
		cout << "Введите размер вектора" << endl;
		cin >> n;
		cout << "Введите, что хотите найти" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1)
		{
			U* ptr = FindPrivate1_vect(v, BinarySearchTree<T, U>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }                       //тут почему-то не работает но такое же в удалении работает
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
			U* ptr = FindPrivate2_vect(v, BinaryTree<T, U>::root);
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
		if (a == 3)
		{
			U* ptr = FindPrivate3_vect(v, TreeChildrenList<T, U>::root);
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
	void Delete_vect(int a, int b)
	{
		if (b == 1) {
			T inf;
			vector<T> v;
			int n;
			cout << "Введите размер вектора, который хотите удалить" << endl;
			cin >> n;
			cout << "Введите, что хотите удалить" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1)
			{
				U* ptr = FindPrivate1_vect(v, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, a));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivate2_vect(v, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, a));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivate3_vect(v, TreeChildrenList<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (TreeChildrenList<T, U>::RemoveNode_vect(ptr, TreeChildrenList<T, U>::root, a));
			}

		}
		else if (b == 2) {
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id" << endl;
			cin >> id;
			if (a == 1)
			{
				U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, a));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, a));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivateId3(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, TreeChildrenList<T, U>::root, a));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder_vect(a);
			int id;
			cout << "Введите id отца" << endl;
			cin >> id;
			if (a == 1)
			{
				U* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, 2));
			}
			else if (a == 2)
			{
				U* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, 2));
			}
			else if (a == 3)
			{
				U* ptr = FindPrivateId3(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "Такого нема" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, TreeChildrenList<T, U>::root, 2));
			}
		}
	}
private:
	bool FindByTheWayPrivate1(bool* mas, U* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
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
	bool FindByTheWayPrivate2(bool* mas, U* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
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
	bool FindByTheWayPrivate3(bool* mas, U* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << node->data << endl;
				count = true;
			}
			else
			{
				if (mas[i] == 0)
				{
					i++;
					FindByTheWayPrivate3(mas, node->left, count, i, n);
				}
				else
				{
					i++;
					FindByTheWayPrivate3(mas, node->right, count, i, n);
				}
			}
		}
		else { return count; }
	}
	void PrintInOrderPrivate1(U* node)
	{
		if (BinarySearchTree<T, U>::root != NULL)
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
	void PrintInOrderPrivate2(U* node) {
		if (BinaryTree<T, U>::root != NULL)
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
	void PrintPreOrderPrivate1(U* node) {
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
	void PrintPreOrderPrivate2(U* node) {
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
	void PrintPreOrderPrivate3(U* node)
	{
		while (node)
		{
			cout << node->id << ". " << node->data;
			if (node->left)
			{
				PrintPreOrderPrivate3(node->left);
			}
			node = node->right;
		}
	}
	void PrintPostOrderPrivate1(U* node)
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
	void PrintPostOrderPrivate2(U* node)
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
	void PrintPreOrderPrivate1_vect(U* node) {
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
	void PrintPreOrderPrivate2_vect(U* node) {
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
	void PrintPreOrderPrivate3_vect(U* node)
	{
		while (node)
		{
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) {
				cout << node->v[i] << " ";
			}
			cout << endl;
			if (node->left)
			{
				PrintPreOrderPrivate3_vect(node->left);
			}
			node = node->right;
		}
	}
	void PrintPostOrderPrivate1_vect(U* node)
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
	void PrintPostOrderPrivate2_vect(U* node)
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
	void PrintInOrderPrivate1_vect(U* node)
	{
		if (BinarySearchTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1_vect(node->left);
			}
			cout << node->id << ". ";
			for (int i = 0; i < node->v.size(); i++) { cout << node->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	};
	void PrintInOrderPrivate2_vect(U* node)
	{
		if (BinaryTree<T, U>::root != NULL)
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
	U* FindPrivate1(T e, U* node)
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
	U* FindPrivate2(T inf, U* node)
	{
		if (node == NULL) return node;

		if (inf == node->data) {
			return node;
		}
		U* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data) { return tmp1; }
		}
		U* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data) { return tmp2; }
		}
	}
	U* FindPrivate3(T e, U* node) {
		if (node != NULL)
		{
			if (node->data == e)
			{
				return node;
			}
			else

			{
				if (node->left) {
					if (e <= node->left->data)
					{
						FindPrivate3(e, node->left);
					}
					else if (e > node->left->data)
					{
						FindPrivate3(e, node->left->right);
					}
				}
				else {
					FindPrivate3(e, node->right);
				}
			}
		}
		else { return node; }
	}
	U* FindPrivate1_vect(vector<T> v, U* node)
	{
		if (node != NULL)
		{

			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->v[0])
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->v[0])
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else {
			return 0;
		}
	}
	U* FindPrivate2_vect(vector<T> v, U* node)
	{
		if (node == NULL) return node;

		if (v == node->v) { return node; }
		U* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v.size() == tmp1->v.size() && v == node->v)
			{
				return tmp1;
			}
		}
		U* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v.size() == tmp2->v.size() && v == node->v)
			{
				return tmp2;
			}
		}
	}
	U* FindPrivate3_vect(vector<T> v, U* node)
	{
		if (node != NULL)
		{
			if (node->v == v)
			{
				return node;
			}
			else
			{
				if (node->left) {
					if (v[0] <= node->left->v[0])
					{
						FindPrivate3_vect(v, node->left);
					}
					else if (v[0] > node->left->v[0])
					{
						FindPrivate3_vect(v, node->left->right);
					}
				}
				else {
					FindPrivate3_vect(v, node->right);
				}
			}
		}
		else { return node; }
	}
	U* FindPrivateId1(int id, U* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		U* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		U* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	U* FindPrivateId2(int id, U* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		U* tmp1 = FindPrivateId2(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		U* tmp2 = FindPrivateId2(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	U* FindPrivateId3(int id, U* node)
	{
		while (node)
		{
			if (id == node->id) { return node; }
			if (node->left)
			{
				FindPrivateId3(id, node->left);
			}
			node = node->right;
		}
		return 0;
	}
};
