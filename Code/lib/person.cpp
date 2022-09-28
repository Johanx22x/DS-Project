#include <person.hh>
//#include <bits/types/time_t.h>
#include <string>

Person::Person(std::string name, std::string id, short int age, time_t joinDate) {
    this->name = name;
    this->id = id;
    this->age = age;
    this->joinDate = joinDate;
}

void Person::append(Person *node) {
    Person *curr = this;

    while (curr->next !=  nullptr) curr = curr->next;

    curr->next = node;
}
