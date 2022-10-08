/**
 * In this header file is defined all the Region class behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 25/09/2022
 */

#pragma once
#include <place.hh>
#include <proxy.hh>
#include <string>

/**
 * Defines a structure that represents a region
 */
class Region {
public:
  std::string name;
  std::string id;
  std::string location;
  Region *next = nullptr;
  Proxy<class Place> *places = nullptr;

  /**
   * Region constructor
   */
  Region(std::string name, std::string id, std::string location);

  /**
   * Display all the nodes of the list
   *
   * @return nothing
   */
  void show();

  /**
   * Display all the nodes of the list (with only the name and the ID)
   *
   * @return nothing
   */
  void showByNameId();

  /**
   * Search for a specific node in the current Region class instance
   *
   * @param id The id to to search
   * @return Region * The found element, nullptr if not found
   */
  Region *search(std::string id);
};
