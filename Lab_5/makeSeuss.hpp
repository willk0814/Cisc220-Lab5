/*
 * MakeSeuss.hpp
 *
 *  Created on: May 15, 2019
 *      Author: willkoenig
 */

#ifndef MAKESEUSS_HPP_
#define MAKESEUSS_HPP_
#include "hashMap.hpp"
#include <iostream>
using namespace std;

class makeSeuss {
	hashMap *ht;
	string fn; // file name for input (“DrSeuss.txt”)
	string newfile; // name of output file
public:
	makeSeuss(string file,string newf,bool h1, bool c1);
	void readFile();
	void writeFile();
};





#endif /* MAKESEUSS_HPP_ */
