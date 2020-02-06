/*
 * Hash.cpp
 *
 *  Created on: Dec 5, 2018
 *      Author: student
 */

#include "Hash.hpp"

Hash::Hash() {
	// TODO Auto-generated constructor stub
	for(int i = 0; i < HASHSIZE; i++) {
		HashTable[i] = new HashNode* [20];
		for(int j = 0; j < 20; j++) {
			HashTable[i][j] = nullptr;
		}
		elemCollisions[i] = 0;
	}
}

Hash::~Hash() {
	// TODO Auto-generated destructor stub
	for(int i = 0; i < HASHSIZE; i++) {
		for(int j = 0; j < 20; j++) {
			if(HashTable[i][j] == nullptr) {
				break;
			}
			delete HashTable[i][j]->theEmployee;
			delete HashTable[i][j];
		}
		delete [] HashTable[i];
	}
}

bool Hash::insert(string theKey, Employee* theEmployee) {
	HashNode* thisHashNode = new HashNode;
	thisHashNode->key = theKey;
	thisHashNode->theEmployee = theEmployee;
	//HashNode* HashNodePtr = &thisHashNode;

	unsigned int Index = CompMADFunction(HashPolyFunction(theKey));

	if(Index >= HASHSIZE) {
		return false;
	}
	else if(theKey.size() == 0) {
		return false;
	}

	for(int i = 0; i < 20; i++) {
		if(HashTable[Index][i] == nullptr) {
			HashTable[Index][i] = thisHashNode;
			if(i > 0) {
				elemCollisions[Index]++;
			}
			return true;
		}
	}

	return false;
}

Employee* Hash::Find(string theKey) {
	unsigned int Index = CompMADFunction(HashPolyFunction(theKey));

	if(theKey.size() == 0) {
		return nullptr;
	}

	for(int i = 0; i < 20; i++) {
		if(HashTable[Index][i] == nullptr) {
			return nullptr;
		}

		if(HashTable[Index][i]->key == theKey) {
			return HashTable[Index][i]->theEmployee;
		}
	}

	return nullptr;
}

int Hash::CollisionCount(void) {
	int Collisions = 0;
	for(int i = 0; i < HASHSIZE; i++) {
		Collisions += elemCollisions[i];
	}

	return Collisions;
}

void Hash::PrintCollisionCount(void) {
	for(int i = 0; i < HASHSIZE; i++) {
		cout << "Element " << i << " collisions: " << elemCollisions[i] << endl;
	}
}

unsigned int Hash::HashPolyFunction(string key) {
	unsigned int hashKey = 0;
	for(unsigned int i = 0; i < key.size(); i++) {
		hashKey += key[i] * pow(3, i+1);
	}

	return hashKey;
}

unsigned int Hash::CompMADFunction(unsigned int hashKey) {
	unsigned int hashIndex = 0;
	int N = HASHSIZE;	//N is size of container
	int p = 1069;		//p must be greater than N
	int a = 13;			//a must be non negative and between 1 and p=1
	int b = 17;			//b must be non negative and between 0 and p=1

	hashIndex = ((a * hashKey + b) % p) % N;

	return hashIndex;
}
