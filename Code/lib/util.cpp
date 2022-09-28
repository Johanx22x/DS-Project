#include <util.hh>
#include <cstdio>
#include <iostream>
#include <instant.hh>
#include <climate.hh>

/**
 * Reads the first char in stdin
 *
 * @returns int The first char found in the stdin buffer
 */
[[deprecated("Use std::cin instead")]]
int getInt() {
    int data = 0;
    std::cin >> data;
    return data;
}

// TEST: Check if this function works
Instant *sortedInsert(Instant *list, Instant* node) {
    if (list == nullptr) return node;

    Instant *curr = list;
    while (curr->date <= node->date || curr != nullptr) curr = curr->next;

    node->prev = curr->prev;
    curr->prev->next = node;
    node->next = curr;
    curr->prev = node;

    return list;
}

// TEST: Check if this function works
Climate *sortedInsert(Climate *list, Climate *node) {
    if (list == nullptr) return node;

    Climate *curr = list;
    Climate *prev = nullptr;
    while (curr->date <= node->date || curr != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = node;
    node-> next = curr;

    return list;
}
