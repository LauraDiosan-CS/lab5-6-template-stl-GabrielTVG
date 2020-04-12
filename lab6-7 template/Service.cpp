#include "Service.h"
#include "Aplicatie.h"
#include "Repository.h"
Service::Service()
{
	memorieHDD = 0;
	memorieRAM = 0;
	RAM = 0;
}

Service::Service(Repository<Aplicatie>*& r)
{
	rep = r;
	memorieHDD = 0;
	memorieRAM = 0;
	RAM = 0;
}
void Service::setRepo(Repository<Aplicatie>*& r)
{
	rep = r;
}

int Service::verificareDate(Aplicatie& a)
{
	map<int, Aplicatie> all = rep->getAll();
	map<int, Aplicatie>::iterator it;
	int ok = 1;
	it = all.begin();
	while (it != all.end() && ok == 1)
	{
		if (strcmp(it->second.getName(), a.getName()) == 0)
		{
			cout << rep->findElem(a);
			cout << "Avem acest nume deja!" << endl << "Introduceti alt nume!" << endl;
			ok = 0;
		}
		it++;
	}

	if (a.getConsumMemorie() < 0)
	{
		cout << "Memoria utilizata nu poate fi negativa!" << endl << "Introduceti o valoare pozitiva!" << endl;
		ok = 0;
	}

	if (a.getStatus() != 1 && a.getStatus() != 2)
	{
		cout << "Statusul este incorect!" << endl << "Introduceti status corespunzator!" << endl;
		ok = 0;
	}
	return ok;
}

void Service::verificareRAM(Aplicatie& a)
{
	int pozitie = 0;
	if (a.getStatus() == 1 && a.getConsumMemorie() > RAM)
	{
		cout << "Memoria utilizata de aplicatie este prea mare, aplicatia va fi mutata in swap!" << endl;
		Aplicatie b(a.getName(), a.getConsumMemorie(), 2);
		rep->updateElem(rep->findElem(a), b);
		//a.setStatus(2);
		memorieHDD += a.getConsumMemorie();
	}
	else
		if (a.getStatus() == 1 && (memorieRAM + a.getConsumMemorie() <= RAM))
			memorieRAM += a.getConsumMemorie();
		else
			if (a.getStatus() == 1 && memorieRAM + a.getConsumMemorie() > RAM && a.getConsumMemorie()<=RAM)
			{
				map<int, Aplicatie> all = rep->getAll();
				map<int, Aplicatie>::iterator it = all.begin();
				while (memorieRAM + a.getConsumMemorie() > RAM)
				{
					it = all.find(pozitie);
					if (it != all.end() && it->second.getStatus() == 1 && it->first!=rep->findElem(a))
					{

						Aplicatie b(it->second.getName(), it->second.getConsumMemorie(), 2);
						rep->updateElem(pozitie, b);
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
				memorieRAM += a.getConsumMemorie();
				cout << "Aplicatie adaugata. Memorie ram utilizata acuma: " << RAM - memorieRAM << " " << endl;
			}
			else
				if (a.getStatus() == 2)
					memorieHDD += a.getConsumMemorie();
}

void Service::adaugareElement(Aplicatie& a)
{
	if (verificareDate(a) == 1)
	{
		verificareRAM(a);
		rep->addElem(a);
		rep->saveFile();
	}
}

int Service::gasireElement(Aplicatie& a)
{
	return rep->findElem(a);
}

void Service::stergereElement(int pozitie)
{
	int memorieVeche, statusVechi, pozitieAp = 0;
	map<int, Aplicatie> all = rep->getAll();
	map<int, Aplicatie>::iterator it;
	it = all.find(pozitie);
	memorieVeche = it->second.getConsumMemorie();
	statusVechi = it->second.getStatus();
	rep->delElem(pozitie);
	if (statusVechi == 1)
	{
		memorieRAM -= memorieVeche;
		map<int, Aplicatie> all = rep->getAll();
		map<int, Aplicatie>::iterator it = all.begin();
		while (memorieRAM <= RAM && pozitieAp < rep->dim())
		{
			it = all.find(pozitieAp);
			if (it != all.end() && it->second.getStatus() == 2 && memorieRAM + it->second.getConsumMemorie() <= RAM)
			{
				Aplicatie b(it->second.getName(), it->second.getConsumMemorie(), 1);
				rep->updateElem(pozitieAp, b);
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
	rep->saveFile();
}

void Service::updateElement(int pozitie, Aplicatie& a)
{
	map<int, Aplicatie> all = rep->getAll();
	map<int, Aplicatie>::iterator it;
	int memorieVeche, statusVechi;
	if (verificareDate(a) == 0 || (pozitie < 0 || pozitie >= rep->dim() || all.find(pozitie) == all.end()))
		cout << "Date/pozitie gresite!"<<endl;
	else
	{
		it = all.find(pozitie);
		memorieVeche = it->second.getConsumMemorie();
		statusVechi = it->second.getStatus();
		if (statusVechi == 1)
			memorieRAM -= memorieVeche;
		else
			memorieHDD -= memorieVeche;
		verificareRAM(a);
		rep->updateElem(pozitie, a);
		rep->saveFile();
	}
}

int Service::getSize()
{
	return rep->dim();
}

map<int, Aplicatie>Service::getEverything()
{
	return rep->getAll();
}

int Service::citireRAM()
{
	int ok = 0;
	cout << "Introduceti numarul de KB utilizabili in RAM: ";
	cin >> RAM;
	if (RAM < 0)
	{
		cout << "Nu putem avea cantitate de memorie negativa." << endl << "Introduceti alta valoare!" << endl;
		ok = 1;
	}
	cout << endl;
	return ok;
}

void Service::afisareMemorie()
{
	cout << "Memorie RAM: " << RAM << endl;
	cout << "Memorie RAM utilizata: " << memorieRAM << endl;
	cout << "Memorie HDD utilizata:" << memorieHDD << endl;
	cout << "Memorie in RAM libera:" << RAM - memorieRAM << endl;
	cout << endl;
}

int Service::getRAM()
{
	return memorieRAM;
}

void Service::setRAM(int ram)
{
	memorieRAM = ram;
}

int Service::getHDD()
{
	return memorieHDD;
}

void Service::setHDD(int hdd)
{
	memorieHDD = hdd;
}

int Service::getTotalRAM()
{
	return RAM;
}

void Service::setTotalRAM(int ram)
{
	RAM = ram;
}
Service::~Service()
{
	memorieHDD = 0;
	memorieRAM = 0;
	RAM = 0;
}