#pragma once
#include <string>

class Rain {
public:
    std::string name;
    std::string id;
    double rainfall;
    Rain *next = nullptr;

    Rain(std::string name, std::string id, double rainfall);

    std::string averageRainfall();
};
