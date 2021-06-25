#include"Hero.h"
	Hero::Hero(string data, int v, vector<string> names, multimap<int, Node<Book>*> role, int id, vector<Book*> books) {
		this->data = data;
		this->names = names;
		this->role = role;
		this->v = v;
		this->id = id++;
		this->way = way;
		this->books = books;
	};
	string Hero::GetData(int i) { return data; };
	string Hero::GetName(int i) { return names[i]; };
	int Hero::GetVectorSize() { return names.size(); };
	vector<Book*> Hero::GetBooks() { return books; }
	multimap<int, Node<Book>*> Hero::GetRole() { return role; }
	/*std::vector<T> GetVectorF() { return v; };*/
	int Hero::GetId() { return id; };
	