#pragma once
#include <rain.hh>

class Climate {
public:
    double precipitation;
    double maxTemp;
    double minTemp;
    double windSpeed;
    double humidity;
    char windDirection;
    bool itRained;
    Rain *rain = nullptr;
    Climate *next = nullptr;

    Climate(double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained);
};
