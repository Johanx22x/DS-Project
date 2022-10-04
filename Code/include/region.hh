#pragma once
#include <string>
#include <proxy.hh>
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

    Proxy<class Place> *places = nullptr;

    Region(std::string name, std::string id, std::string location);

    /**
     * Display all the nodes of the list
     *
     * @return nothing
     */
    void show();

    /**
     * Display all the nodes of the list (with only the name and the ID)
     *
     * @return nothing
     */
    void showByNameId();

    Region *search(std::string id);
};
    
