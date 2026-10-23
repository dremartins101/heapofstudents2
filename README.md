# heapofstudents2

# heapofstudents

```mermaid

classDiagram

class Student{
    firstName: string
    lastName: string
    address: Adress
    birthDate: Date 
    gradDate: Date 
    creditHours: int
    Student()
    init(string studentString)
    printStudent()
    getLastFirst() string

}

class Address{
    street: string
    city: string 
    state: string
    zip: string 
    Address()
    init(street, city, state, zip)
    printAddress() 
}
class Date{
    month: int 
    day: int 
    year: int 
    Date()
    init(dateString) 
    printDate() 
}

Student --> Address 
Student --> Date

```


# algorithms:

## data Parsing

- loaded string into std::stringstream
- used getline with / to extract month, day, year into strings
- converted strings to integers with std::stoi
- stored integers in class member variables

## student data extraction

- loaded studentString into std::stringstream
- getline with , to pull out the parts in order they appeared (name, address, dates, credits)
- passed address into Address::init()
- date strings into date::init()
- final credit hours to integer

