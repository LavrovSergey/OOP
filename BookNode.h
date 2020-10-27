#pragma once
#include <string>
#include <vector>
#include<fstream>
template<class T, class U> class BinarySearchTree;

class BookNode {
	friend class BinarySearchTree<string, BookNode>;
public:
	BookNode* left;
	BookNode* right;
	string data; //name of the book
	vector<string> authors;
	int d, m, y;
	int pages;
	string plot;
	int id = 0;
	bool way;
};
class BookFunctions : public BinarySearchTree<string, BookNode>
{
public:
	void InFile() {
		ofstream books("books.bin");
		InFilePrivate(BinarySearchTree<string, BookNode>::root, books);
		books.close();
	}
	void AddBook() {
		BookNode* b = new BookNode;
		int n; string s;
		cout << "Введите название книги" << endl;
		getline(cin, b->data);
		cout << "Введите количество авторов" << endl;
		cin >> n;
		cout << "Заполните авторов" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			b->authors.push_back(s);
		}
		cout << "Заполните дату написания книги(день месяц год)" << endl;
		cin >> b->d >> b->m >> b->y;
		cout << "Введите количество страниц" << endl;
		cin >> b->pages;
		cin.ignore(1, '\n');
		cout << "Заполните сюжет кратко" << endl;
		getline(cin, b->plot);
		BinarySearchTree<string, BookNode>::AddLeaf(b, BinarySearchTree<string, BookNode>::root);
		
	}
	void Delete()
	{
		PrintInOrder();
		int id;
		cout << "Введите id" << endl;
		cin >> id;
			BookNode* ptr = FindPrivateId(id, BinarySearchTree<string, BookNode>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree<string, BookNode>::RemoveNode(ptr, BinarySearchTree<string, BookNode>::root, 1));
			system("pause");
	}
	void PrintInOrder() {
		PrintInOrderPrivate(BinarySearchTree<string, BookNode>::root);
		system("pause");
	}
	void Find() {
		string inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
			BookNode* ptr1 = FindPrivate(inf, BinarySearchTree<string, BookNode>::root);
			if (ptr1 == NULL ) { cout << "Такого нема" << endl; }
			else {
				PrintBook(ptr1);
			}
			system("pause");
	}
	BookNode* FindPrivate(string name, BookNode* node)
	{
		if (node != NULL)
		{
			if (node->data == name)
			{
				return node;
			}
			else
			{
				if (name <= node->data)
				{
					FindPrivate(name, node->left);
				}
				else if (name > node->data)
				{
					FindPrivate(name, node->right);
				}
			}
		}
		else { return node; }
	}
	void PrintBook(BookNode* node) {
		cout << node->id << ". ";
		cout << "Название: " << node->data << endl;
		cout << "Авторы: ";
		for (int i = 0; i < node->authors.size(); i++)
		{
			cout << node->authors[i];
			if (i<= node->authors.size()-1) { cout << ", "; }
			else(cout << endl);
		}
		cout << "Дата написания:" << node->d << ". " << node->m << ". " << node->y << endl;
		cout << "Количество страниц:" << node->id << ".";
		cout << "Описание:" << node->plot << endl;
	}
private:
	
	BookNode* FindPrivateId(int id, BookNode* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		BookNode* tmp1 = FindPrivateId(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		BookNode* tmp2 = FindPrivateId(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	void PrintInOrderPrivate(BookNode* node)
	{
		if (BinarySearchTree<string, BookNode>::root != NULL)
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
		else(cout << "Пусто" << endl);
	}
	void InFilePrivate(BookNode* node, ostream &books) {
		
		if (node->left != NULL)
		{
			InFilePrivate(node->left, books);
		}
		books.write((char*)&node, sizeof(BookNode));
		if (node->right != NULL)
		{
			InFilePrivate(node->right, books);
		}
	}
};