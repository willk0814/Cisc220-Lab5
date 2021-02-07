/*
 * hashMap.cpp
 *
 *  Created on: May 15, 2019
 *      Author: willkoenig
 */

#include <iostream>
using namespace std;

#include "hashMap.hpp"


hashMap::hashMap(bool hash1, bool coll1){
	cout << "hashMap is running" << endl;
	h1 = hash1;
	c1 = coll1;
	mapSize = 1000;
	map = new hashNode*[mapSize];
	for (int i = 0; i < mapSize; i++){
		map[i] = NULL;
	}
	collisionct1 = 0;
	collisionct2 = 0;
	numKeys = 0;
}

void hashMap::addKeyValue(string k, string v){
	cout << "addKeyValue is running" << endl;
	//adds a node to the map at the correct index based on the key string, and then inserts the value
	//into the value field of hashNode
	//Pseudo-Code: should call hash function then set the new hashNode's value field
	//to hold the value string
	if(float(numKeys)/float(mapSize) >= 0.7){
		reHash();
	}

	int h = getIndex(k);
	int c;
	if (map[h] == NULL){
		map[h] = new hashNode(k,v);
		cout << "hash indicie: "<< h <<endl;
		numKeys +=1;
	} else if (map[h]->keyword != k) {
		while (map[h] != NULL) {
			if (c1) {
				collisionct1++;
				c = collHash1(h,k);
				h = c;
			} else {
				collisionct1++;
				c = collHash2(h,k);
				h = c;
			}
		}
		map[c] = new hashNode(k,v);
		numKeys+=1;

	} else if (map[h]->keyword == k) {
		cout << "adding value: "<< v <<endl;
		map[h]->addValue(v);

	}
}

int hashMap::getIndex(string k){
	cout << "getIndez is running" << endl;
	// uses calcHash and reHash to calculate and return the index of where the keyword
	// k should be inserted into the map array
	if (float(numKeys)/float(mapSize) >= 0.7) {
		reHash();
	}
	if(h1) {
		return calcHash(k);

	} else {
		return calcHash2(k);
	}
}

int hashMap::calcHash(string k) {
	cout << "calcHash is running" << endl;
	//first hashing function
	int len = k.length();
	int hash = 0;
	for (int i = 0; i < len; i++) {
		hash += (int)k[i];
	}
	return hash % mapSize;
}

int hashMap::calcHash2(string k){
	cout << "calcHash2 is running" << endl;
	int len = k.length();
	int hash = 0;
	for(int i = 0; i < len; i++){
		if (i < len/4){
			hash += (int)k[i] * 4;
		}else if(i > len/4 && i < len/2){
			hash += (int)k[i] * 3;
		}else {
			hash += (int)k[i];
		}
	}
	return hash%mapSize;
}

int hashMap::getClosestPrime(){
	cout << "getClosestPrime is running" << endl;
	//helper function for reHash, returns the closest prime to a number , can include as a parameter an
	//array of prime numbers that can be searched through
	int count = 0;
	for(int j = 2; j < mapSize; j++){
		if(mapSize % j == 0){
			count = 1;
		}
	}
	if (count > 0) {
		mapSize++;
		getClosestPrime();
	} else {
		return mapSize;
	}
}

void hashMap::reHash(){
	cout << "reHash is running" << endl;
	//creates a longer hash array of size*2 rounded up to the nearest prime and rehashes the keys
	hashNode** tmp = map;
	int tmpSize = mapSize;
	mapSize *= 2;
	mapSize = getClosestPrime();
	map = new hashNode*[mapSize];
	for (int i = 0; i < tmpSize; i++) { // NULL value
		if (tmp[i] != NULL) {
			for (int j = 0; j < tmp[i]->currSize; j++) {
				addKeyValue(tmp[i]->keyword, tmp[i]->values[j]);
			}
		}
	}
	cout <<"********"<<endl;
}

int hashMap::collHash1(int h, string k){
	cout << "collHash1 is running" << endl;
	//first collision handling function -> linear probing function
	while (map[h] != NULL) { // not an empty spot
		h++; // increment new index
		collisionct2++; //increment collision count
	}
	return h;
}

int hashMap::collHash2(int h, string k){
	cout << "collHash2 is running" << endl;
	//second collision handling function -> quadratic probing function
	int j = 1;
	while (map[h] != NULL) { // not an empty spot
		h += (j*j); // calculate new index
		collisionct2++; //increment collision count
	}
	return h;

}

int hashMap::findKey(string k) {
	cout << "findKey is running" << endl;
	//finds the key in the array and returns the index, if it's not in the array return -1
	int h = getIndex(k);
	if(map[h]->keyword == k) {
		return h;
	} else {
		while((map[h] != NULL) || (map[h]->keyword != k)) {
			if (c1) {
				h = collHash1(h, k);
			} else{
				h = collHash2(h, k);
			}
		}
		if(map[h]->keyword == k) {
			return h;
		} else {
			return -1;
		}
	}
}

void hashMap::printMap(){
	cout << "printMap is running" << endl;
	//iterates through the array and prints
	for(int i = 0; i < mapSize; i++){
		if (map[i]!= NULL){
			cout << map[i]->keyword << ": ";
			for(int j = 0; j < map[i]->valuesSize; j++){
				cout << map[i]->values[j]<< " ";
			}
		}cout << endl;
	}
	cout << endl;
}



