#pragma once
#include "Service.h"
class UI
{
private:
	Service ser;

public:
	UI();
	void citireRAM(Service&);
	void modele(Service&);
	void adaugareAplicatie(Service&);
	void afisareAplicatie(Service&);
	void updateAplicatie(Service&);
	void gasireAplicatie(Service&);
	void stergereAplicatie(Service&);
	void afisareMemorie(Service&);
	void run();
	~UI();
};