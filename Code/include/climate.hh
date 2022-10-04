#pragma once
//#include <bits/types/time_t.h>
#include <person.hh>
#include <place.hh>
#include <region.hh>
#include <rain.hh>

/**
 * Defines a structure that represents the Climate
 */
class Climate {
public:
    std::string id;
    double precipitation;
    double maxTemp;
    double minTemp;
    double windSpeed;
    double humidity;
    char windDirection;
    bool itRained;
    time_t date;
    time_t startTime;
    time_t endTime;
    class Place *place = nullptr;
    class Person *person = nullptr;
    Rain *rain = nullptr;
    Climate *next = nullptr;

    Climate(std::string id, double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained, time_t date, time_t startTime, time_t endTime, Rain *rain, Place *place, Person *person);

    void append(Climate *node);

    void show();

    void showById();

    Climate *search(std::string id);

    std::string str();
};
