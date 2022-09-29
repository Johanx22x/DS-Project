#pragma once

#include "place.hh"
#include <climate.hh>
#include <instant.hh>

/**
 * Returns the first character of stdin as an int
 */
[[deprecated("Use std::cin instead")]]
int getInt();

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
 * Inserts an element at the beginning of a list
 *
 * @tparam T The type of the list
 * @param list The list
 * @param node The element to be inserted
 */
template <typename T> 
T *insert(T *list, T *node) {
    if (list == nullptr)
        return nullptr;
    node->next = list;
    return node;
}
