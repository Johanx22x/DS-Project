#include <cstdio>
#include <region.hh>
#include <string>

Region::Region(std::string name, std::string id, std::string location) {
    this->name = name;
    this->id = id;
    this->location = location;
}

void Region::show() {
    Region *curr = this;

    while (curr != nullptr) {
        printf("\nRegion name: %s\nRegion ID: %s\nRegion location: %s\n", curr->name.c_str(), curr->id.c_str(), curr->location.c_str());
        curr = curr->next;
    }
}
