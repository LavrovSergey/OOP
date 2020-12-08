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
	static bool comparator(Book* & aa, Book* & bb) {
		 Book& a = *aa;
		 Book& b = *bb;
		if (a.GetYear() < b.GetYear()) return true;
		if (a.GetYear() > b.GetYear()) return false;
		if (a.GetMonth() < b.GetMonth()) return true;
		if (a.GetMonth() > b.GetMonth()) return false;
		return a.GetDay() < b.GetDay();
	}
	/*! Add a character.
	* @param root of tree of book to add books 
	*/
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
	/*! Find by name.*/
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
	
private:
	/*! Print book series
	*  @param name of character
	* @param node for traveling
	* @return node that we searched
	*/
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
	/*! Print charecter
	*  @param node for traveling
	*/
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
	/*! Print book series
	*  @param node for traveling
	*/
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
	/*! Find by id
	* @param id
	*  @param node for traveling
	*/
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
};