#pragma once
#include "Aplicatie.h"
#include <map>
using namespace std;

class Repository {
private: 
	map<int, Aplicatie>app;
	int contor;
public:
	Repository();
	void addElem(Aplicatie);
	int findElem(Aplicatie);
	void delElem(int);
	void updateElem(int,Aplicatie);
	int dim();
	map<int,Aplicatie> getAll();
	~Repository();
};

