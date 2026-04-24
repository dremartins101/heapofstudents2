#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string> 

class Address{
	private:
		std::string street, city, state, zip;
	public:
		Address();
		void init(std::string s, std::string c, std::string st, std::string z);
		void printAddress();
};

#endif
