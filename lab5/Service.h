#pragma once
#include "Repository.h"

class Service
{
private:
	Repository rep;
public:
	Service();
	//Service(const Repository&);
	//void setRepo(const Repository&);
	void adaugareElement(const Aplicatie&);
	int gasireElement(const Aplicatie&);
	void stergereElement(int);
	void updateElement(int, Aplicatie);
	int getSize();
	map<int, Aplicatie> getEverything();
	~Service();
};