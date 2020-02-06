//*****************
//Project Name: Hash Class
//Project Description: Create a Hash Class
//Project Author: Macaldo, Aaron Jay
//Is this an extra credit Project:  No
//Date completed: 12/07/2018
//Operating system used: Windows
//IDE Used:  Eclipse
//*****************

#include <iostream>
#include <fstream>
#include "Hash.hpp"
#include "Employee.hpp"

using namespace std;

string mklower(string);

int main() {
	Hash hashEmployees;
	Employee* theEmployee = nullptr;
	string userInput = "";

	ifstream inputEmployee;

	inputEmployee.open("Employees.txt");

	if(inputEmployee.is_open()) {
		while(!inputEmployee.eof()) {
			theEmployee = new Employee();
			inputEmployee >> theEmployee->ID;
			inputEmployee >> theEmployee->lastName;
			inputEmployee >> theEmployee->firstName;
			inputEmployee >> theEmployee->income;
			hashEmployees.insert(theEmployee->ID, theEmployee);
		}
		inputEmployee.close();
	}

	else {
		cout << "Unable to Open" << endl;
	}

	cout << "Total Collisions: " << hashEmployees.CollisionCount() << endl << endl;

	hashEmployees.PrintCollisionCount();

	cout << "Input an Employee Key to find: ";
	cin >> userInput;
	while(mklower(userInput) != "end") {
		Employee* theEmployee = hashEmployees.Find(userInput);
		if(theEmployee == nullptr) {
			cout << "Employee not found" << endl;
			cout << userInput << endl;
		}
		else {
			cout << "Employee Key: " << theEmployee->ID << endl;
			cout << "Employee Name: " << theEmployee->firstName << " " << theEmployee->lastName << endl;
			cout << "Employee Salary: " << theEmployee->income << endl;
		}
		cout << "Input an Employee Key to find or type 'end' to exit: ";
		cin >> userInput;
	}




	cout << "Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

string mklower(string theString) {
	string lowerString;
	for(unsigned int i = 0; i < theString.size(); i++) {
		lowerString += tolower(theString[i]);
	}

	return lowerString;
}
