#include "Aplicatie.h"
#include <cstring>
using namespace std;

Aplicatie::Aplicatie()
{
	nume = NULL;
	consumMemorie = 0;
	status = 0;
}

Aplicatie::Aplicatie(const char* num, int memorie, int stat)
{
	nume = new char[strlen(num) + 1];
	strcpy_s(nume, strlen(num) + 1, num);
	consumMemorie = memorie;
	status = stat;
}

Aplicatie::Aplicatie(const Aplicatie& a)
{
	nume = new char[strlen(a.nume) + 1];
	strcpy_s(nume, strlen(a.nume) + 1, a.nume);
	consumMemorie = a.consumMemorie;
	status = a.status;
}

Aplicatie::~Aplicatie()
{
	if (nume)
	{
		delete[] nume;
		nume = NULL;
	}
	consumMemorie = 0;
	status = 0;
}

char* Aplicatie::getName()
{
	return nume;
}

void Aplicatie::setName(char* name)
{
	if (nume)
		delete[]nume;
	nume = new char[strlen(name) + 1];
	strcpy_s(nume, strlen(name) + 1, name);
}

int Aplicatie::getConsumMemorie()
{
	return consumMemorie;
}

void Aplicatie::setConsumMemorie(int memorie)
{
	consumMemorie = memorie;
}

int Aplicatie::getStatus()
{
	return status;
}

void Aplicatie::setStatus(int stat)
{
	status = stat;
}
Aplicatie& Aplicatie::operator=(const Aplicatie& a)
{
	if (this != &a)
	{
		if (nume)
			delete[] nume;
		nume = new char[strlen(a.nume) + 1];
		strcpy_s(nume, strlen(a.nume) + 1, a.nume);
		consumMemorie = a.consumMemorie;
		status = a.status;
	}
	return *this;
}

bool Aplicatie::operator==(const Aplicatie& a)
{
	return (strcmp(nume, a.nume) == 0 && consumMemorie == a.consumMemorie && status == a.status);
}
ostream& operator<<(ostream& os, Aplicatie a)
{
	os << "Nume: " << a.nume << " Consum memorie: " << a.consumMemorie << " Status (1 ram, 2 swap): " << a.status<<endl;
	return os;
}

//istream& operator>>(istream& is, Aplicatie& a)
//{
//	int status, memorie;
//	char* nume = new char[20];
//	cout << endl << "Nume aplicatie: ";
//	is >> nume;
//	cout << endl << "Status (1 ram, 2 swap): ";
//	is >> status;
//	cout << endl << "Memorie utilizata: ";
//	is >> memorie;
//	cout << endl;
//	a.setName(nume);
//	a.setStatus(status);
//	a.setConsumMemorie(memorie);
//	delete[] nume;
//	return is;
//}
