/**
 * Here is implemented all the methods from the region header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 01/10/2022
 */

#include <proxy.hh>
#include <cstdio>
#include <region.hh>
#include <string>

/// See the documentation declared in the header file
Region::Region(std::string name, std::string id, std::string location) {
    this->name = name;
    this->id = id;
    this->location = location;
}

/// See the documentation declared in the header file
void Region::show() {
    Region *curr = this;

    while (curr != nullptr) {
        printf("\nRegion name: %s\nRegion ID: %s\nRegion location: %s\n", curr->name.c_str(), curr->id.c_str(), curr->location.c_str());
        if (curr->places != nullptr) {
            printf("Places sub-list:");
            curr->places->show();
        }
        curr = curr->next;
    }
}

/// See the documentation declared in the header file
void Region::showByNameId() {
    Region *curr = this;

    while (curr != nullptr) {
        printf("\nRegion name: %s\nRegion ID: %s\n", curr->name.c_str(), curr->id.c_str());
        curr = curr->next;
    }
}

/// See the documentation declared in the header file
Region *Region::search(std::string id) {
    Region *curr = this;

    while (curr != nullptr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }

    return nullptr;
}
