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
        printf("%s, %s\n", curr->name.c_str(), curr->location.c_str());
        curr = curr->next;
    }
}
