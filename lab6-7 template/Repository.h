#pragma once
#include "Aplicatie.h"
#include <map>
#include <iostream>
using namespace std;
template <class T>
class Repository {
protected: 
	map<int, T>app;
	int contor;
public:
	Repository();
	Repository(const Repository&);
	void addElem(T& );
	int findElem(T& );
	void delElem(int);
	void updateElem(int,T&);
	int dim();
	map<int,T> getAll();
	virtual void loadFile(const char* fileName);
	virtual void saveFile();
	~Repository();
};

template <class T> Repository<T>::Repository()
{
	this->contor = 0;
}

template <class T> Repository<T>::Repository(const Repository& r)
{
	this->app = r.app;
	this->contor = r.contor;
}

template <class T> void Repository<T>::addElem(T& a)
{
	this->app.insert(pair<int, T>(this->contor++, a));
}

template <class T> int Repository<T>::findElem(T& a)
{
	map<int, Aplicatie>::iterator it = app.begin();
	while (it != app.end()) {
		if (it->second == a)
			return it->first;
		else
			it++;
	}
	return -1;
}

template <class T> void Repository<T>::delElem(int nr)
{
	//map<int, Aplicatie>::iterator itf = app.find(nr);
	app.erase(nr);
}

template <class T> void Repository<T>::updateElem(int pozitie,T& noua)
{
	map<int, Aplicatie>::iterator itf = app.find(pozitie);
	if (itf != app.end())
		this->app[pozitie] = noua;
}

template <class T> int Repository<T>::dim()
{
	return this->contor;
}

template <class T> map<int, T>Repository<T>::getAll()
{
	return this->app;
}

template <class T> inline void Repository<T>::loadFile(const char* fileName)
{

}

template <class T> inline void Repository<T>::saveFile()
{

}
template <class T> Repository<T>::~Repository()
{
	app.clear();
	contor = 0;
}