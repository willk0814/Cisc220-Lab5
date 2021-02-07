/*
 * MakeSeuss.cpp
 *
 *  Created on: May 15, 2019
 *      Author: willkoenig
 */

#include "makeSeuss.hpp"

#include "hashMap.hpp"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

makeSeuss::makeSeuss(string f1,string f2,bool h1, bool c1) {
	ht = new hashMap(h1,c1);
	newfile = f2;
	fn = f1;
	readFile();
	writeFile();
}
void makeSeuss::readFile() {
	cout << "reading file" << endl;
	ifstream infile(fn.c_str(),ios::in); // open file
	string key = "";
	string value= "";
	infile>> key;
	ht->first = key;
	while (infile >> value) { // loop getting single characters
		cout << key <<": " << value << endl;
		ht->addKeyValue(key,value);
		key = value;
		value = "";
	}
	ht->addKeyValue(key,value);
	cout << endl;
	infile.close();
}
void makeSeuss::writeFile() {
	cout << "writing file" << endl;
	ofstream outfile(newfile.c_str(),ios::out);
	outfile << ht->first << " ";
	string key = "";
	string value = ht->map[ht->getIndex(ht->first)]->getRandValue();
	int ct = 0;
	int len = 0;
	while (ct < 500 && value != "") {
		cout << "while" << endl;
		key = value;
		outfile << key << " ";
		if (len == 11) {
			outfile << "\n";
			len = 0;
		}
		else len++;
		value = ht->map[ht->getIndex(key)]->getRandValue();
		ct ++;
	}
	cout << "Original Collisions: " << ht->collisionct1 << endl;
	cout << "Secondary Collisions: " << ht->collisionct2 << endl;
	outfile.close();
}



