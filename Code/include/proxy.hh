#pragma once
#include <iostream>

/**
 * Defines a structure that works as a middleman for sublist definitions
 *
 * @tparam T The type that this proxy will hold
 */
template<typename T>
class Proxy {
public:
    T *link = nullptr;
    Proxy<T> *next = nullptr;

    Proxy(T *value) {
        this->link = value;
    }

    /**
     * Appends an element to the end of the list
     *
     * @param node The element to be appended
     */
    void append(Proxy<T> *node) {
        Proxy<T> *curr = this;

        while (curr->next != nullptr) curr = curr->next;

        curr->next = node;
    }

    /**
     * Display information about the sub-list
     *
     * @return nothing
     */
    void show() {
        Proxy<T> *curr = this;

        while (curr != nullptr) {
            std::cout << "\n" << curr->link->str();
            curr = curr->next;
        }
    }

    Proxy<T> *deleteNode(Proxy<T> *list, Proxy<T> *node) {
        if (list == nullptr) return nullptr;

        if (list->link == node->link) return list->next;

        Proxy<T> *curr = list;
        Proxy<T> *prev;
        while (curr != nullptr) {
            if (curr->link == node->link) {
                prev->next = curr->next;
                return list;
            }
            prev = curr;
            curr = curr->next;
        }

        return nullptr;
    }
};
