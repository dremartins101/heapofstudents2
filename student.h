#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <string>
#include "date.h"
#include "address.h"


class Student {
	private:
		std::string firstName;
		std::string lastName;
		// pointers to heap objs
		Address* address;
		Date* birthDate;
		Date* gradDate;
		int creditHours;
	public:
		Student();
		Student~(); // destructor to clean heap mem
		void init(std::string StudentString);
		void printStudent();

		std::string getLastName();
		std::string getFirstName();
		int getCreditHours();
		std::string getLastFirst();
}; //end student class

#endif
