/*
 * Employee.hpp
 *
 *  Created on: Dec 5, 2018
 *      Author: student
 */

#ifndef EMPLOYEE_HPP_
#define EMPLOYEE_HPP_

#include <iostream>
using namespace std;

class Employee {
public:
	Employee();
	virtual ~Employee();

	string ID;
	string lastName;
	string firstName;
	int income;
};

#endif /* EMPLOYEE_HPP_ */
