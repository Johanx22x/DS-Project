#pragma once
#include <cstdio>
#include <string>
#include <proxy.hh>
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
    Proxy<class Climate> *climate = nullptr;

    Place(std::string name, int population, double area, Region *region);

    void show();

    void showByName();

    Place* search(std::string name);

    std::string str(); 
};
