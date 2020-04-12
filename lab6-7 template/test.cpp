#include "Aplicatie.h"
#include "Service.h"
#include "test.h"
#include <cassert>
#include <assert.h>
#include <iostream>
using namespace std;
void testareAdaugare()
{
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	assert(ser.getSize() == 0);
	ser.setTotalRAM(10);
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
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	assert(ser.getSize() == 2);
	ser.stergereElement(0);
	assert(ser.gasireElement(a) == -1 && ser.gasireElement(b) == 1);
	ser.stergereElement(1);
	assert(ser.gasireElement(a) == -1 && ser.gasireElement(b) == -1);
}

void testareUpdate()
{
	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it1,it2;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	Aplicatie c("TestUpdate1", 3, 2);
	Aplicatie d("TesUpdate2", 4, 1);
	ser.updateElement(0, c);
	ser.updateElement(1, d);
	all = ser.getEverything();
	it1 = all.find(0);
	it2 = all.find(1);
	assert(it1->second == c);
	assert(it2->second == d);
}

void testareFisiere()
{
	RepositoryFile<Aplicatie> rf;
	assert(rf.dim() == 0);
	rf.loadFile("testAplicatii.txt");
	assert(rf.dim() == 3);
	Aplicatie a = Aplicatie("test4", 2, 2);
	rf.addElem(a);
	rf.saveFile();
	rf.loadFile("testAplicatii.txt");
	assert(rf.dim() == 4);
	rf.delElem(3);
	rf.saveFile();
	rf.loadFile("testAplicatii.txt");
	assert(rf.dim() == 3);
}

void testareAdaugare2()
{

	Service ser;
	map<int, Aplicatie> all;
	map<int, Aplicatie>::iterator it;
	Aplicatie a("Test1", 1, 1);
	Aplicatie b("Test2", 2, 2);
	Aplicatie c("Test3", 11, 1);
	Aplicatie d("Test4", 10, 1);
	ser.setTotalRAM(10);
	ser.adaugareElement(a);
	ser.adaugareElement(b);
	ser.adaugareElement(c);
	all = ser.getEverything();
	it = all.find(2);
	assert(it->second.getStatus() == 1);
	ser.adaugareElement(d);
	all = ser.getEverything();
	it = all.find(0);
	assert(it->second.getStatus() == 2);
	it = all.find(3);
	assert(it->second.getStatus() == 1);
}