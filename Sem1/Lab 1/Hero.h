#pragma once
#include <string>
#include <vector>
#include<map>
#include "Book.h"
#include "Node.h"
using namespace std;
/*! Character class.*/
class Hero {
private:
	string data; //name of the hero
	int v;
	vector<string> names;
	int id;
	multimap<int, Node<Book>*> role;
	vector<Book*> books;
public:
	Hero(string data, int v, vector<string> names, multimap<int, Node<Book>*> role, int id, vector<Book*> books);
	string GetData(int i);
	string GetName(int i);
	int GetVectorSize();
	vector<Book*> GetBooks();
	multimap<int, Node<Book>*> GetRole();
	/*std::vector<T> GetVectorF() { return v; };*/
	int GetId();
	bool way;
};