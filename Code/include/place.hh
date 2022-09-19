#pragma once
#include <string>
#include <proxy.hh>
#include <climate.hh>

/**
 * Defines a structure that represents a place
 */
class Place {
public:
    std::string name;
    short int population;
    double area;
    Place *next = nullptr;
    Proxy<Climate> *climate = nullptr;

    Place(std::string name, short int population, double area);
};
