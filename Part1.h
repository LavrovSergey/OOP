#pragma once
#include <vector>
using namespace std;
/*! @param T -data type*/
template<class T>
/*! Template node class.*/
class Part1 {
private:
	T data;
	vector<T> v;
	int id = 0; 
public:
	Part1(T data, int id, bool way) : data(data), id(id), way(way) {}
	Part1(vector<T> v, int id, bool way) :  v(v), id(id), way(way) {}
	T GetData() { return data; };
	T GetVector(int i) { return v[i]; };
	int GetVectorSize() { return v.size(); };
	vector<T> GetVectorF() { return v; };
	int GetId() { return id; };
	bool GetWay() { return way; };
	bool way;
};