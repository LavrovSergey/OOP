#pragma once
#include <string>
#include <vector>
/*! @param T -data type
* @param U -object.*/
template<class T, class U> class BinarySearchTree;
/*! Character class.*/
class Hero {
	friend class BinarySearchTree<string, Hero>;
public:
	string data; //name of the hero
	int v;
	vector<string> names;
	int m;
	multimap<int, string> hb;
	int id = 0;
	bool way;
};