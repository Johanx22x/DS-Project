#pragma once
#include <string>
#include <place.hh>

/**
 * Defines a structure that represents a region
 */
class Region {
public:
    std::string name;
    std::string id;
    std::string location;
    Region *next = nullptr;

    Proxy<Place> *places = nullptr;

    Region(std::string name, std::string id, std::string location);
};
    
