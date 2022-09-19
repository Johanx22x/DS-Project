#pragma once
#include <bits/types/time_t.h>
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

    Person(std::string name, std::string id, short int age, time_t joinDate);

    /** 
     * Appends an element to the end of the list
     * 
     * @param *node The element to be appended
     */
    void append(Person *node);
};
