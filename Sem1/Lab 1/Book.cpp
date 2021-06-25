#include "Book.h"
	Book::Book(string data, vector<string> authors, int v, int d, int m, int y, int pages, string plot, int id) {
		this->data = data;
		this->authors = authors;
		this->v = v;
		this->d = d;
		this->m = m;
		this->y = y;
		this->pages = pages;
		this->plot = plot;
		this->id = id++;
	};
	string Book::GetData(int i) { return data; };
	string Book::GetAuthor(int i) { return authors[i]; };
	int Book::GetDay() { return d; };
	int Book::GetMonth() { return m; };
	int Book::GetYear() { return y; };
	int Book::GetPages() { return pages; };
	string Book::GetPlot() { return plot; };
	int Book::GetVectorSize() { return authors.size(); };
	/*std::vector<T> GetVectorF() { return v; };*/
	int Book::GetId() { return id; };
	
