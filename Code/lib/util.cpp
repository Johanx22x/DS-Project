#include <util.hh>
#include <cstdio>
#include <iostream>
#include <instant.hh>
#include <climate.hh>
#include <place.hh>

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

Place *insert(Place *list, Place *node) {
    if (list == nullptr) return node;

    node->next = list;
    
    Place *curr = list;

    do {
        curr = curr->next;
    } while (curr != list);

    curr->next = node;

    return list;
}

Instant *sortedInsert(Instant *list, Instant* node) {
    if (list == nullptr) return node;

    if (list->date < node->date) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Instant *tmp = list;

    while (node->date > tmp->date) {
        if (tmp->next == nullptr) break;
        tmp = tmp->next;
    }

    // case for when the new node ends up between 2 nodes
    if (tmp->next != nullptr) {
        node->next = tmp->next;
        tmp->next = node;
        node->prev = tmp;
    } else { // this one executes if the new node ends up at the end
        tmp->next = node;
        node->prev = tmp;
    }

    return list;
}

Climate *sortedInsert(Climate *list, Climate *node) {
    if (list == nullptr) return node;

    if (list->date < node->date) {
        node->next = list;
        return node;
    }

    Climate *tmp = list;

    while (node->date > tmp->date) {
        if (tmp->next == nullptr) break;
        tmp = tmp->next;
    }

    if (tmp->next == nullptr) { // this executes when the new node ends up at the end
        tmp->next = node;
    } else {
        node->next = tmp->next;
        tmp->next = node;

    }

    return list;
}
