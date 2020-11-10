#pragma once
#include "Node.h"
#include "BinarySearchTree.h"
#include <fstream>
/*! @param T -data type
* @param U -object.*/
/*! Function class for working with books.*/
template <class T, class U>
class BookFunctions : public  Node<T, U>, public BinarySearchTree<T, U>
{
public:
	/*void FromFile() {
		ifstream books("books.bin");
		if (books.peek() != EOF) {
			FromFilePrivate(books);
		}
	}*/
	/*! Write to file.*/
	void InFile() {
		ofstream books("books.bin");
		InFilePrivate(BinarySearchTree<string, Node<T, U>>::root, books);
		books.close();
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
	/*! Adding a book.*/
	void AddBook() {
		Book* b = new Book;
		int n; string s;
		cout << "Enter the title of the book" << endl;
		getline(cin, b->data);
		cout << "Enter the number of authors" << endl;
		cin >> n;
		cout << "Fill in authors" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			b->authors.push_back(s);
		}
		cout << "Fill in the date the book was written (day month year)" << endl;
		cin >> b->d >> b->m >> b->y;
		cout << "Enter the number of pages" << endl;
		cin >> b->pages;
		cin.ignore(1, '\n');
		cout << "Fill out the plot briefly" << endl;
		getline(cin, b->plot);
		BinarySearchTree<string, Node<T, U>>::AddLeaf(b, BinarySearchTree<string, Node<T, U>>::root);

	}
	/*! Delete a book.*/
	void Delete()
	{
		PrintInOrder();
		int id;
		cout << "Enter id" << endl;
		cin >> id;
		Node<T, U>* ptr = FindPrivateId(id, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr == NULL) { cout << "There is no such thing" << endl; }
		else  (BinarySearchTree<string, Node<T, U>>::RemoveNode(ptr, BinarySearchTree<string, Node<T, U>>::root, 1));
		system("pause");
	}
	/*! Print.*/
	void PrintInOrder() {
		PrintInOrderPrivate(BinarySearchTree<string, Node<T, U>>::root);
		system("pause");
	}
	/*! Find.*/
	void Find() {
		string inf;
		cout << "Enter what you want to find" << endl;
		cin >> inf;
		Node<T, U>* ptr1 = FindPrivate(inf, BinarySearchTree<string, Node<T, U>>::root);
		if (ptr1 == NULL) { cout << "There is no such thing" << endl; }
		else {
			PrintBook(ptr1);
		}
		system("pause");
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
	void PrintBook(Node<T, U>* node) {
		cout << node->data->id << ". ";
		cout << "Title: " << node->data->data << endl;
		cout << "Authors: ";
		for (int i = 0; i < node->data->authors.size(); i++)
		{
			cout << node->data->authors[i];
			if (i <= node->data->authors.size() - 1) { cout << ", "; }
			else(cout << endl);
		}
		cout << "Date of writing:" << node->data->d << ". " << node->data->m << ". " << node->data->y<< endl;
		cout << "Number of pages:" << node->data->id << ".";
		cout << "Plot:" << node->data->plot << endl;
	}
private:
	void UpdatePrivate(Node<T, U>* node) {
		string s;
		cout << "Enter new name of book" << endl;
		getline(cin, node->data->data);
		cout << "Enter the number of authors" << endl;
		cin >> node->data->v;
		cout << "Fill in authors" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < node->data->v; i++) {
			getline(cin, s);
			node->data->authors.push_back(s);
		}
		cout << "Fill in the date the book was written (day month year)" << endl;
		cin >> node->data->d >> node->data->m >> node->data->y;
		cout << "Enter the number of pages" << endl;
		cin >> node->data->pages;
		cin.ignore(1, '\n');
		cout << "Fill in the plot briefly" << endl;
		getline(cin, node->data->plot);
	}
	/*! Search by id.*/
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
	void PrintInOrderPrivate(Node<T, U>* node)
	{
		if (BinarySearchTree<string, Node<T, U>>::root != NULL)
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
	void InFilePrivate(Node<T, U>* node, ostream& books) {
		if (node->left != NULL)
		{
			InFilePrivate(node->left, books);
		}
		if (node != NULL) {
			books.write((char*)&node->data->v, sizeof(int));
			for (int i = 0; i < node->v; i++) {
				books.write((char*)&node->data->authors[i], sizeof(string));
			}
			books.write((char*)&node->data->data, sizeof(string));
			books.write((char*)&node->data->d, sizeof(int));
			books.write((char*)&node->data->m, sizeof(int));
			books.write((char*)&node->data->y, sizeof(int));
			books.write((char*)&node->data->plot, sizeof(string));
			books.write((char*)&node->data->pages, sizeof(int));
		}
		if (node->right != NULL)
		{
			InFilePrivate(node->right, books);
		}
	}
	//void FromFilePrivate(ifstream& books) {
	//	while (!books.eof()) {
	//		Book* b = new Book;
	//		string s;
	//		books.read((char*)&b->data->v, sizeof(int));
	//		if (books.eof()) { break; }
	//		for (int i = 0; i < b->data->v; i++) {
	//			books.read((char*)&s, sizeof(string)); b->data->authors.push_back(s);          // Âûçâàíî èñêëþ÷åíèå: íàðóøåíèå äîñòóïà äëÿ ÷òåíèÿ._Pnext áûëî 0x2BACC0F0A08.
	//		}
	//		books.read((char*)&b->data->data, sizeof(string));
	//		books.read((char*)&b->data->d, sizeof(int));
	//		books.read((char*)&b->data->m, sizeof(int));
	//		books.read((char*)&b->data->y, sizeof(int));
	//		books.read((char*)&b->data->plot, sizeof(string));
	//		books.read((char*)&b->data->pages, sizeof(int));
	//		BinarySearchTree<string, Node<T, U>>::AddLeaf(b, BinarySearchTree<string, Node<T, U>>::root);
	//	}
	//}
};
