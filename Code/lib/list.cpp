
class LinkedList {
public:
    int value;
    LinkedList *next = nullptr;

    LinkedList(int value) {
        this->value = value;
    }

    void print();
};
