#include <iostream>
#include "date.h"
#include <sstream> 

Date::Date(){
	month = 1;
	day = 1;
	year = 2000;
} // end constructor

void Date::init(std::string dateString){
	// dateString is mm//dd/yy
	// make a stringstream
	std::stringstream converter;
	std::string sMonth;
	std::string sDay;
	std::string sYear;


	// separate to temp strings
	converter.str(dateString);
	getline(converter, sMonth, '/');
	getline(converter, sDay, '/');
	getline(converter, sYear);

	// convert to ints
	
	converter.clear();
	converter.str("");

	converter << sMonth << " " << sDay << " " << sYear;
	converter >> month >> day >> year;
} // end init

void Date::printDate(){
	std::string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	if (month >= 1 && month <= 12){
		std::cout << months[month] << " " << day << ", " << year << std::endl;
	} // end if 
	else {
		std::cout << "Invalid date." << std::endl;
	} // end else 
	

} // end printDate
