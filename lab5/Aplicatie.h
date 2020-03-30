#pragma once
class Aplicatie {
private:
	char* nume;
	int consumMemorie;
	int status;
public:
	Aplicatie();
	Aplicatie(char*, int, int);
	Aplicatie(const Aplicatie&);
	~Aplicatie();
	Aplicatie& operator=(const Aplicatie&);

};