#include <cstdio>
#include <place.hh>

Place::Place(std::string name, int population, double area) {
    this->name = name;
    this->population = population;
    this->area = area;
}

void Place::show() {
    Place *curr = this;
    
    do {
        printf("\nPlace name: %s\nPlace population: %d\nPlace area: %f\n", curr->name.c_str(), curr->population, curr->area);
        curr = curr->next;
    } while (curr != this);
}
