/**
 * In this header file is defined all the Person class behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 24/09/2022
 */

#pragma once
#include <climate.hh>
#include <proxy.hh>
#include <string>

/**
 * Defines a structure that represents a person
 */
class Person {
public:
  std::string name;
  std::string id;
  short int age;
  std::string location;
  time_t joinDate;
  Person *prev = nullptr;
  Person *next = nullptr;
  Proxy<class Climate> *climates = nullptr;

  /**
   * Person constructor
   *
   * @param name      The name of the person
   * @param id        The id of the person
   * @param age       The age of the person
   * @param joinDate  Date in which the person was registered
   */
  Person(std::string name, std::string id, short int age, std::string location,
         time_t joinDate);

  /**
   * Show all the nodes of the struct
   *
   * @return nothing
   */
  void show();

  /**
   * Show all the nodes of the struct (only printing the name and the id)
   *
   * @return nothing
   */
  void showByNameId();

  /**
   * Search a person in the list
   *
   * @param id The element id to search
   */
  Person *search(std::string id);

  /**
   * Return a formated string with the current instance data
   *
   * @return string The data formated
   */
  std::string str();
};
