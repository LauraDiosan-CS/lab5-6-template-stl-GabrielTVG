#include "UI.h"
#include <iostream>
#include <string>
using namespace std;

UI::UI()
{
	memorieHDD = 0;
	memorieRAM = 0;
	RAM = 0;
}

void UI::citireRAM()
{	
	int ok = 1;
	while (ok)
	{
		ok = 0;
		cout << "Introduceti numarul de KB utilizabili in RAM: ";
		cin >> RAM;
		if (RAM < 0)
		{
			cout << "Nu putem avea cantitate de memorie negativa." << endl << "Introduceti alta valoare!" << endl;
			ok = 1;
		}
	}
	cout << endl;
}

void UI::modele()
{
	Aplicatie a("Model1", 1, 1);
	Aplicatie b("Model2", 2, 2);
	Aplicatie c("Model3", 3, 1);
	if (a.getConsumMemorie() + memorieRAM <= RAM)
	{
		ser.adaugareElement(a);
		memorieRAM += a.getConsumMemorie();
	}
	else
	{
		a.setStatus(2);
		ser.adaugareElement(a);
		memorieHDD += a.getConsumMemorie();
	}
	ser.adaugareElement(b);
	if (c.getConsumMemorie() + memorieRAM <= RAM)
	{
		ser.adaugareElement(c);
		memorieRAM += c.getConsumMemorie();
	}
	else
	{
		c.setStatus(2);
		ser.adaugareElement(c);
		memorieHDD += c.getConsumMemorie();
	}
}
void UI::adaugareAplicatie()
{
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	cout << "Dati date despre aplicatie"<<endl;
	int status, memorie, ok = 1,pozitie=0;
	char* nume = new char[20];

	while (ok)
	{
		ok = 0;
		cout << endl << "Nume aplicatie: ";
		cin >> nume;
		it = all.begin();
		while(it!=all.end() && ok==0)
		{
			if (strcmp(it->second.getName(),nume)==0)
			{
				cout << "Avem acest nume deja!" << endl << "Introduceti alt nume!"<<endl;
				ok = 1;
			}
			it++;
		}
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		cout << endl << "Memorie utilizata: ";
		cin >> memorie;
		if (memorie < 0)
		{
			cout << "Memoria utilizata nu poate fi negativa!" << endl << "Introduceti o valoare pozitiva!"<<endl;
			ok = 1;
		}
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		cout << endl << "Status (1 ram, 2 swap): ";
		cin >> status;
		if (status != 1 && status != 2)
		{
			cout << "Statusul este incorect!" << endl << "Introduceti status corespunzator!" << endl;
			ok = 1;
		}
	}
	if (status == 1 && memorie > RAM)
	{
		cout << "Memoria utilizata de aplicatie este prea mare, aplicatia va fi mutata in swap!"<<endl;
		status = 2;
		memorieHDD += memorie;
	}
	else
		if (status == 1 && (memorieRAM + memorie <= RAM))
			memorieRAM += memorie;
		else
			if (status == 1 && memorieRAM + memorie > RAM)
			{
				map<int, Aplicatie> all = ser.getEverything();
				map<int, Aplicatie>::iterator it = all.begin();
				while (memorieRAM + memorie > RAM)
				{
					it = all.find(pozitie);
					if (it != all.end() && it->second.getStatus() == 1)
					{
						Aplicatie b(it->second.getName(), it->second.getConsumMemorie(), 2);
						ser.updateElement(pozitie,b);
						memorieHDD += it->second.getConsumMemorie();
						memorieRAM -= it->second.getConsumMemorie();
						cout << "Stare initiala: " << endl;
						cout << "Cheia: " << it->first << ' ' << it->second << endl;
						cout << "Stare actuala: " << endl;
						cout << "Cheia: " << pozitie << " " << b << endl;
						cout << "Memorie ram utilizata acuma: " << RAM - memorieRAM << " " << endl;
					}
					pozitie++;
				}
				memorieRAM += memorie;
				cout << "Aplicatie adaugata. Memorie ram utilizata acuma: " << RAM - memorieRAM << " "<<endl;
			}
			else
			if (status == 2)
				memorieHDD += memorie;
	Aplicatie a(nume, memorie, status);
	ser.adaugareElement(a);
	cout << endl;
}

void UI::afisareAplicatie()
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

