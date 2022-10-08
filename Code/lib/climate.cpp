/**
 * Here is defined all the climate methods from the climate header file
 * See the header file to see the documentation of these methods
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 04/10/2022
 */

#include <person.hh>
#include <climate.hh>
#include <cstdio>
#include <sstream>

/// See the Climate header file for the documentation
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

/// See the Climate header file for the documentation
void Climate::append(Climate *node) {
    Climate *curr = this;

    while (curr->next != nullptr) curr = curr->next;

    curr->next = node;
}

/// See the Climate header file for the documentation
void Climate::show() {
    Climate *curr = this;

    while (curr != nullptr) {
        printf("\n%s\n", curr->str().c_str());
        printf("Associate rain: \n\tID: %s\n\tName: %s\n\tRainfall: %s\n\tRainfall value: %f\n", curr->rain->id.c_str(), curr->rain->name.c_str(), curr->rain->fmtRainfall().c_str(), curr->rain->rainfall);
        curr = curr->next;
    }
}

/// See the Climate header file for the documentation
void Climate::showById() {
    Climate *curr = this;

    while (curr != nullptr) {
        printf("\nClimate: %s\n", curr->id.c_str());
        curr = curr->next;
    }
}

/// See the Climate header file for the documentation
Climate *Climate::search(std::string id) {
    Climate *curr = this;

    while (curr != nullptr) {
        if (curr->id == id) return curr;
        curr = curr->next;
    }

    return nullptr;
}

/// See the Climate header file for the documentation
std::string Climate::str() {
    std::ostringstream out;
    char endBuf[13];
    char startBuf[13];
    char dateBuf[200];

    tm *datetmp = gmtime(&this->date);
    strftime(dateBuf, sizeof(dateBuf), "%a %b %d %Y", datetmp);

    tm *endtmp = gmtime(&this->endTime);
    strftime(endBuf, sizeof(endBuf), "%H:%M:%S", endtmp);

    tm *starttmp = gmtime(&this->startTime);
    strftime(startBuf, sizeof(startBuf), "%H:%M:%S", starttmp);

    std::string rainState = (itRained) ? "Yes" : "No";

    out << "Climate ID: " << this->id << "\nClimate location: " << place->name 
        << "\nPrecipitation: " << this->precipitation << "\nMaximum temperature: " 
        << this->maxTemp << "\nMinimum temperature: " << this->minTemp 
        << "\nWind speed: " << this->windSpeed << "\nHumidity: " << this->humidity 
        << "\nWind direction: " << this->windDirection << "\nRain: " << rainState 
        << "\nDate: " << dateBuf << "\nStart Time: " << startBuf << "\nEnd Time: " << endBuf;
    return out.str();
}

/// See the Climate header file for the documentation
std::string Climate::tstr() {
    std::ostringstream out;
    char endBuf[13];
    char startBuf[13];
    char dateBuf[200];

    tm *datetmp = gmtime(&this->date);
    strftime(dateBuf, sizeof(dateBuf), "%a %b %d %Y", datetmp);

    tm *endtmp = gmtime(&this->endTime);
    strftime(endBuf, sizeof(endBuf), "%H:%M:%S", endtmp);

    tm *starttmp = gmtime(&this->startTime);
    strftime(startBuf, sizeof(startBuf), "%H:%M:%S", starttmp);

    std::string rainState = (itRained) ? "Yes" : "No";

    out << "\tClimate ID: " << this->id << "\n\tClimate location: " << place->name 
        << "\n\tPrecipitation: " << this->precipitation << "\n\tMaximum temperature: " 
        << this->maxTemp << "\n\tMinimum temperature: " << this->minTemp 
        << "\n\tWind speed: " << this->windSpeed << "\n\tHumidity: " << this->humidity 
        << "\n\tWind direction: " << this->windDirection << "\n\tRain: " << rainState 
        << "\n\tDate: " << dateBuf << "\n\tEnd Time: " << endBuf << "\n\tStart Time: " << startBuf;
    return out.str();
}
