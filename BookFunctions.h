#pragma once
#include "Node.h"
#include "Book.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
using namespace std;
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with books.*/
template <class T, class U>
class BookFunctions
{
public:
	int id = 1;
	BinarySearchTree<T, U> bst;
	/*! Adding a book.
	*/
	void AddBook() {
		int n,d,m,y,pages; string data,s,plot;
		vector<string> authors;
		cout << "Enter the title of the book" << endl;
		getline(cin, data);
		cout << "Enter the number of authors" << endl;
		cin >> n;
		cout << "Fill in authors" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			authors.push_back(s);
		}
		cout << "Fill in the date the book was written (day month year)" << endl;
		cin >> d >>m >> y;
		cout << "Enter the number of pages" << endl;
		cin >>pages;
		cin.ignore(1, '\n');
		cout << "Fill out the plot briefly" << endl;
		getline(cin,plot);
		Book* b = new Book(data,authors,n,d,m,y,pages,plot, id);
		id++;
		bst.AddLeaf(b, bst.GetRoot());
	}
	/*! Delete a book.*/
	void Delete()
	{
		PrintInOrder(bst.GetRoot());
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node< U>* ptr = FindPrivateId(id, bst.GetRoot());
		if (ptr == NULL) { cout << "There is no such thing" << endl; }
		else  (bst.RemoveNode(ptr, bst.GetRoot(), 1));
		system("pause");
	}
	/*! Print.
	* @param root
	*/
	void PrintInOrder(Node<U>* r) {
		PrintInOrderPrivate(r);
		system("pause");
	}
	/*! Find.*/
	void Find() {
		string inf;
		cout << "Enter what you want to find" << endl;
		cin >> inf;
		Node<U>* ptr1 = FindPrivate(inf, bst.GetRoot());
		if (ptr1 == NULL) { cout << "There is no such thing" << endl; }
		else {
			PrintBook(ptr1);
		}
		system("pause");
	}
	/*! Print book series
	* @param name of book
	*  @param node for traveling
	*/
	Node<U>* FindPrivate(string name, Node<U>* node)
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
	/*! Print book 
	*  @param node of book
	*/
	void PrintBook(Node<U>* node) {
		cout << node->data->GetId() << ". ";
		cout << "Title: " << node->data->GetData(0) << endl;
		cout << "Authors: ";
		for (int i = 0; i < node->data->GetVectorSize(); i++)
		{
			cout << node->data->GetAuthor(i);
			if (i < node->data->GetVectorSize() - 1) { cout << ", "; }
			else(cout << endl);
		}
		cout << "Date of writing:" << node->data->GetDay() << ". " << node->data->GetMonth() << ". " << node->data->GetYear()<< endl;
		cout << "Number of pages:" << node->data->GetPages()<<endl;
		cout << "Plot:" << node->data->GetPlot() << endl;
	}
	/*! Search by id.
	*@param id
	* @param root
	* @return node
	*/
	Node<U>* FindId(int id, Node<U>* r)
	{
	     return FindPrivateId(id, r);
	}
private:
	/*! Search by id.
	*@param id
	* @param root
	* @return node
	*/
	Node<U>* FindPrivateId(int id, Node<U>* node) {
		if (node == NULL) return node;
		if (id == node->data->GetId()) {
			return node;
		}
		Node<U>* tmp1 = FindPrivateId(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->data->GetId()) { return tmp1; }
		}
		Node<U>* tmp2 = FindPrivateId(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->data->GetId()) { return tmp2; }
		}
	}
	/*! Print book
	*  @param node for traveling
	*/
	void PrintInOrderPrivate(Node<U>* node)
	{
		if ( node != NULL)
		{
			if (node->left != NULL)
			{
				PrintInOrderPrivate(node->left);
			}
			PrintBook(node);
			if (node->right != NULL)
			{
				PrintInOrderPrivate(node->right);
			}
		}
		else(cout << "Empty" << endl);
	}
};
