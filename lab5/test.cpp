#include "Aplicatie.h"
#include "Service.h"
#include "test.h"
#include <cassert>
#include <assert.h>
#include <iostream>
using namespace std;
void testareAdaugare()
{
	Repository rep;
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	assert(rep.dim() == 0);
	rep.addElem(a);
	all = rep.getAll();
	it = all.find(0);
	assert(rep.dim() == 1 && it->second == a);
	rep.addElem(b);
	all = rep.getAll();
	it = all.find(1);
	assert(rep.dim() == 2 && it->second == b);
	assert(ser.getSize() == 0);
	ser.adaugareElement(a);
	all = ser.getEverything();
	it = all.find(0);
	assert(ser.getSize() == 1 && it->second == a);
	ser.adaugareElement(b);
	all = ser.getEverything();
	it = all.find(1);
	assert(ser.getSize() == 2 && it->second == b);
}

void testareStergereSiCautare()
{
	Repository rep;
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	rep.addElem(a);
	rep.addElem(b);
	assert(ser.getSize() == 2);
	assert(rep.dim() == 2);
	rep.delElem(0);
	ser.stergereElement(0);
	assert(rep.findElem(a) == -1 && rep.findElem(b) == 1);
	assert(ser.gasireElement(a) == -1 && ser.gasireElement(b) == 1);
	ser.stergereElement(1);
	rep.delElem(1);
	assert(rep.findElem(a) == -1 && rep.findElem(b) == -1);
	assert(ser.gasireElement(a) == -1 && ser.gasireElement(b) == -1);
}

void testareUpdate()
{
	Repository rep;
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it1,it2;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	rep.addElem(a);
	rep.addElem(b);
	Aplicatie c("TestUpdate1", 3, 2);
	Aplicatie d("TesUpdate2", 4, 1);
	rep.updateElem(0, c);
	rep.updateElem(1, d);
	ser.updateElement(0, c);
	ser.updateElement(1, d);
	all = ser.getEverything();
	it1 = all.find(0);
	it2 = all.find(1);
	assert(it1->second == c);
	assert(it2->second == d);
	all = rep.getAll();
	it1 = all.find(0);
	it2 = all.find(1);
	assert(it1->second == c);
	assert(it2->second == d);

}