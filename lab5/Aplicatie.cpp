#include "Aplicatie.h"

Aplicatie::Aplicatie()
{
	nume = NULL;
	consumMemorie = 0;
	status = 0;
}
Aplicatie::Aplicatie(char* nume, int memorie, int status)
{
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(nume, strlen(nume) + 1, nume);
	consumMemorie = memorie;
	status = status;
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