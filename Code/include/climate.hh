#pragma once
#include <bits/types/time_t.h>
#include <rain.hh>

/**
 * Defines a structure that represents the Climate
 */
class Climate {
public:
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
    Rain *rain = nullptr;
    Climate *next = nullptr;

    Climate(double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained, time_t date, time_t startTime, time_t endTime);
};
