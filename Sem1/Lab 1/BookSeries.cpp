#include "BookSeries.h"
BookSeries::BookSeries(vector<Book*>books, int id) {
	this->books = books;
	this->id = id++;
	this->way = way;
};
string BookSeries::GetData(int i) { return books[i]->GetData(0); };
int BookSeries::GetVectorSize() { return books.size(); };
int BookSeries::GetId() { return id; };
bool way;