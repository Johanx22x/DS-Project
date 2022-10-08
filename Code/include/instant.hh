/**
 * In this header file is defined all the Instant struct behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 24/09/2022
 */

#pragma once
#include <string>

/**
 * Defines a structure that represents an instant in time
 */
class Instant {
public:
  std::string name;
  time_t date;
  time_t startTime;
  time_t endTime;
  Instant *prev = nullptr;
  Instant *next = nullptr;

  /**
   * Instant constructor
   */
  Instant(std::string name, time_t date, time_t startTime, time_t endTime);

  /**
   * Show all the nodes of a list
   *
   * @return nothing
   */
  void show();

  /**
   * Show all the nodes of a list
   *
   * @return nothing
   */
  void showByName();

  /**
   * Search an instant in the list
   *
   * @param id The element name to search
   * @return Instant * The finded node, nullptr in case of not finded
   */
  Instant *search(std::string name);

  /**
   * Format the current class data into a string
   *
   * @return string The format string with the class data
   */
  std::string str();
};
