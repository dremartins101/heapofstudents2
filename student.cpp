#include <iostream>
#include <string>
#include <sstream>
#include "student.h"

Student::Student(){
    firstName = "";
    lastName = "";
    creditHours = 0;
} // end constructor

void Student::init(std::string studentString){
	std::stringstream ss(studentString);
	std::string street, city, state, zip, bday, gday, credits;

	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, street, ',');
	getline(ss, city, ',');
	getline(ss, state, ',');
	getline(ss, zip, ',');
	getline(ss, bday, ',');
	getline(ss, gday, ',');
	getline(ss, credits, ',');

	address.init(street, city, state, zip);
	birthDate.init(bday);
	gradDate.init(gday);

	// convert credits to int
	creditHours = std::stoi(credits);
} // end init

void Student::printStudent(){
	std::cout << firstName << " " << lastName << std::endl;
	address.printAddress();
	std::cout << "DOB: ";
	birthDate.printDate();
	std::cout << "Grad: ";
	gradDate.printDate();
	std::cout << "Credits: " << creditHours << std::endl;
} // end printstudent
 
std::string Student::getLastFirst(){
	return lastName + ", " + firstName;
} // end getlastfirst
