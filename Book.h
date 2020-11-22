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
	int id = 0;
public:
	Book(string data, vector<string> authors, int v, int d, int m, int y,int pages, string plot) {

		this->data = data;
		this->authors = authors;
		this->v = v;
		this->d = d;
		this->m = m;
		this->y = y;
		this->pages =pages;
		this->plot = plot;
		this->id= id++;
		this->way = way;
	};
	string GetData() { return data; };
	string GetAuthor(int i) { return authors[i]; };
	int GetDay() { return d; };
	int GetMonth() { return m; };
	int GetYear() { return y; };
	int GetPages() { return pages; };
	string GetPlot() { return plot; };
	int GetVectorSize() { return authors.size(); };
	/*std::vector<T> GetVectorF() { return v; };*/
	int GetId() { return id; };
	bool way;
};