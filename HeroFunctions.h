#pragma once
#include "Node.h"
#include "Hero.h"
#include "BinarySearchTree.h"
#include"BookFunctions.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with character.*/
template <class T, class U>
class HeroFunctions  
{
public:
int	id = 1;
	BinarySearchTree<string, U> bst;
	BookFunctions<T,Book> bf;
	/*void FromFile() {
		ifstream heroes("heroes.bin");
		if (heroes.peek() != EOF) {
			FromFilePrivate(heroes);
		}
	}*/
	/*! Write to file.*/
	/*void InFile() {
		ofstream heroes("heroes.bin");
		InFilePrivate(BinarySearchTree<string, Node<T, U>>::root, heroes);
		heroes.close();
	}*/
	/*void Update() {
		PrintInOrder();
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node<T, U>* ptr = FindPrivateId(id, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr == NULL) { cout << "I cant find" << endl; }
		else  (UpdatePrivate(ptr));
		system("pause");
	}*/
	static bool comparator(Book* & aa, Book* & bb) {

		 Book& a = *aa;
		 Book& b = *bb;

		if (a.GetYear() < b.GetYear()) return true;
		if (a.GetYear() > b.GetYear()) return false;
		if (a.GetMonth() < b.GetMonth()) return true;
		if (a.GetMonth() > b.GetMonth()) return false;
		return a.GetDay() < b.GetDay();
	}
	/*! Add a character.*/
	void AddHero(Node<Book>* r) {
		int a;
		vector<Book*> books;
		vector<string> names;
		int n; string s, data;
		multimap<int, Node<Book>*> role;
		cout << "Enter character name" << endl;
		getline(cin, data);
		cout << "Enter the number of his aliases / names" << endl;
		cin >> n;
		cout << "Fill them in " << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			names.push_back(s);
		}
		cout << "Enter the number of books in which it appears" << endl;
		cin >> n;
		cout << "Fill the book and its role in it " << endl;
		for (int i = 0; i < n; i++) {
            cout << "Choose book ID" << endl;
			bf.PrintInOrder(r);
			cin >> a;
			Node<Book>* ptr = bf.FindId(a, r);
			cout << "What is his role (1-main, 2-minor, 3-episodic)" << endl;
			cin >> a;
			cin.ignore(1, '\n');
			role.insert(pair<int, Node<Book>*>(a, ptr));
			if(a==1 || a==2){books.push_back(ptr->data);}
		}
		sort(books.begin(), books.end(), comparator);
		Hero* h = new Hero(data, n, names, role, id, books );
		id++;
		bst.AddLeaf(h, bst.GetRoot());
	}
	/*! Delete by id.*/
	void Delete()
	{
		PrintInOrder();
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node<U>* ptr = FindPrivateId(id, bst.GetRoot());
		if (ptr == NULL) { cout << "There is no such thing" << endl; }
		else  (bst.RemoveNode(ptr, bst.GetRoot(), 1));
	}
	/*! Print.*/
	void PrintInOrder() {
		PrintPreOrderPrivate(bst.GetRoot());
		system("pause");
	}
	/*! Find.*/
	void Find() {
		string inf;
		cout << "Enter what you want to find" << endl;
		cin >> inf;
		Node< U>* ptr2 = FindPrivate(inf, bst.GetRoot());
		if (ptr2 == NULL) { cout << "There is no such thing" << endl; }
		else {
			PrintHero(ptr2);
		}
		system("pause");
	}
	
	/*vector<Book> Series() {
		vector<string>name;
		SeriesPrivate(BinarySearchTree<string, Node<T, U>>::root, name);
	}*/
