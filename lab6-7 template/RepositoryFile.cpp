#include "RepositoryFile.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

RepositoryFile<Aplicatie>::RepositoryFile():Repository()
{
	fileName = "";
}

RepositoryFile<Aplicatie>::RepositoryFile(const char* Name):Repository()
{
	fileName = Name;
	ifstream fin(Name);
	char* nume = new char[20];
	int status = 0;
	int memorie = 0;
	while (!fin.eof())
	{
		fin >> nume >> memorie >> status;
		if (nume != "" && (status == 1 || status == 2) && memorie >= 0)
		{
			Aplicatie a(nume, memorie, status);
			app.insert(pair<int, Aplicatie>(this->contor++, a));
		}
		
	}
	delete[] nume;
	fin.close();
}

void RepositoryFile<Aplicatie>::loadFile(const char* Name)
{
	app.clear();
	fileName = Name;
	ifstream fin(Name);
	char* nume = new char[20];
	int status = 0;
	int memorie = 0;
	while (!fin.eof())
	{
		fin >> nume >> memorie >> status;
		if (nume != "" && (status == 1 || status == 2) && memorie >= 0)
		{
			Aplicatie a(nume, memorie, status);
			app.insert(pair<int, Aplicatie>(this->contor++, a));
		}
	}
	delete[] nume;
	fin.close();
}

void RepositoryFile<Aplicatie>::saveFile()
{
	ofstream fout(fileName);
	map<int, Aplicatie>::iterator itr;
	for (itr = app.begin(); itr != app.end(); itr++)
		fout << itr->second.getName() << " " << itr->second.getConsumMemorie() << " " << itr->second.getStatus();
	fout.close();
}

RepositoryFile<Aplicatie>::~RepositoryFile()
{

}