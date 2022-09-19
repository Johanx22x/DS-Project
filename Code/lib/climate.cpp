#include <climate.hh>

Climate::Climate(double precipitation, double maxTemp, double minTemp, double windSpeed, double humidity, char windDirection, bool itRained) {
    this->precipitation = precipitation;
    this->maxTemp = maxTemp;
    this->minTemp = minTemp;
    this->windSpeed = windSpeed;
    this->humidity = humidity;
    this->windDirection = windDirection;
    this->itRained = itRained;
}
