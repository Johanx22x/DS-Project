#pragma once

template<typename T>
class Proxy {
public:
    T *link = nullptr;
    Proxy<T> *next = nullptr;

    Proxy(T *value);

    void append(Proxy<T> *node);
};
