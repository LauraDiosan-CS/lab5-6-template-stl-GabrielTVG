#pragma once
#include <iostream>
#include <string>
using namespace std;
class Aplicatie {
private:
	char* nume;
	int consumMemorie;
	int status;
public:
	Aplicatie();
	Aplicatie(const char*, int, int);
	Aplicatie(const Aplicatie&);
	~Aplicatie();
	char* getName();
	void setName(char*);
	int getConsumMemorie();
	void setConsumMemorie(int);
	int getStatus();
	void setStatus(int);
	Aplicatie& operator=(const Aplicatie&);
	bool operator==(const Aplicatie&);
	friend ostream& operator<<(ostream&, Aplicatie);
	//friend istream& operator>>(istream&, Aplicatie&);
};