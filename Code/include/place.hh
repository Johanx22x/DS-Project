/**
 * In this header file is defined all the Place class behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 24/09/2022
 */

#pragma once
#include <algorithm>
#include <climate.hh>
#include <cstdio>
#include <proxy.hh>
#include <string>

/**
 * Defines a structure that represents a place
 */
class Place {
public:
  std::string name;
  int population;
  double area;
  Place *next = this;
  class Region *region = nullptr;
  Proxy<class Climate> *climate = nullptr;

  /**
   * Place constructor
   */
  Place(std::string name, int population, double area, Region *region);

  /**
   * Display all the nodes information of the current instance
   */
  void show();

  /**
   * Display all the nodes Name of the current instance
   */
  void showByName();

  /**
   * Search a specific node in the current instance
   *
   * @return Place * The found node, nullptr if its not found
   */
  Place *find(std::string name);

  std::string tstr();
};
