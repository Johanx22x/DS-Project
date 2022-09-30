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

void Place::showByName() {
    Place *curr = this;
    
    do {
        printf("\nPlace name: %s\n", curr->name.c_str());
        curr = curr->next;
    } while (curr != this);
}

Place* Place::search(std::string name) {
    Place *curr = this;

    do {
        if (curr->name == name) return curr;
        curr = curr->next;
    } while (curr != this);

    return nullptr;
}
