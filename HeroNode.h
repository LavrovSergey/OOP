#pragma once
#include <string>
#include <vector>
/*! @param T -data type
* @param U -object.*/
template<class T, class U> class BinarySearchTree;
/*! Character class.*/
class HeroNode {
	friend class BinarySearchTree<string, HeroNode>;
public:
	string data; //name of the hero
	vector<string> names;
	multimap<int, string> hb;
	int id = 0;
	bool way;
	HeroNode* left;
	HeroNode* right;
};
class HeroFunctions : public BinarySearchTree<string, HeroNode>
{
public:
	/*! Write to file.*/
	void InFile() {
		ofstream heroes("heroes.bin");
		InFilePrivate(BinarySearchTree<string, HeroNode>::root, heroes);
		heroes.close();
	}
	/*! Add a character.*/
	void AddHero() {
		int a;
		HeroNode* h = new HeroNode;
		int n; string s;
		cout << "Введите имя персонажа" << endl;
		getline(cin, h->data);
		cout << "Введите количество его псевдонимов/имен" << endl;
		cin >> n;
		cout << "Заполните их " << endl;
		cin.ignore(1, '\n');
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			h->names.push_back(s);
		}
		cout << "Введите количество книг, в которых он встречается" << endl;
		cin >> n;
		cout << "Заполните название книг и его роль в них " << endl;
		for (int i = 0; i < n; i++) {
			cout << "Какая у него роль(1-главная, 2-второстепенная, 3-эпизодическая)" << endl;
			cin >> a;
			cin.ignore(1, '\n');
			cout << "Введите название книги" << endl;
			getline(cin, s);
			h->hb.insert(pair<int, string>(a, s));
		}
		BinarySearchTree<string, HeroNode>::AddLeaf(h, BinarySearchTree<string, HeroNode>::root);
	}
	/*! Delete by number.*/
	void Delete( )
	{
		PrintInOrder();
		int id;
		cout << "Введите id" << endl;
		cin >> id;
			HeroNode* ptr = FindPrivateId(id, BinarySearchTree<string, HeroNode>::root);
			if (ptr == NULL) { cout << "Такого нема" << endl; }
			else  (BinarySearchTree<string, HeroNode>::RemoveNode(ptr, BinarySearchTree<string, HeroNode>::root, 1));
	}
	/*! Print.*/
	void PrintInOrder() {
		PrintPreOrderPrivate(BinarySearchTree<string, HeroNode>::root);
		system("pause");
	}
	/*! Find.*/
	void Find() {
		string inf;
		cout << "Введите, что хотите найти" << endl;
		cin >> inf;
			HeroNode* ptr2 = FindPrivate(inf, BinarySearchTree<string, HeroNode>::root);
			if (ptr2 == NULL) { cout << "Такого нема" << endl; }
			else {
				PrintHero(ptr2);
			}
			system("pause");	
	}
	/*! Print series.*/
	void Series() {
		vector<string>name;
		SeriesPrivate(BinarySearchTree<string, HeroNode>::root, name);
	}
private:
	void SeriesPrivate(HeroNode* node, vector<string>name) {
		if (node != NULL)
		{
			for (auto it = node->hb.begin(); it != node->hb.end(); ++it)
			{
				if (it->first == 1 || it->first == 2)
				{
					name.push_back(it->second);
				}
			}
			cout << "Эти книги принадлежат одной серии: ";
			for (int i = 0; i < name.size(); i++) {
				if (i<= name.size()-1) { cout << name[i] << ','; }
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
		else { cout << "Пусто" << endl; }

	}
	HeroNode* FindPrivate(string name, HeroNode* node)
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
	void PrintHero(HeroNode* node) {
		cout << node->id << ". ";
		cout << "Имя: " << node->data << endl;
		cout << "Псевдонимы: ";
		for (int i = 0; i < node->names.size(); i++)
		{
			cout << node->names[i];
			if (i <= node->names.size()-1) { cout << ", "; }
			else(cout << endl);
		}
		cout << "Роль-Книга: ";
		for (auto it = node->hb.begin(); it != node->hb.end(); ++it)
		{
			cout << it->first << " -- " << it->second << endl;
		}
	}
	void PrintPreOrderPrivate(HeroNode* node) {
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
		else(cout << "Пусто" << endl);
	}
	HeroNode* FindPrivateId(int id, HeroNode* node) {
		if (node == NULL) return node;
		if (id == node->id) {
			return node;
		}
		HeroNode* tmp1 = FindPrivateId(id, node->left);
		if (tmp1 != NULL) {
			if (id == tmp1->id) { return tmp1; }
		}
		HeroNode* tmp2 = FindPrivateId(id, node->right);
		if (tmp2 != NULL) {
			if (id == tmp2->id) { return tmp2; }
		}
	}
	void InFilePrivate(HeroNode* node, ostream& heroes) {

		if (node->left != NULL)
		{
			InFilePrivate(node->left, heroes);
		}
		heroes.write((char*)&node, sizeof(HeroNode));
		if (node->right != NULL)
		{
			InFilePrivate(node->right, heroes);
		}
	}
};