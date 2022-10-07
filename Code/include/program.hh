#pragma once

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

class Program {
public:
  Person *people =
      new Person("Johan Rodriguez", "2022141892", 18, "Santa Rosa", 1531721412);
  Region *regions = new Region("San Carlos", "5", "Alajuela, Costa Rica");
  Place *places = new Place("Santa Clara", 500, 1250.3, regions);
  Instant *instants = new Instant("Sunny monday", 1588485717, 1588485717, 1588489021);
  Rain *rains = new Rain("Storm", "1", 0.2);
  Climate *climates = new Climate("1", 2.3, 4.1, 8.2, 0.4, 31.8, 'N', true, 1665147440,
                                  1665147440, 1665147823, rains, places, people);
  Menu *menu = new Menu("Main Menu");

  // NOTE: Sub-menus definition
  Menu *dataManagement = new Menu("Data Management Menu");
  Menu *consultations = new Menu("Consultations Menu");
  Menu *reports = new Menu("Reports Menu");
  Program();

  int run();
};
