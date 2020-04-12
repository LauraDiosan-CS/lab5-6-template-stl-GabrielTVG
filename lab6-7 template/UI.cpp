#include "UI.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

UI::UI()
{
	this->ser;
}

void UI::citireRAM(Service& ser)
{	
	while (ser.citireRAM())
		ser.citireRAM();
}

void UI::modele(Service& ser)
{
	Aplicatie a("Model1", 1, 1);
	Aplicatie b("Model2", 2, 2);
	Aplicatie c("Model3", 3, 1);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	ser.adaugareElement(c);
}

void UI::adaugareAplicatie(Service& ser)
{
	cout << "Dati date despre aplicatie"<<endl;
	int status, memorie;
	char* nume = new char[20];
	cout << endl << "Nume aplicatie: ";
	cin >> nume;
	cout << endl << "Memorie utilizata: ";
	cin >> memorie;
	status = 1;
	Aplicatie a(nume, memorie, status);
	ser.adaugareElement(a);
	cout << endl;
}

void UI::afisareAplicatie(Service& ser)
{
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it=all.begin();
	while (it != all.end())
	{
		cout << "Cheia: " << it->first << ' ' << it->second;
		it++;
	}
	cout << endl;
}

void UI::updateAplicatie(Service& ser)
{
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	cout << "Dati date despre aplicatie"<<endl;
	int status, memorie, ok = 1,pozitie;
	char* nume = new char[20];
	cout << "Pozitia in mapa la aplicatia care vrem sa o schimbam: ";
	cin >> pozitie;
	cout << endl << "Noul nume al aplicatiei: ";
	cin >> nume;
	cout << endl << "Memorie utilizata noua: ";
	cin >> memorie;
	cout << endl << "Status nou (1 ram, 2 swap): ";
	cin >> status;
	Aplicatie a(nume, memorie, status);
	ser.updateElement(pozitie, a);
	cout << endl;
}

void UI::gasireAplicatie(Service& ser)
{
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	cout << "Dati date despre aplicatia cautata" << endl;
	int status, memorie, ok;
	char* nume = new char[20];
	cout << endl << "Nume aplicatie: ";
	cin >> nume;
	cout << endl << "Status (1 ram, 2 swap): ";
	cin >> status;
	cout << endl << "Memorie utilizata: ";
	cin >> memorie;
	Aplicatie a(nume, memorie, status);
	ok = ser.gasireElement(a);
	if (ok != -1)
		cout << "Aplicatia cautata se afla in mapa la cheia " << ok << endl;
	else
		cout << "Nu exista aplicatie cu aceste specificatii in mapa." << endl;
	cout << endl;
}

void UI::stergereAplicatie(Service& ser)
{
	int pozitie;
	cout << "Introduceti pozitia in mapa al aplicatiei care o stergem: ";
	cin >> pozitie;
	ser.stergereElement(pozitie);
	cout << "Aplicatie stearsa!" << endl;
}

void UI::afisareMemorie(Service& ser)
{
	ser.afisareMemorie();
}

void UI::run()
{
	int ok = 1, optiune, contor = 0;
	char modificat[15] = "modificat";
	RepositoryFile<Aplicatie> rf;
	Repository<Aplicatie>* r = &rf;
	Service ser;
	ser.setRepo(r);
	citireRAM(ser);
	r->loadFile("Aplicatii.txt");
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	for (it = all.begin(); it != all.end(); it++)
	{
		Aplicatie a = it->second;
		ser.verificareRAM(a);
	}
	r->saveFile();
	//modele();
	cout << endl;
	while (ok)
	{
		cout << "1.Adaugare aplicatie 2 Afisare aplicatii 3 Update aplicatie 4.Gasire aplicatie 5.Stergere aplicatie 6.Memorie 0 Iesire" << endl;
		cin >> optiune;
		if (optiune == 1)
		{
			adaugareAplicatie(ser);
			continue;
		}
		if (optiune == 2)
		{
			afisareAplicatie(ser);
			continue;
		}
		if (optiune == 3)
		{
			updateAplicatie(ser);
			continue;
		}
		if (optiune == 4)
		{
			gasireAplicatie(ser);
			continue;
		}
		if (optiune == 5)
		{
			stergereAplicatie(ser);
			continue;
		}
		if (optiune == 6)
		{
			afisareMemorie(ser);
			continue;
		}
		if (optiune == 0)
		{
			ok = 0;
			continue;
		}
	}

}
UI::~UI()
{

}