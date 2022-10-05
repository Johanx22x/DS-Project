#include <cstdio>
#include <place.hh>
#include <sstream>

Place::Place(std::string name, int population, double area, Region *region) {
    this->name = name;
    this->population = population;
    this->area = area;
    this->region = region;
}

void Place::show() {
    Place *curr = this;
    
    do {
        printf("\nPlace name: %s\nPlace population: %d\nPlace area: %f\nPlace region: %s\n", curr->name.c_str(), curr->population, curr->area, curr->region->name.c_str());
        if (curr->climate != nullptr) {
            printf("Climates sub-list:");
            curr->climate->show();
        }
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

Place* Place::find(std::string name) {
    Place *curr = this;

    do {
        if (curr->name == name) return curr;
        curr = curr->next;
    } while (curr != this);

    return nullptr;
}

std::string Place::str() {
    std::string myStr;
    std::ostringstream os;
    os << "\tPlace name: " << name << "\n\tPlace population: " << population << "\n\tPlace area: " << area << "\n";
    myStr = os.str(); //now convert stream to my_str string
    return myStr;
}
