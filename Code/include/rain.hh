/**
 * In this header file is defined all the Rain class behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 23/09/2022
 */

#pragma once
#include <string>

/**
 * Defines a structure that represents rain
 */
class Rain {
public:
  std::string name;
  std::string id;
  double rainfall;
  Rain *next = nullptr;

  /**
   * Rain constructor
   */
  Rain(std::string name, std::string id, double rainfall);

  /**
   * Show all the rain nodes of a list
   */
  void show();

  /**
   * Show all the rain nodes of a list (only prints the name and the id)
   */
  void showByNameId();

  /**
   * Returns the average rainfall for the current period
   *
   * @returns std::string A neatly formatted string that denotes the average
   * rainfall
   */
  std::string fmtAverage();

  /**
   * @brief Calculates the average rainfall for the entire rain list, not a
   * single node or proxy node
   *
   * @returns double The average rainfall between 0 and 1
   */
  double average();

  /**
   * Search an element in the current Rain class instance
   *
   * @param id The id of the node to search
   * @return Rain * The found node, nullptr in case of not found
   */
  Rain *search(std::string id);

  /**
   * @brief Returns a neatly formatted string that represents the total rainfall
   * as a string
   *
   * @returns std::string A neatly formatted string
   */
  std::string fmtRainfall();

private:
  /**
   * @brief This does what you think it does
   *
   * @returns double The minimum value amongst the entire rains list
   */
  double min();
  /**
   * @brief This does what you think it does
   *
   * @returns double The maximum value amongst the entire rains list
   */
  double max();
};
