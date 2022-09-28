//#include <bits/types/time_t.h>
#include <climate.hh>

Climate::Climate(double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained, time_t date, time_t startTime, time_t endTime) {
    this->precipitation = precipitation;
    this->maxTemp = maxTemp;
    this->minTemp = minTemp;
    this->windSpeed = windSpeed;
    this->humidity = humidity;
    this->windDirection = windDirection;
    this->itRained = itRained;
    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;
}
