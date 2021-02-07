/*
 * main.cpp
 *
 *  Created on: May 15, 2019
 *      Author: willkoenig
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "hashMap.hpp"
#include "makeSeuss.hpp"

using namespace std;

string drSeuss = "DrSeuss.txt";
string book1 = "Hash1Collision1.txt";
string book2 = "Hash1Collision2.txt";
string book3 = "Hash2Collision1.txt";
string book4 = "Hash2Collision2.txt";

int main() {
	srand(time(NULL));

//	makeSeuss(drSeuss, book1, true, true);
//	makeSeuss(drSeuss, book2, true, false);
	makeSeuss(drSeuss, book3, false, true);
//	makeSeuss(drSeuss, book4, false, false);

}

