//#include <bits/types/time_t.h>
#include <climate.hh>
#include <cstdio>

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

void Climate::append(Climate *node) {
    Climate *curr = this;

    while (curr->next != nullptr) curr = curr->next;

    curr->next = node;
}

void Climate::show() {
    Climate *curr = this;

    while (curr->next != nullptr) {
        printf("Climate: %f\n", curr->precipitation);
        curr = curr->next;
    }
}
