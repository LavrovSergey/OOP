/*! Class for working with a template node.*/
#pragma once
#include "Part1.h"
#include "Node.h"
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "NarrayTree.h"
#include <iostream>
#include <string>
using namespace std;
/*! @param T -data type
* @param U -object.*/
template <class T, class U>
class Functions: public  Node<T, U>, public BinarySearchTree<T, U>, public BinaryTree<T, U>, public NarrayTree<T, U>
{
public:
	/*! Search by the way.
	*0-left
	* 1-right
	*/
	void FindByTheWay(int a) {
		bool count = false, i = 0;
		int n;
		cout << "Enter route length" << endl;
		cin >> n;
		bool* mas = new bool[n];
		cout << "Fill in the route" << endl;
		for (int j = 0; j < n; j++) {
			cin >> mas[j];
		}
		if (a == 1) {
			if (FindByTheWayPrivate1(mas, BinarySearchTree<T, U>::root, count, i, n) == 0)
			{
				cout << "There is no such thing";
			}
		}
		else if (a == 2) {
			if (FindByTheWayPrivate2(mas, BinaryTree<T, U>::root, count, i, n) == 0)
			{
				cout << "There is no such thing";
			}
		}
		else {
			if (FindByTheWayPrivate3(mas, NarrayTree<T, U>::root, count, i, n) == 0)
			{
				cout << "There is no such thing";
			}
		}
		delete[]mas;
		system("pause");
	}
	/*! All ways to delete.
	* a==1 by value
	* a==2 by id
	* a==3 by fathers`s node
	*/
	void Delete(int a, int b)
	{
		if (b == 1) {
			T inf;
			cout << "Enter what you want to delete" << endl;
			cin >> inf;
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivate2(inf, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 1));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivate3(inf, NarrayTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (NarrayTree<T, U>::RemoveNode(ptr, NarrayTree<T, U>::root, 1));
			}
		}
		else if (b == 2) {
			int id;
			cout << "Enter id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 1));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 1));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivateId3(id, NarrayTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (NarrayTree<T, U>::RemoveNode(ptr, NarrayTree<T, U>::root, 1));
			}
		}
		else if (b == 3)
		{
			int id;
			cout << "Enter father`s id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode(ptr, BinarySearchTree<T, U>::root, 2));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode(ptr, BinaryTree<T, U>::root, 2));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivateId3(id, NarrayTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (NarrayTree<T, U>::RemoveNode(ptr, NarrayTree<T, U>::root, 2));
			}
		}
	}
	/*! Adding a node for part1.*/
	void AddLeaf(int a) {
		T inf;
		cout << "Enter information" << endl;
		cin >> inf;
		if (a == 1) { BinarySearchTree<T, U>::creat_leaf(inf, 0); }
		else if (a == 2) { BinaryTree<T, U>::root = BinaryTree<T, U>::AddLeaf(BinaryTree<T, U>::root, BinaryTree<T, U>::creat_leaf(inf, 0)); }
		else if (a == 3) { NarrayTree<T, U>::AddLeaf(inf, NarrayTree<T, U>::root); }
	}
	/*! Adding a node for part1.*/
	void AddLeaf_vect(int a) {
		int n;
		T inf;
		vector<T> v;
		cout << "Vector size: " << endl;
		cin >> n;
		cout << "Fill vector" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1) { BinarySearchTree<T, U>::creat_leaf_v(v, 0); }
		else if (a == 2) { BinaryTree<T, U>::root = BinaryTree<T, U>::AddLeaf(BinaryTree<T, U>::root, BinaryTree<T, U>::creat_leaf_v(v, 0)); }
		else if (a == 3) { NarrayTree<T, U>::AddLeaf_v(v, NarrayTree<T, U>::root); }
	}
	/*! Search by the information.*/
	void Find(int a) {
		T inf;
		cout << "Enter what you want to find" << endl;
		cin >> inf;
		if (a == 1)
		{
			Node<T, U>* ptr = FindPrivate1(inf, BinarySearchTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }
			else(cout << ptr->data->id << ". " << ptr->data->data << endl);
			system("pause");
		}
		else if (a == 2)
		{
			Node<T, U>* ptr = FindPrivate2(inf, BinaryTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }
			else(cout << ptr->data->id << ". " << ptr->data->data << endl);
			system("pause");
		}
		else if (a == 3)
		{
			Node<T, U>* ptr = FindPrivate3(inf, NarrayTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }
			else(cout << ptr->data->id << ". " << ptr->data->data << endl);
			system("pause");
		}
	}
	/*! Search by the information.*/
	void Find_vect(int a) {
		T inf;
		vector<T> v;
		int n;
		cout << "Enter vector size:" << endl;
		cin >> n;
		cout << "Enter what you want to find" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> inf;
			v.push_back(inf);
		}
		if (a == 1)
		{
			Node<T, U>* ptr = FindPrivate1_vect(v, BinarySearchTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }                       //тут почему-то не работает но такое же в удалении работает
			else {
				cout << ptr->data->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		else if (a == 2)
		{
			Node<T, U>* ptr = FindPrivate2_vect(v, BinaryTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }
			else {
				cout << ptr->data->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
		else if (a == 3)
		{
			Node<T, U>* ptr = FindPrivate3_vect(v, NarrayTree<T, U>::root);
			if (ptr == NULL) { cout << "There is no such thing" << endl; }
			else {
				cout << ptr->data->id << ". ";
				for (int i = 0; i < n; i++)
				{
					cout << v[i];
				}
			}
			system("pause");
		}
	}
	/*! Print.*/
	void PrintInOrder(int a) {
		if (a == 1) { PrintInOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintInOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintInOrder_vect(int a) {
		if (a == 1) { PrintInOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintInOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPostOrder(int a) {
		if (a == 1) { PrintPostOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPostOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPostOrder_vect(int a) {
		if (a == 1) { PrintPostOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPostOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPreOrder(int a) {
		if (a == 1) { PrintPreOrderPrivate1(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPreOrderPrivate2(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! Print.*/
	void PrintPreOrder_vect(int a) {
		if (a == 1) { PrintPreOrderPrivate1_vect(BinarySearchTree<T, U>::root); }
		else if (a == 2) { PrintPreOrderPrivate2_vect(BinaryTree<T, U>::root); }
		else if (a == 3) { PrintPreOrderPrivate3_vect(NarrayTree<T, U>::root); }
		system("pause");
	}
	/*! All ways to delete.
	* a==1 by value
	* a==2 by id
	* a==3 by fathers`s node
	*/
	void Delete_vect(int a, int b)
	{
		if (b == 1) {
			T inf;
			vector<T> v;
			int n;
			cout << "Enter the size of the vector you want to remove" << endl;
			cin >> n;
			cout << "Enter what you want to delete" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> inf;
				v.push_back(inf);
			}
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivate1_vect(v, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, a));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivate2_vect(v, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, a));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivate3_vect(v, NarrayTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (NarrayTree<T, U>::RemoveNode_vect(ptr, NarrayTree<T, U>::root, a));
			}
		}
		else if (b == 2) {
			PrintPreOrder_vect(a);
			int id;
			cout << "Enter id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, a));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, a));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivateId3(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, NarrayTree<T, U>::root, a));
			}
		}
		else if (b == 3)
		{
			PrintPreOrder_vect(a);
			int id;
			cout << "Enter father`s id" << endl;
			cin >> id;
			if (a == 1)
			{
				Node<T, U>* ptr = FindPrivateId1(id, BinarySearchTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else  (BinarySearchTree<T, U>::RemoveNode_vect(ptr, BinarySearchTree<T, U>::root, 2));
			}
			else if (a == 2)
			{
				Node<T, U>* ptr = FindPrivateId2(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, BinaryTree<T, U>::root, 2));
			}
			else if (a == 3)
			{
				Node<T, U>* ptr = FindPrivateId3(id, BinaryTree<T, U>::root);
				if (ptr == NULL) { cout << "There is no such thing" << endl; }
				else (BinaryTree<T, U>::RemoveNode_vect(ptr, NarrayTree<T, U>::root, 2));
			}
		}
	}
private:
	bool FindByTheWayPrivate1(bool* mas, Node<T, U>* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << "You found it:" << node->data->data << endl;
				count = true;
				return count;
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
	bool FindByTheWayPrivate2(bool* mas, Node<T, U>* node, bool count, int i, int n) {
		if (node != NULL)
		{
			if (i == n)
			{
				cout << "You found it:" << node->data->data << endl;
				count = true;
				return count;
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
	bool FindByTheWayPrivate3(bool* mas, Node<T, U>* node, bool count, int i, int n) {
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
	void PrintInOrderPrivate1(Node<T, U>* node)
	{
		if (BinarySearchTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1(node->left);
			}
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate1(node->right);
			}
		}
		else(cout << "Пусто" << endl);
	}
	void PrintInOrderPrivate2(Node<T, U>* node) {
		if (BinaryTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Empty" << endl);
	};
	void PrintPreOrderPrivate1(Node<T, U>* node) {
		if (node != NULL)
		{
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	void PrintPreOrderPrivate2(Node<T, U>* node) {
		if (node != NULL)
		{
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	void PrintPreOrderPrivate3(Node<T, U>* node)
	{
		while (node)
		{
			cout << node->data->id << ". " << node->data->data;
			if (node->left)
			{
				PrintPreOrderPrivate3(node->left);
			}
			node = node->right;
		}
	}
	void PrintPostOrderPrivate1(Node<T, U>* node)
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
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
		}
		else(cout << "Empty" << endl);
	}
	void PrintPostOrderPrivate2(Node<T, U>* node)
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
			cout << node->data->id << ". ";
			cout << node->data->data << endl;
		}
		else(cout << "Empty" << endl);
	}
	Node<T, U>* FindPrivate1(T inf, Node<T, U>* node)
	{
		if (node != NULL)
		{
			if (node->data->data == inf)
			{
				return node;
			}
			else
			{
				if (inf <= node->data->data)
				{
					FindPrivate1(inf, node->left);
				}
				else if (inf > node->data->data)
				{
					FindPrivate1(inf, node->right);
				}
			}
		}
		else { return node; }
	}
	Node<T, U>* FindPrivate2(T inf, Node<T, U>* node)
	{
		if (node == NULL) return node;
		if (inf == node->data->data) {
			return node;
		}
		Node<T, U>* tmp1 = FindPrivate2(inf, node->left);
		if (tmp1 != NULL) {
			if (inf == tmp1->data->data) { return tmp1; }
		}
		Node<T, U>* tmp2 = FindPrivate2(inf, node->right);
		if (tmp2 != NULL) {
			if (inf == tmp2->data->data) { return tmp2; }
		}
	}
	Node<T, U>* FindPrivate3(T inf, Node<T, U>* node) {
		if (node != NULL)
		{
			if (node->data->data == inf)
			{
				return node;
			}
			else
			{
				if (node->left) {
					if (inf <= node->left->data->data)
					{
						FindPrivate3(inf, node->left);
					}
					else if (inf > node->left->data->data)
					{
						FindPrivate3(inf, node->left->right);
					}
				}
				else {
					FindPrivate3(inf, node->right);
				}
			}
		}
		else { return node; }
	}
	Node<T, U>* FindPrivateId1(int id, Node<T, U>* node) {
		if (node == NULL) return node;
		if (id == node->data->id) {
			return node;
		}
		Node<T, U>* tmp1 = FindPrivateId1(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->data->id) { return tmp1; }
		}
		Node<T, U>* tmp2 = FindPrivateId1(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->data->id) { return tmp2; }
		}
	}
	Node<T, U>* FindPrivateId2(int id, Node<T, U>* node) {
		if (node == NULL) return node;
		if (id == node->data->id) {
			return node;
		}
		Node<T, U>* tmp1 = FindPrivateId2(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->data->id) { return tmp1; }
		}
		Node<T, U>* tmp2 = FindPrivateId2(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->data->id) { return tmp2; }
		}
	}
	Node<T, U>* FindPrivateId3(int id, Node<T, U>* node)
	{
		while (node)
		{
			if (id == node->data->id) { return node; }
			if (node->left)
			{
				FindPrivateId3(id, node->left);
			}
			node = node->right;
		}
		return 0;
	}
	void PrintPreOrderPrivate1_vect(Node<T, U>* node) {
		if (node != NULL)
		{
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate1_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	void PrintPreOrderPrivate2_vect(Node<T, U>* node) {
		if (node != NULL)
		{
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
			if (node->left != NULL)
			{
				PrintPreOrderPrivate2_vect(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate2_vect(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	void PrintPreOrderPrivate3_vect(Node<T, U>* node)
	{
		while (node)
		{
			cout << node->data->id << ". ";
			for (int i = 0; i < node->data->v.size(); i++) {
				cout << node->data->v[i] << " ";
			}
			cout << endl;
			if (node->left)
			{
				PrintPreOrderPrivate3_vect(node->left);
			}
			node = node->right;
		}
	}
	void PrintPostOrderPrivate1_vect(Node<T, U>* node)
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
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
		}
		else(cout << "Empty" << endl);
	}
	void PrintPostOrderPrivate2_vect(Node<T, U>* node)
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
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
		}
		else(cout << "Empty" << endl);
	}
	void PrintInOrderPrivate1_vect(Node<T, U>* node)
	{
		if (BinarySearchTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate1_vect(node->left);
			}
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate1_vect(node->right);
			}
		}
		else(cout << "Empty" << endl);
	};
	void PrintInOrderPrivate2_vect(Node<T, U>* node)
	{
		if (BinaryTree<T, U>::root != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate2(node->left);
			}
			cout << node->data->id << ". "; for (int i = 0; i < node->data->v.size(); i++) { cout << node->data->v[i] << ' ' << endl; }
			if (node->right != NULL)
			{
				PrintInOrderPrivate2(node->right);
			}
		}
		else(cout << "Empty" << endl);
	};
	Node<T, U>* FindPrivate1_vect(vector<T> v, Node<T, U>* node)
	{
		if (node != NULL)
		{
			if (node->data->v == v)
			{
				return node;
			}
			else
			{
				if (v[0] <= node->data->v[0])
				{
					FindPrivate1_vect(v, node->left);
				}
				else if (v[0] > node->data->v[0])
				{
					FindPrivate1_vect(v, node->right);
				}
			}
		}
		else {
			return 0;
		}
	}
	Node<T, U>* FindPrivate2_vect(vector<T> v, Node<T, U>* node)
	{
		if (node == NULL) return node;
		if (v == node->data->v) { return node; }
		Node<T, U>* tmp1 = FindPrivate2_vect(v, node->left);
		if (tmp1 != NULL) {
			if (v == node->data->v)
			{
				return tmp1;
			}
		}
		Node<T, U>* tmp2 = FindPrivate2_vect(v, node->right);
		if (tmp2 != NULL) {
			if (v == node->data->v)
			{
				return tmp2;
			}
		}
	}
	Node<T, U>* FindPrivate3_vect(vector<T> v, Node<T, U>* node)
	{
		if (node != NULL)
		{
			if (node->data->v == v)
			{
				return node;
			}
			else
			{
				if (node->left) {
					if (v[0] <= node->left->data->v[0])
					{
						FindPrivate3_vect(v, node->left);
					}
					else if (v[0] > node->left->data->v[0])
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
};
