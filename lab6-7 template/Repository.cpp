//void mapOfFlowers() {
//	map<char, Flower> m;
//	Flower f1("daisy", 5);
//	Flower f2("rose", 10);
//	Flower f3("tulip", 2);
//	Flower f4("dahlia", 20);
//	//pair<char, Flower> p;
//	//p(f1.getName()[0], f1);
//
//	m.insert(pair<char, Flower>(f1.getName()[0], f1));
//	m.insert(pair<char, Flower>(f2.getName()[0], f2));
//	m.insert(pair<char, Flower>(f3.getName()[0], f3));
//	m.insert(pair<char, Flower>(f4.getName()[0], f4));
//
//	cout << "map of flowers is : " << endl;
//	map<char, Flower>::iterator it = m.begin();
//	while (it != m.end()) {
//		cout << "key = " << (*it).first << " value = " << (*it).second << endl;
//		++it;
//	}
//	cout << endl;
//
//	map<char, Flower>::iterator itf = m.find(f2.getName()[0]);
//	if (itf != m.end())
//		cout << "Flower (" << f2 << ") belongs to the map ..." << endl;
//	else
//		cout << "Flower (" << f2 << ") doesn't belong to the map..." << endl;
//
//
//	int counter = m.count(f1.getName()[0]);
//	cout << "Flower (" << f1 << ") appears " << counter << " times in the map " << endl;
//}
