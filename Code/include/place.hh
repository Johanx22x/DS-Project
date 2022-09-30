#pragma once
#include <proxy.hh>
#include <region.hh>
#include <string>
#include <climate.hh>

/**
 * Defines a structure that represents a place
 */
class Place {
public:
    std::string name;
    int population;
    double area;
    Place *next = this;
    class Region *region = nullptr;
    Proxy<Climate> *climate = nullptr;

    Place(std::string name, int population, double area);

    void show();
};
