#pragma once
#include <string>

/**
 * Defines a structure that represents rain
 */
class Rain {
public:
    std::string name;
    std::string id;
    double rainfall;
    Rain *next = nullptr;

    Rain(std::string name, std::string id, double rainfall);

    /**
     * Show all the rain nodes of a list
     */
    void show();

    /**
     * Returns the average rainfall for the current period
     *
     * @returns std::string A neatly formatted string that denotes the average rainfall
     */
    std::string averageRainfall();
};
