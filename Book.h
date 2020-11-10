#pragma once
#include <string>
#include <vector>
#include<fstream>
/*! @param T -data type
* @param U -object.*/
template<class T, class U> class BinarySearchTree;
/*! Book class.*/
class Book {
public:
	string data; //name of the book
	vector<std::string> authors;
	int v;
	int d, m, y;
	int pages;
	string plot;
	int id = 0;
	bool way;
};