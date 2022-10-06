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
   */
  Instant *search(std::string name);

  std::string str();
};
