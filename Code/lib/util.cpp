#include <iostream>
/**
 * Inserts an element at the beginning of a list
 *
 * @tparam T The type of the list
 * @param list The list
 * @param node The element to be inserted
 */
#include <cstdio>

template<typename T>
T *insert(const T *list, const T* node) {
    if (list == nullptr) return nullptr;
    node->next = list;
    return node;
}

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
