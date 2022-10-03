#include <person.hh>
#include <util.hh>
#include <cstdio>
#include <iostream>
#include <instant.hh>
#include <climate.hh>
#include <place.hh>
#include <region.hh>

/**
 * Reads the first char in stdin
 *
 * @returns int The first char found in the stdin buffer
 */
int getInt() {
    int data = 0;
    std::cin >> data;
    return data;
}

// FIXME: This function produce an error with lower and upper
// TODO: Implement toLower() function to fix this error
Person *sortedInsert(Person *list, Person *node) {
    if (list == nullptr) return node;

    if (list->name >= node->name) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Person *tmp = list;

    while (node->name < tmp->name) {
        if (tmp->next == nullptr) break;
        tmp = tmp->next;
    }

    // case for when the new node ends up between 2 nodes
    if (tmp->next != nullptr) {
        node->next = tmp->next;
        tmp->next->prev = node;
        node->prev = tmp;
        tmp->next = node;
    } else { // this one executes if the new node ends up at the end
        tmp->next = node;
        node->prev = tmp;
    }

    return list;
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
        tmp->prev->next = tmp->next = node;
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

    if (tmp->next != nullptr) { // this executes when the new node ends up at the end
        node->next = tmp->next;
        tmp->next = node;
    } else {

        tmp->next = node;
    }

    return list;
}

Person *deleteNodePerson(Person *list, Person *node) {
    if (list == nullptr) return nullptr; 
    else if (node == nullptr) return list;

    // Check for the first node
    if (list->id == node->id) {
        if (list->next == nullptr) return nullptr;
        list->next->prev = nullptr;
        return list->next;
    }

    Person *curr = list;
    Person *prev;
    while (curr != nullptr) {
        if (curr->id == node->id) {
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    return list;
}

Rain *deleteNodeRain(Rain *list, Rain *node) {
    if (list == nullptr) return nullptr; 
    else if (node == nullptr) return list;

    // Check for the first node
    if (list->id == node->id) {
        return list->next;
    }

    Rain *curr = list;
    Rain *prev;
    while (curr != nullptr) {
        if (curr->id == node->id) {
            prev->next = curr->next;
        }
        prev = curr;
        curr = curr->next;
    }

    return list;
}

Region *deleteNodeRegion(Region *list, Region *node) {
    if (list == nullptr) return nullptr; 
    else if (node == nullptr) return list;

    // Check for the first node
    if (list->id == node->id) {
        return list->next;
    }

    Region *curr = list;
    Region *prev;
    while (curr != nullptr) {
        if (curr->id == node->id) {
            prev->next = curr->next;
        }
        prev = curr;
        curr = curr->next;
    }

    return list;
}
