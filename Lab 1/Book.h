#pragma once
#include <string>
#include <vector>
using namespace std;
/*! Book class.*/
class Book {
private:
	string data; //name of the book
	vector<string> authors;
	int v;
	int d, m, y;
	int pages;
	string plot;
	int id ;
public:
	Book(string data, vector<string> authors, int v, int d, int m, int y, int pages, string plot, int id);
	string GetData(int i);
	string GetAuthor(int i);
	int GetDay();
	int GetMonth();
	int GetYear();
	int GetPages();
	string GetPlot();
	int GetVectorSize();
	/*std::vector<T> GetVectorF() { return v; };*/
	int GetId();
	bool way;
};