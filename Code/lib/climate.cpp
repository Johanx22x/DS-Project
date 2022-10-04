//#include <bits/types/time_t.h>
#include <person.hh>
#include <climate.hh>
#include <cstdio>
#include <sstream>

Climate::Climate(std::string id, double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained, time_t date, time_t startTime, time_t endTime, Rain *rain, Place *place, Person *person) {
    this->id = id;
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
    this->rain = rain;
    this->place = place;
    this->person = person;
}

void Climate::append(Climate *node) {
    Climate *curr = this;

    while (curr->next != nullptr) curr = curr->next;

    curr->next = node;
}

void Climate::show() {
    // TODO: Show more data
    Climate *curr = this;

    while (curr != nullptr) {
        printf("\nClimate: %s\n", curr->id.c_str());
        printf("Associate rain: \n\tID: %s\n\tName: %s\n", curr->rain->id.c_str(), curr->rain->name.c_str());
        curr = curr->next;
    }
}

void Climate::showById() {
    Climate *curr = this;

    while (curr != nullptr) {
        printf("\nClimate: %s\n", curr->id.c_str());
        curr = curr->next;
    }
}

Climate *Climate::search(std::string id) {
    Climate *curr = this;

    while (curr != nullptr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }

    return nullptr;
}

std::string Climate::str() {
    std::string myStr;
    std::ostringstream os;
    os << "\tClimate ID: " << id << "\n\tClimate location: " << place->name << "\n";
    myStr = os.str(); //now convert stream to my_str string
    return myStr;
}
