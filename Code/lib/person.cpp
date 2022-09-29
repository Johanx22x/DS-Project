#include <cstdio>
#include <ctime>
#include <person.hh>
//#include <bits/types/time_t.h>
#include <string>

Person::Person(std::string name, std::string id, short int age, time_t joinDate) {
    this->name = name;
    this->id = id;
    this->age = age;
    this->joinDate = joinDate;
}

void Person::show() {
    Person *curr = this;

    while (curr != nullptr) {
        printf("\nName: %s\nID: %s\nAge: %d\nJoin Date: %s", curr->name.c_str(), curr->id.c_str(), curr->age, asctime(gmtime(&curr->joinDate)));
        curr = curr->next;
    }
}

Person *Person::search(std::string id) {
    Person *curr = this;
    
    while (curr != nullptr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }

    return nullptr;
}
