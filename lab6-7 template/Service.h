#pragma once
#include "Repository.h"
#include "RepositoryFile.h"

class Service
{
private:
	RepositoryFile<Aplicatie> repF;
	Repository<Aplicatie>* rep = &repF;
	int memorieHDD, memorieRAM, RAM;
public:
	Service();
	Service(Repository<Aplicatie>*&);
	void setRepo(Repository<Aplicatie>*&);
	void adaugareElement(Aplicatie&);
	int gasireElement(Aplicatie&);
	void stergereElement(int);
	void updateElement(int, Aplicatie&);
	int getSize();
	map<int, Aplicatie> getEverything();
	int verificareDate(Aplicatie& a);
	int citireRAM();
	void verificareRAM(Aplicatie&);
	void afisareMemorie();
	int getRAM();
	void setRAM(int);
	int getHDD();
	void setHDD(int);
	int getTotalRAM();
	void setTotalRAM(int);
	~Service();
};