/**
 * In this header file is defined all the Proxy template class behavior and
 * parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 22/09/2022
 */

#pragma once
#include <iostream>

/**
 * Defines a structure that works as a middleman for sublist definitions
 *
 * @tparam T The type that this proxy will hold
 */
template <typename T> class Proxy {
public:
  T *link = nullptr;
  Proxy<T> *next = nullptr;

  Proxy(T *value) { this->link = value; }

  /**
   * Appends an element to the end of the list
   *
   * @param node The element to be appended
   */
  void append(Proxy<T> *node) {
    Proxy<T> *curr = this;

    while (curr->next != nullptr)
      curr = curr->next;

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
      std::cout << "\n" << curr->link->tstr() << "\n";
      curr = curr->next;
    }
  }

  /**
   * Delete a  node from the proxy class instance
   *
   * @param list* The current Proxy list instance
   * @param node* The element to delete
   * Return Proxy<T> * The new list without @node*
   */
  Proxy<T> *deleteNode(Proxy<T> *list, Proxy<T> *node) {
    if (list == nullptr)
      return nullptr;

    if (list->link == node->link)
      return list->next;

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

  // TODO: make a better size calculation method that doesn't have to traverse
  // The entire list each time we want to get its size
  // NOTE: about the comment above, there's really no way of doing this without
  // storing the size of the entire list somewhere
  std::size_t size() {
    size_t _siz = 0;
    for (Proxy<T> *tmp = this; tmp != nullptr; tmp = tmp->next)
      _siz++;
    return _siz;
  }
};
