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
	int v;
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
	void FromFile() {
		ifstream books("books.bin");
		if (books.peek() != EOF) {
			FromFilePrivate(books);
		}
	}
	void InFile() {
		ofstream books("books.bin");
		InFilePrivate(BinarySearchTree<string, BookNode>::root, books);
		books.close();
	}
	void Update() {
		PrintInOrder();
		int id;
		cout << "������� id" << endl;
		cin >> id;
		BookNode* ptr = FindPrivateId(id, BinarySearchTree<string, BookNode>::root);
		if (ptr == NULL) { cout << "������ ����" << endl; }
		else  (UpdatePrivate(ptr));
		system("pause");
	}
	void AddBook() {
		BookNode* b = new BookNode;
		string s;
		cout << "������� �������� �����" << endl;
		getline(cin, b->data);
		cout << "������� ���������� �������" << endl;
		cin >> b->v;
		cout << "��������� �������" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < b->v; i++) {
			getline(cin, s);
			b->authors.push_back(s);
		}
		cout << "��������� ���� ��������� �����(���� ����� ���)" << endl;
		cin >> b->d >> b->m >> b->y;
		cout << "������� ���������� �������" << endl;
		cin >> b->pages;
		cin.ignore(1, '\n');
		cout << "��������� ����� ������" << endl;
		getline(cin, b->plot);
		BinarySearchTree<string, BookNode>::AddLeaf(b, BinarySearchTree<string, BookNode>::root);

	}
	void Delete()
	{
		PrintInOrder();
		int id;
		cout << "������� id" << endl;
		cin >> id;
		BookNode* ptr = FindPrivateId(id, BinarySearchTree<string, BookNode>::root);
		if (ptr == NULL) { cout << "������ ����" << endl; }
		else  (BinarySearchTree<string, BookNode>::RemoveNode(ptr, BinarySearchTree<string, BookNode>::root, 1));
		system("pause");
	}
	void PrintInOrder() {
		PrintInOrderPrivate(BinarySearchTree<string, BookNode>::root);
		system("pause");
	}
	void Find() {
		string inf;
		cout << "�������, ��� ������ �����" << endl;
		cin >> inf;
		BookNode* ptr1 = FindPrivate(inf, BinarySearchTree<string, BookNode>::root);
		if (ptr1 == NULL) { cout << "������ ����" << endl; }
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
		cout << "��������: " << node->data << endl;
		cout << "������: ";
		for (int i = 0; i < node->authors.size(); i++)
		{
			cout << node->authors[i];
			if (i <= node->authors.size() - 1) { cout << ", "; }
			else if (i == 1) { cout << endl; }
			else(cout << endl);
		}
		cout << "���� ���������:" << node->d << ". " << node->m << ". " << node->y << endl;
		cout << "���������� �������:" << node->id << "." << endl;
		cout << "��������:" << node->plot << endl;
	}
private:
	void UpdatePrivate(BookNode* node) {
		string s;
		cout << "������� �������� �����" << endl;
		getline(cin, node->data);
		cout << "������� ���������� �������" << endl;
		cin >> node->v;
		cout << "��������� �������" << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < node->v; i++) {
			getline(cin, s);
			node->authors.push_back(s);
		}
		cout << "��������� ���� ��������� �����(���� ����� ���)" << endl;
		cin >> node->d >> node->m >> node->y;
		cout << "������� ���������� �������" << endl;
		cin >> node->pages;
		cin.ignore(1, '\n');
		cout << "��������� ����� ������" << endl;
		getline(cin, node->plot);
	}
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
		else(cout << "�����" << endl);
	}
	void InFilePrivate(BookNode* node, ostream& books) {
		if (node->left != NULL)
		{
			InFilePrivate(node->left, books);
		}
		if (node != NULL) {
			books.write((char*)&node->v, sizeof(int));
			/*for (int i = 0; i < node->v; i++) {
				books.write((char*)&node->authors[i], sizeof(string));
			}*/
			books.write((char*)&node->data, sizeof(string));
			books.write((char*)&node->d, sizeof(int));
			books.write((char*)&node->m, sizeof(int));
			books.write((char*)&node->y, sizeof(int));
			books.write((char*)&node->plot, sizeof(string));
			books.write((char*)&node->pages, sizeof(int));
		}
		if (node->right != NULL)
		{
			InFilePrivate(node->right, books);
		}
	}
	void FromFilePrivate(ifstream& books) {
		while (!books.eof()) {
			BookNode* b = new BookNode;
			string s;
			books.read((char*)&b->v, sizeof(int));
			if (books.eof()) { break; }
			/*for (int i = 0; i < b->v; i++) {
				books.read((char*)&s, sizeof(string)); b->authors.push_back(s);           ������� ����������: ��������� ������� ��� ������._Pnext ���� 0x2BACC0F0A08.
			}*/
			books.read((char*)&b->data, sizeof(string));
			books.read((char*)&b->d, sizeof(int));
			books.read((char*)&b->m, sizeof(int));
			books.read((char*)&b->y, sizeof(int));
			books.read((char*)&b->plot, sizeof(string));
			books.read((char*)&b->pages, sizeof(int));
			BinarySearchTree<string, BookNode>::AddLeaf(b, BinarySearchTree<string, BookNode>::root);
		}
	}
};
