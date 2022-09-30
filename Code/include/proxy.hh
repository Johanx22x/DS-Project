#pragma once

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

    Proxy(T *value);

    /**
     * Appends an element to the end of the list
     *
     * @param node The element to be appended
     */
    void append(Proxy<T> *node);

    void show();
};
