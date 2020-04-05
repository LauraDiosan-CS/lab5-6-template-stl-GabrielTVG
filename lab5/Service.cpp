#include "Service.h"
#include "Aplicatie.h"
#include "Repository.h"
Service::Service()
{

}

//Service::Service(const Repository& r)
//{
//	rep = r;
//}
//void setRepo(const Repository& r)
//{
//	rep = r;
//}

void Service::adaugareElement(const Aplicatie& a)
{
	this->rep.addElem(a);
}

int Service::gasireElement(const Aplicatie& a)
{
	return this->rep.findElem(a);
}

void Service::stergereElement(int pozitie)
{
	this->rep.delElem(pozitie);
}

void Service::updateElement(int pozitie, Aplicatie a)
{
	this->rep.updateElem(pozitie, a);
}

int Service::getSize()
{
	return this->rep.dim();
}

map<int, Aplicatie>Service::getEverything()
{
	return this->rep.getAll();
}

Service::~Service()
{

}