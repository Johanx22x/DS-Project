#include <cstdio>
#include <place.hh>

Place::Place(std::string name, short int population, double area) {
    this->name = name;
    this->population = population;
    this->area = area;
}

void Place::show() {
    Place *curr = this;
    
    do {
        printf("%s\n", curr->name.c_str());
        curr = curr->next;
    } while (curr != this);
}
