#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "student.h"

//void testAddress();
//void testDate();
//void testStudent();

void loadStudents(Std::vector<Student*>& students);void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

int main(){
  std::vector<Student*> students;

  loadStudents(students);
  std::string choice;

  while (choice != "0"){
	  choice = menu();

	  if (choice == "1"){
		  showStudentNames(students);
	  }
	  else if (choice == "2"){
		  printStudents(students);
	  }

	  else if (choice == "3"){
		  findStudent(students);
	  } 
	  else if (choice != "0"){
		  std::cout << "Invalid choice" << std::endl;
	  }
	}

  delStudents(students);

  return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
	std::ifstream file("students.csv");

	if(!file.is_open()){
		std::cout << "Error opening file" << std::endl;
		return;
	}

	std::string line;

	while (getline(file, line)){
		Student* student = new Student();

		student->init(line);
		students.push_back(student);
	}
	file.close();
}

void priintStudents(std::vector<Student*>& students){
	for(Student* student : students){
		student->printStudent();

		std::cout << "______________" << std::endl;
	}
}

void showStudentNames(std::vector<Student*>& students){
	for (Student* student : students){
		std::cout << student -> getLastFirst() << std::endl;
	}
}

void findStudent(std::vector<Student*>& students){
	std::string searchName;

	std::cout << "Last name of student : ";
	getline(std::cin, searchName);

	bool found = false;

	for (Student* student : students){
		if (student->getLastFirst().find(searchName)!= std::string::npos){
			student->printStudent();

			std::cout << "________________________" << std::endl;

			found = true;
		}
	}

	if (!found){
		std::cout << "No students found" << std::endl;
	}
}

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
