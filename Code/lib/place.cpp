/**
 * Here is implemented all the methods from the rain header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 06/10/2022
 */

#include <cstdio>
#include <place.hh>
#include <sstream>

/// See the documentation declared in the place header file
Place::Place(std::string name, int population, double area, Region *region) {
    this->name = name;
    this->population = population;
    this->area = area;
    this->region = region;
}

/// See the documentation declared in the place header file
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

/// See the documentation declared in the place header file
void Place::showByName() {
    Place *curr = this;
    
    do {
        printf("\nPlace name: %s\n", curr->name.c_str());
        curr = curr->next;
    } while (curr != this);
}

/// See the documentation declared in the place header file
Place* Place::find(std::string name) {
    Place *curr = this;

    do {
        if (curr->name == name) return curr;
        curr = curr->next;
    } while (curr != this);

    return nullptr;
}

/// See the documentation declared in the place header file
std::string Place::tstr() {
    std::string myStr;
    std::ostringstream os;
    os << "\tPlace name: " << name << "\n\tPlace population: " << population << "\n\tPlace area: " << area;
    myStr = os.str(); //now convert stream to my_str string
    return myStr;
}
