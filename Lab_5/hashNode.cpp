/*
 * hashNode.cpp
 *
 *  Created on: May 15, 2019
 *      Author: willkoenig
 */

#include <iostream>
using namespace std;
#include "hashNode.hpp"

hashNode::hashNode(){
	keyword = "";
	valuesSize = 0;
	currSize = 0;
	values = NULL;
}

hashNode::hashNode(string s){
	keyword = s;
	valuesSize = 100;
	currSize = 0;
	values = new string[valuesSize];
}
hashNode::hashNode(string s, string v){ //puts a value in the values array and initializes currSize to 1
	keyword = s;
	valuesSize = 100;
	currSize = 1;
	values = new string[valuesSize];
	values[0] = v;

}
void hashNode::addValue(string v){
	if (currSize < valuesSize) {
		values[currSize] = v;
		currSize++;
	} else {
		dblArray();
		values[currSize] = v;
		currSize++;
	}

}
void hashNode::dblArray(){
	string *tmp;
	tmp = new string[2*valuesSize];
	for (int i = 0; i < valuesSize; i++){
		tmp[i] = values[i];
	}
	values = tmp;
	valuesSize *= 2;
}
string hashNode::getRandValue() {
	cout << "getting random value" << endl;
	if (currSize == 0){
		cout << "currSize = 0" << endl;
		return "";
	} else {
		int i = rand()%currSize;
		return values[i];
	}

}






