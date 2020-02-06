/*
 * Hash.hpp
 *
 *  Created on: Dec 5, 2018
 *      Author: student
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include <iostream>
#include <cmath>
#include "Employee.hpp"

const int HASHSIZE = 1000;

struct HashNode {
	string key;
	Employee* theEmployee;
};

using namespace std;

class Hash {
public:
	Hash();
	virtual ~Hash();

	bool insert(string, Employee*);
	Employee* Find(string);
	int CollisionCount(void);
	void PrintCollisionCount(void);


private:
	HashNode** HashTable[HASHSIZE];
	int elemCollisions[HASHSIZE];
	unsigned int HashPolyFunction(string);
	unsigned int CompMADFunction(unsigned int);
};

#endif /* HASH_HPP_ */
