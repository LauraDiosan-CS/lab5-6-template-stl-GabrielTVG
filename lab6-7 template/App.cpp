#include <iostream>
#include "UI.h"
#include "test.h"
using namespace std;
int main()
{
	UI ui;
	cout << "teste"<<endl;
	testareAdaugare();
	testareStergereSiCautare();
	testareUpdate();
	testareAdaugare2();
	cout << "gj"<<endl;
	ui.run();
	cout << endl;
	return 0;
}