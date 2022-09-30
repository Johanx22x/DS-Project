#pragma once
//#include <bits/types/time_t.h>
#include <string>
#include <proxy.hh>
#include <climate.hh>
#include <place.hh>

/**
 * Defines a structure that represents a person
 */
class Person {
public:
    std::string name;
    std::string id;
    short int age;
    time_t joinDate;
    Person *prev = nullptr;
    Person *next = nullptr;
    Place *location = nullptr;
    Proxy<Climate> *climates = nullptr;

    /**
     * Person constructor
     *
     * @param name      The name of the person
     * @param id        The id of the person
     * @param age       The age of the person
     * @param joinDate  Date in which the person was registered
     */
    Person(std::string name, std::string id, short int age, time_t joinDate);

    /**
     * Show all the nodes of the struct
     *
     * @return nothing
     */
    void show();

    /**
     * Search a person in the list
     *
     * @param id The element id to search
     */
    Person *search(std::string id);
};
