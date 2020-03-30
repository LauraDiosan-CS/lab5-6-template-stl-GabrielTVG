#pragma once
#include <iostream>
using namespace std;

template <class T, int CAP= 20>
class Repository {
private: 
	T elem[CAP];
	int size;
public:
	Repository();
	Repository(const Repository<T, CAP>& rep);
	~Repository();
};

template<class T, int CAP>Repository<T, CAP>::Repository()
{
	this->size = 0;
}

template<class T, int CAP>Repository<T, CAP>::Repository(const Repository<T, CAP>& rep)
{
	this->size = rep.size;
	for (int i = 0; i < rep.size; i++)
		this->elem[i] = rep.elem[i];
}

template<class T, int CAP>Repository<T, CAP>::~Repository()
{
	this->size = 0;
}