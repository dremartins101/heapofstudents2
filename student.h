#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include <string>
#include "date.h"
#include "address.h"


class Student {
	private:
		std::string firstName;
		std::string lastName;
		Address address;
		Date birthDate;
		Date gradDate;
		int creditHours;
	public:
		Student();
		void init(std::string StudentString);
		void printStudent();
		std::string getLastFirst();
}; //end student class

#endif
