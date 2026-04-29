#include <iostream>
#include "date.h"
#include <vector>
#include <string>
#include <algorithm>
#include "address.h"
#include "student.h"
#include <fstream>

// prototypes
void loadStudents(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);

//void testAddress();
//void testDate();
//void testStudent();

int main(){
  std::vector<Student*> students;

  
  loadStudents(students);
  
  // Menu
  std::string choice = "";
  while (choice != "0") {
	  std::cout << "\n0) Quit" << std::endl;
	  std::cout << "1) Print all student names" << std::endl;
	  std::cout << "2) Print all student data" << std::endl;
	  std::cout << "3) Find a student" << std::endl;
	  std::cout << "\nPlease choose 0-3: ";
	  std::cin >> choice;
	  std::cin.ignore();

	  if (choice == "1") {
		  showStudentNames(students);
	} else if (choice == "2"){
		printStudents(students);
	} else if (choice == "3"){
		findStudent(students);
	}
}

delStudents(students);
  
  return 0;
} // end main


void loadStudents(std::vector<Student*>& students){
	std::ifstream file("students.csv");
	std::string line;

	if (file.is_open()){
		while (getline(file, line)) {
			if (line.length() > 0) {
				Student* s = new Student();
				s->init(line);
				students.push_back(s);
			}
		}
		file.close();
		std::cout << "Successfully loaded " << students.size() << " students" << std::endl;
	}
		 else {
			std::cout << "Could not open students.csv" << std::endl;
		}
} // end loadStudents

void showStudentNames(std::vector<Student*>& students){
	for (auto s : students) {
		std::cout << s->getLastFirst() << std::endl;
	}
} // end showStudentNames

void printStudents(std::vector<Student*>& students){
	for (auto s : students) {
		s->printStudent();
		std::cout << "__________________________________" << std::endl;
	}
} // end printStudents

void delStudents(std::vector<Student*>& students){
	for (size_t i = 0; i < students.size(); i++){
		delete students[i];
	}
	students.clear();
} // end delStudents
 
void findStudent(std::vector<Student*>& students){
	std::string searchTerm;
	std::cout << "last name of student: ";
	std::getline(std::cin, searchTerm);
	

	for (auto &c : searchTerm){
		c = std::tolower(c);
	}

	bool found = false;
	for (auto s : students) {
		std::string tempName = s->getLastName();
		for (auto &c : tempName){
			c = std::tolower(c);
		}


		if (tempName.find(searchTerm) != std::string::npos)
		{
			s->printStudent();
			std::cout << "________________________";
			found = true;
		}
	}
	if (!found) {
		std::cout << "No matches found for: " << searchTerm << std::endl;
	}
} // end findStudent
 
void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent
