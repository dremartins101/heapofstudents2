# heapofstudents2

## UML

```mermaid
classDiagram
    class Student {
        -firstName: string
        -lastName: string
        -address: Address*
        -birthDate: Date*
        -gradDate: Date*
        -creditHours: int
        +Student()
        +~Student()
        +init(string studentString)
        +printStudent()
        +getLastName() string
        +getLastFirst() string
    }

    class Address {
        -street: string
        -city: string 
        -state: string
        -zip: string 
        +Address()
        +init(street, city, state, zip)
        +printAddress() 
    }

    class Date {
        -month: int 
        -day: int 
        -year: int 
        +Date()
        +init(dateString) 
        +printDate() 
    }

    Student --> Address : manages heap pointer
    Student --> Date : manages heap pointers
