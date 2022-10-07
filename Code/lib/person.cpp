#include <cstdio>
#include <ctime>
#include <person.hh>
//#include <bits/types/time_t.h>
#include <sstream>
#include <string>

Person::Person(std::string name, std::string id, short int age, std::string location, time_t joinDate) {
    this->name = name;
    this->id = id;
    this->age = age;
    this->joinDate = joinDate;
    this->location = location;
}

void Person::show() {
    Person *curr = this;

    while (curr != nullptr) {
        char dateBuf[200];
        tm *datetmp = gmtime(&this->joinDate);
        strftime(dateBuf, sizeof(dateBuf), "%a %b %d %Y", datetmp);

        printf("\nPerson name: %s\nPerson ID: %s\nPerson age: %d\nPerson location: %s\nPerson Join Date: %s\n", curr->name.c_str(), curr->id.c_str(), curr->age, curr->location.c_str(), dateBuf);
        if (curr->climates != nullptr) {
            printf("Climates sub-list:");
            curr->climates->show();
        }
        curr = curr->next;
    }
}

std::string Person::str() {
    std::ostringstream out;
    out << "Person's name: " << this->name.c_str() << "\nPerson's ID: " << this->id << "\nPerson's age: " << this->age << "\nPerson's join date: " << asctime(gmtime(&this->joinDate));
    return out.str();
}

void Person::showByNameId() {
    Person *curr = this;

    while (curr != nullptr) {
        printf("\nPerson name: %s\nPerson ID: %s\n", curr->name.c_str(), curr->id.c_str());
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
