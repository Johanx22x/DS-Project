/**
 * In this header file is defined all the climate struct behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 24/09/2022
 */

#pragma once
#include <person.hh>
#include <place.hh>
#include <rain.hh>
#include <region.hh>

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

  /**
   * Climate constructor
   */
  Climate(std::string id, double precipitation, double maxTemp, double minTemp,
          double windSpeed, double humidity, char windDirection, bool itRained,
          time_t date, time_t startTime, time_t endTime, Rain *rain,
          Place *place, Person *person);

  /**
   * This method display all the climate nodes in the current list
   * Show all the information available in the climate class params
   */
  void show();

  /**
   * This method display all the climate nodes in the current list
   * Only showing the ID of the climate node
   */
  void showById();

  /**
   * This method search a specific node in the current list, using the node ID 
   *
   * @param id The id of the node to search
   * @return Climate * A pointer to the finded element, nullptr if not finded
   */
  Climate *search(std::string id);

  /**
   * Return the climate instance data already formated in a string
   */
  std::string str();

  /**
   * Return the climate instance data already formated in a string using a tabulate format
   * Use this method to display a sub-list
   */
  std::string tstr();
};
