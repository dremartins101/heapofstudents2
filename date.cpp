#include <iostream>
#include "date.h"
#include <sstream> 

Date::Date(){
	month = 1;
	day = 1;
	year = 1;
} // end constructor

void Date::init(std::string dateString){
	std::stringstream converter;

	std::string sMonth;
	std::string sDay;
	std::string sYear;

	converter.str(dateString);
	getline(converter, sMonth, '/');
	getline(converter, sDay, '/');
	getline(converter, sYear, '/');

	converter.clear();
	converter.str("");

	converter << sMonth << " " << sDay << " " << sYear;
	converter >> month >> day >> year;
}
void Date::printDate(){
	std::string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	if (month >= 1 && month <= 12){
		std::cout << months[month] << " " << day << ", " << year << std::endl;
	}
	else{
		std::cout << "Invalid date" << std::endl;
	}
} // end printDate
