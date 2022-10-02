#include <proxy.hh>
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
        if (curr->places != nullptr) {
            printf("Places sub-list:");
            curr->places->show();
        }
        curr = curr->next;
    }
}

void Region::showByNameID() {
    Region *curr = this;

    while (curr != nullptr) {
        printf("\nRegion name: %s\nRegion ID: %s\n", curr->name.c_str(), curr->id.c_str());
        curr = curr->next;
    }
}

Region *Region::search(std::string id) {
    Region *curr = this;

    while (curr != nullptr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }

    return nullptr;
}
