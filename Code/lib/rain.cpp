#include <cstdio>
#include <rain.hh>
#include <string>

Rain::Rain(std::string name, std::string id, double rainfall) {
    this->name = name;
    this->id = id;
    this->rainfall = rainfall;
}

std::string Rain::averageRainfall() {
    // TODO: implement this functionality
    return "";
}

void Rain::show() {
    Rain *curr = this;

    while (curr != nullptr) {
        printf("%s %f\n", curr->name.c_str(), curr->rainfall);
        curr = curr->next;
    }
}
