/**
 * In this header file is defined all the util methods
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 06/10/2022
 */

#pragma once

#include <person.hh>
#include <place.hh>
#include <climate.hh>
#include <instant.hh>
#include <ctime>

/**
 * Sorts and insert a Person node into a Person list
 */
Person *sortedInsert(Person *list, Person *node);

/**
 * Sorts and inserts a Climate node into a Climate list
 */
Climate *sortedInsert(Climate *, Climate *);

/**
 * Sorts and inserts an Instant node into an Instant list
 */
Instant *sortedInsert(Instant *, Instant *);

/**
 * Insert a new element in the places circular list
 *
 * @param list The list
 * @param node The element to be inserted
 */
Place *insert(Place *list, Place *node);

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Person *deleteNode(Person *list, Person *node);

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Rain *deleteNode(Rain *list, Rain *node);

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Region *deleteNode(Region *list, Region *node);

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Place *deleteNode(Place *list, Place *node);

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Instant *deleteNode(Instant *list, Instant *node);

/**
 * Inserts an element at the beginning of a list
 *
 * @tparam T The type of the list
 * @param list The list
 * @param node The element to be inserted
 */
template <typename T> T *insert(T *list, T *node) {
  if (list == nullptr) return nullptr;
  node->next = list;
  return node;
}

/**
 * Delete a given node from the list
 *
 * @param list The list
 * @param node The element to be deleted
 */
Climate *deleteNode(Climate *list, Climate *node);

/**
 * Flush flushes stdin
 */
void flush();

/**
 * Do a safe validation to the user input for integers values
 *
 * @param message The message to display every time that the input fails
 */
int getInt(std::string message);

/**
 * Do a safe validation to the user input for double values
 *
 * @param message The message to display every time that the input fails
 */
double getDouble(std::string message);

/**
 * Display a message as an error
 *
 * @param message The message to display as an error
 */
void eprint(std::string message);

/**
 * Display a message as a valid notification
 *
 * @param message The message to display as a valid notification
 */
void printValid(std::string message);

/**
 * Get the date according to the user input
 *
 * @return time The date the user entered
 */
time_t getDate();

/**
 * Get the time according to the user input
 *
 * @return time The time the user entered
 */
time_t getTime();