private:
	/*void SeriesPrivate(Node<T, U>* node, vector<string>name) {
		if (node != NULL)
		{
			for (auto it = node->data->hb.begin(); it != node->data->hb.end(); ++it)
			{
				if (it->first == 1 || it->first == 2)
				{
					name.push_back(it->second);
				}
			}
			cout << "These books belong to one series: ";
			for (int i = 0; i < name.size(); i++) {
				if (i <= name.size() - 1) { cout << name[i] << ','; }
				else(cout << name[i]);
			}
			cout << endl;
			system("pause");
			if (node->left != NULL)
			{
				SeriesPrivate(node->left, name);
			}
			if (node->right != NULL)
			{
				SeriesPrivate(node->right, name);
			}
		}
		else { cout << "Empty" << endl; }

	}*/
	Node<U>* FindPrivate(string name, Node< U>* node)
	{
		if (node != NULL)
		{
			if (node->data->GetData(0) == name)
			{
				return node;
			}
			else
			{
				if (name <= node->data->GetData(0))
				{
					FindPrivate(name, node->left);
				}
				else if (name > node->data->GetData(0))
				{
					FindPrivate(name, node->right);
				}
			}
		}
		else { return node; }
	}
	void PrintHero(Node< U>* node) {
		cout << node->data->GetId() << ". ";
		cout << "Name: " << node->data->GetData(0) << endl;
		cout << "Aliases: ";
		for (int i = 0; i < node->data->GetVectorSize(); i++)
		{
			cout << node->data->GetName(i);
			if (i < node->data->GetVectorSize() - 1) { cout << ", "; }
			else(cout << endl);
		}
		multimap<int, Node<Book>*> role = node->data->GetRole();
		cout << "Role-Book: "<<endl;
		for (auto it = role.begin(); it != role.end(); ++it)
		{
			if (it->first == 1) { cout << "main" << " -- " << it->second->data->GetData(0) << endl; }
			else if (it->first == 2) { cout << "minor" << " -- " << it->second->data->GetData(0) << endl; }
			else if (it->first == 3) { cout << "episodic" << " -- " << it->second->data->GetData(0) << endl; }
		}
	}
	void PrintPreOrderPrivate(Node<U>* node) {
		if (node != NULL)
		{
			PrintHero(node);
			if (node->left != NULL)
			{
				PrintPreOrderPrivate(node->left);
			}
			if (node->right != NULL)
			{
				PrintPreOrderPrivate(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
	Node<U>* FindPrivateId(int id, Node<U>* node) {
		if (node == NULL) return node;
		if (id == node->data->GetId()) {
			return node;
		}
		Node< U>* tmp1 = FindPrivateId(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->data->GetId()){ return tmp1; }
		}
		Node<U>* tmp2 = FindPrivateId(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->data->GetId()){ return tmp2; }
		}
	}
	/*void UpdatePrivate(Node<T, U>* node) {
		int a;
		string s;
		cout << "Enter character name" << endl;
		getline(cin, node->data->data);
		cout << "Enter the number of his aliases / names" << endl;
		cin >> node->data->v;
		cout << "Fill them in " << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < node->data->v; i++) {
			getline(cin, s);
			node->data->names.push_back(s);
		}
		cout << "Enter the number of books in which it appears" << endl;
		cin >> node->data->m;
		cout << "Fill in the title of the books and its role in them " << endl;
		for (int i = 0; i < node->data->m; i++) {
			cout << "What is his role (1-main, 2-minor, 3-episodic)" << endl;
			cin >> a;
			cin.ignore(1, '\n');
			cout << "Enter the title of the book" << endl;
			getline(cin, s);
			node->data->hb.insert(pair<int, string>(a, s));
		}
	}*/
	//void FromFilePrivate(ifstream& heroes) {
	//	while (!heroes.eof()) {
	//		Hero* b = new Hero;
	//		string s;
	//		heroes.read((char*)&b->data->v, sizeof(int));
	//		if (heroes.eof()) { break; }
	//		for (int i = 0; i < b->data->v; i++) {
	//			heroes.read((char*)&s, sizeof(string)); b->data->names.push_back(s);         //  Âûçâàíî èñêëþ÷åíèå: íàðóøåíèå äîñòóïà äëÿ ÷òåíèÿ._Pnext áûëî 0x2BACC0F0A08.
	//		}
	//		//multimap
	//		heroes.read((char*)&b->data->m, sizeof(int));
	//		BinarySearchTree<string, Hero>::AddLeaf(b, BinarySearchTree<string, Node<T, U>>::root);
	//	}
	//}
	/*void InFilePrivate(Node<T, U>* node, ostream& heroes) {

		if (node->left != NULL)
		{
			InFilePrivate(node->left, heroes);
		}
		if (node != NULL) {
			heroes.write((char*)&node->data->v, sizeof(int));
			for (int i = 0; i < node->data->v; i++) {
				heroes.write((char*)&node->data->names[i], sizeof(string));
			}
			heroes.write((char*)&node->data->m, sizeof(int));
			for (int i = 0; i < node->data->m; i++) {
				heroes.write((char*)&node->data->names[i], sizeof(string));
			}
		}
		if (node->right != NULL)
		{
			InFilePrivate(node->right, heroes);
		}
	}*/
};