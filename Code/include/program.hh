/**
 * In this header file is defined all the Program class behavior and parameters
 * Also the first data of the program
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 06/09/2022
 */

#pragma once

// Define the DLL export declaration
#include <menu.hh>
#if defined(_WIN32)
#define DllExport __declspec(dllexport)
#else
#define DllExport
#endif

#include <climate.hh>
#include <instant.hh>
#include <person.hh>
#include <place.hh>
#include <rain.hh>

/**
 * Class that represents the Program
 */
class Program {
public:
  // NOTE: List instances declaration
  Person *people = new Person("Aaron Gonzalez", "2021", 19, "La Tigra", 1665147823);
  Region *regions = new Region("San Carlos", "A-1", "Alajuela, Costa Rica");
  Place *places = new Place("Santa Clara", 500, 1250.3, regions);
  Instant *instants = new Instant("Sunny sunday sunrise", 1588485717, 1588485717, 1588489021);
  Rain *rains = new Rain("Storm", "R-1", 13.32);
  Climate *climates = new Climate("1", 2.3, 4.1, 8.2, 0.4, 31.8, 'N', true, 1665147440, 1665147440, 1665147823, rains, places, people);

  // NOTE: Main menu definition
  Menu *menu = new Menu("Main Menu");

  // NOTE: Sub-menus definition
  Menu *dataManagement = new Menu("Data Management Menu");
  Menu *consultations = new Menu("Consultations Menu");
  Menu *reports = new Menu("Reports Menu");

  /**
   * Program constructor
   */
  Program();

  /**
   * Run the program
   */
  int run();
};
