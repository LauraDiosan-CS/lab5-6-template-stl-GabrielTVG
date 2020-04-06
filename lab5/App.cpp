#include <iostream>
#include "UI.h"
#include "test.h"
using namespace std;
int main()
{
	int ok = 1, optiune;
	UI ui;
	cout << "teste"<<endl;
	testareAdaugare();
	testareStergereSiCautare();
	testareUpdate();
	cout << "gj"<<endl;
	ui.citireRAM();
	ui.modele();
	cout << endl;
	while (ok)
	{
		cout << "1.Adaugare aplicatie 2 Afisare aplicatii 3 Update aplicatie 4.Gasire aplicatie 5.Stergere aplicatie 6.Memorie 0 Iesire"<<endl;
		cin >> optiune;
		if (optiune == 1)
		{
			ui.adaugareAplicatie();
			continue;
		}
		if (optiune == 2)
		{
			ui.afisareAplicatie();
			continue;
		}
		if (optiune == 3)
		{
			ui.updateAplicatie();
			continue;
		}
		if (optiune == 4)
		{
			ui.gasireAplicatie();
			continue;
		}
		if (optiune == 5)
		{
			ui.stergereAplicatie();
			continue;
		}
		if (optiune == 6)
		{
			ui.afisareMemorie();
			continue;
		}
		if (optiune == 0)
		{
			ok = 0;
			continue;
		}
	}
	return 0;
}