#include <proxy.hh>

template<typename T>
Proxy<T>::Proxy(T *value) {
    this->link = value;
}

template<typename T>
void Proxy<T>::append(Proxy<T> *node) {
    Proxy<T> *curr = this;

    while (curr->next != nullptr) curr = curr->next;

    curr->next = node;
}
