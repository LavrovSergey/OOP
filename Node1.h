#pragma once
#include <vector>
/*! @param T -data type*/
template<class T>
/*! Template node class.*/
class Part1 {
public:
	T data;
	std::vector<T> v;
	int id = 0;
	bool way; 
};