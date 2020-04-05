#pragma once
#include "Service.h"
class UI
{
private:
	Service ser;
	Repository rep;
	Aplicatie ap;
	int memorieHDD, memorieRAM, RAM;
public:
	UI();
	void citireRAM();
	void adaugareAplicatie();
	void afisareAplicatie();
	void updateAplicatie();
	void gasireAplicatie();
	void stergereAplicatie();
	void afisareMemorie();
	~UI();
};