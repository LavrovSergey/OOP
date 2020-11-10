#pragma once
#include "Node.h"
#include "Hero.h"
#include "BinarySearchTree.h"
#include <fstream>
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with character.*/
template <class T, class U>
class HeroFunctions : public  Node<T, U>, public BinarySearchTree<T, U>
{
public:
	/*void FromFile() {
		ifstream heroes("heroes.bin");
		if (heroes.peek() != EOF) {
			FromFilePrivate(heroes);
		}
	}*/
	/*! Write to file.*/
	void InFile() {
		ofstream heroes("heroes.bin");
		InFilePrivate(BinarySearchTree<string, Node<T, U>>::root, heroes);
		heroes.close();
	}
	void Update() {
		PrintInOrder();
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node<T, U>* ptr = FindPrivateId(id, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr == NULL) { cout << "I cant find" << endl; }
		else  (UpdatePrivate(ptr));
		system("pause");
	}
	/*! Add a character.*/
	void AddHero() {
		int a;
		Hero* h=new Hero;
		int n; string s;
		cout << "Enter character name" << endl;
		getline(cin, h->data);
		cout << "Enter the number of his aliases / names" << endl;
		cin >> n;
		cout << "Fill them in " << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			h->names.push_back(s);
		}
		cout << "Enter the number of books in which it appears" << endl;
		cin >> n;
		cout << "Fill in the title of the books and its role in them " << endl;
		for (int i = 0; i < n; i++) {
			cout << "What is his role (1-main, 2-minor, 3-episodic)" << endl;
			cin >> a;
			cin.ignore(1, '\n');
			cout << "Enter the title of the book" << endl;
			getline(cin, s);
			h->hb.insert(pair<int, string>(a, s));
		}
		BinarySearchTree<string, Node<T, U>>::AddLeaf(h, BinarySearchTree<string, Node<T, U>>::root);
	}
	/*! Delete by number.*/
	void Delete()
	{
		PrintInOrder();
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node<T, U>* ptr = FindPrivateId(id, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr == NULL) { cout << "There is no such thing" << endl; }
		else  (BinarySearchTree<string, Node<T, U>>::RemoveNode(ptr, BinarySearchTree<string, Node<T, U>>::root, 1));
	}
	/*! Print.*/
	void PrintInOrder() {
		PrintPreOrderPrivate(BinarySearchTree<string, Node<T, U>>::root);
		system("pause");
	}
	/*! Find.*/
	void Find() {
		string inf;
		cout << "Enter what you want to find" << endl;
		cin >> inf;
		Node<T, U>* ptr2 = FindPrivate(inf, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr2 == NULL) { cout << "There is no such thing" << endl; }
		else {
			PrintHero(ptr2);
		}
		system("pause");
	}
	/*! Print series.*/
	void Series() {
		vector<string>name;
		SeriesPrivate(BinarySearchTree<string, Node<T, U>>::root, name);
	}
private:
	void SeriesPrivate(Node<T, U>* node, vector<string>name) {
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

	}
	Node<T, U>* FindPrivate(string name, Node<T, U>* node)
	{
		if (node != NULL)
		{
			if (node->data->data == name)
			{
				return node;
			}
			else
			{
				if (name <= node->data->data)
				{
					FindPrivate(name, node->left);
				}
				else if (name > node->data->data)
				{
					FindPrivate(name, node->right);
				}
			}
		}
		else { return node; }
	}
	void PrintHero(Node<T, U>* node) {
		cout << node->data->id << ". ";
		cout << "Name: " << node->data->data << endl;
		cout << "Aliases: ";
		for (int i = 0; i < node->data->names.size(); i++)
		{
			cout << node->data->names[i];
			if (i <= node->data->names.size() - 1) { cout << ", "; }
			else(cout << endl);
		}
		cout << "Role-Book: ";
		for (auto it = node->data->hb.begin(); it != node->data->hb.end(); ++it)
		{
			cout << it->first << " -- " << it->second << endl;
		}
	}
	void PrintPreOrderPrivate(Node<T, U>* node) {
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
	Node<T, U>* FindPrivateId(int id, Node<T, U>* node) {
		if (node == NULL) return node;
		if (id == node->data->id) {
			return node;
		}
		Node<T, U>* tmp1 = FindPrivateId(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->data->id) { return tmp1; }
		}
		Node<T, U>* tmp2 = FindPrivateId(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->data->id) { return tmp2; }
		}
	}
	void UpdatePrivate(Node<T, U>* node) {
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
	}
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
	void InFilePrivate(Node<T, U>* node, ostream& heroes) {

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
	}
};