void UI::updateAplicatie()
{
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	cout << "Dati date despre aplicatie"<<endl;
	int status, memorie, ok = 1,pozitie,memorieVeche,statusVechi;
	char* nume = new char[20];
	
	while (ok)
	{
		ok = 0;
		cout << "Pozitia in mapa la aplicatia care vrem sa o schimbam: ";
		cin >> pozitie;
		if (pozitie < 0 || pozitie >= ser.getSize() || all.find(pozitie)==all.end())
		{
			cout << "Pozitia este invalida" << endl << "Introduceti o valoare corespunzatoare: "<<endl;
			ok = 1;
		}
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		cout << endl << "Noul nume al aplicatiei: ";
		cin >> nume;
		it = all.begin();
		while(it!=all.end())
		{
			if (it->second.getName() == nume)
			{
				cout << "Avem acest nume deja!" << endl << "Introduceti alt nume!"<<endl;
				ok = 1;
			}
			it++;
		}
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		cout << endl << "Memorie utilizata noua: ";
		cin >> memorie;
		if (memorie < 0)
		{
			cout << "Memoria utilizata nu poate fi negativa!" << endl << "Introduceti o valoare pozitiva!";
			ok = 1;
		}
	}

	ok = 1;
	while (ok)
	{
		ok = 0;
		cout << endl << "Status nou (1 ram, 2 swap): ";
		cin >> status;
		if (status != 1 && status != 2)
		{
			cout << "Statusul este incorect!" << endl << "Introduceti status corespunzator!" << endl;
			ok = 1;
		}
	}

	it = all.find(pozitie);
	memorieVeche = it->second.getConsumMemorie();
	statusVechi = it->second.getStatus();
	if (statusVechi == 1)
		memorieRAM -= memorieVeche;
	else
		memorieHDD -= memorieVeche;

	if (status == 1 && (memorieRAM + memorie > RAM))
	{
		cout << "Memoria utilizata este prea mare, aplicatia va fi mutata in swap!";
		status = 2;
		memorieHDD += memorie;
	}
	else
		if (status == 1 && (memorieRAM + memorie <= RAM))
			memorieRAM += memorie;
		else
			if (status == 2)
				memorieHDD += memorie;

	Aplicatie a(nume, memorie, status);
	ser.updateElement(pozitie, a);
	cout << endl;
}

void UI::gasireAplicatie()
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

void UI::stergereAplicatie()
{
	int pozitie, memorieVeche, statusVechi, pozitieAp = 0;
	map<int, Aplicatie> all = ser.getEverything();
	map<int, Aplicatie>::iterator it;
	cout << "Introduceti pozitia in mapa al aplicatiei care o stergem: ";
	cin >> pozitie;
	it = all.find(pozitie);
	memorieVeche = it->second.getConsumMemorie();
	statusVechi = it->second.getStatus();
	ser.stergereElement(pozitie);
	cout << "Aplicatie stearsa!" << endl;
	if (statusVechi == 1)
	{
		memorieRAM -= memorieVeche;
		map<int, Aplicatie> all = ser.getEverything();
		map<int, Aplicatie>::iterator it = all.begin();
		while (memorieRAM <= RAM && pozitieAp<ser.getSize())
		{
			it = all.find(pozitieAp);
			if (it != all.end() && it->second.getStatus() == 2 && memorieRAM+it->second.getConsumMemorie()<=RAM)
			{
				Aplicatie b(it->second.getName(), it->second.getConsumMemorie(), 1);
				ser.updateElement(pozitieAp, b);
				memorieHDD -= it->second.getConsumMemorie();
				memorieRAM += it->second.getConsumMemorie();
				cout << "Stare initiala: " << endl;
				cout << "Cheia: " << it->first << ' ' << it->second << endl;
				cout << "Stare actuala: " << endl;
				cout << "Cheia: " << pozitieAp << " " << b << endl;
				cout << "Memorie ram utilizata acuma: " << RAM - memorieRAM << " " << endl;
			}
			pozitieAp++;
		}
	}
	else
		if (statusVechi == 2)
		memorieHDD -= memorieVeche;
	cout << endl;
}

void UI::afisareMemorie()
{
	cout << "Memorie RAM: " << RAM << endl;
	cout << "Memorie RAM utilizata: " << memorieRAM << endl;
	cout << "Memorie HDD utilizata:" << memorieHDD << endl;
	cout << "Memorie in RAM libera:" << RAM - memorieRAM << endl;
	cout << endl;
}
UI::~UI()
{
	memorieHDD = 0;
	memorieRAM = 0;
	RAM = 0;
}