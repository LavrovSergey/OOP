#pragma once
#include <string>
#include <vector>
using namespace std;
/*! Character class.*/
class Hero {
private:
	string data; //name of the hero
	int v;
	vector<string> names;
	int id = 0;

public:
	Hero(string data, int v, vector<string> names, multimap<int, Node<Book>*> role) {
		this->data = data;
		this->names = names;
		this->role = role;
		this->v = v;
		this->id = id++;
		this->way = way;
	};
	string GetData() { return data; };
	string GetName(int i) { return names[i]; };
	int GetVectorSize() { return names.size(); };
	multimap<int, Node<Book>*> GetRole() { return role; }
	/*std::vector<T> GetVectorF() { return v; };*/
	int GetId() { return id; };
	bool way; multimap<int, Node<Book>*> role;
};