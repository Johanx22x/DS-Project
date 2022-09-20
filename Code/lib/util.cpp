/**
 * Inserts an element at the beginning of a list
 *
 * @tparam T The type of the list
 * @param list The list
 * @param node The element to be inserted
 */
template<typename T>
T *insert(const T *list, const T* node) {
    if (list == nullptr) return nullptr;
    node->next = list;
    return node;
}

