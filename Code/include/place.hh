#pragma once
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

  Place(std::string name, int population, double area, Region *region);

  void show();

  void showByName();

  Place *find(std::string name);

  std::string tstr();
};
