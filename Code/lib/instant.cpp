#include <instant.hh>
#include <string>

Instant::Instant(std::string name, time_t date, time_t startTime, time_t endTime) {
    this->name = name;
    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;
}

void Instant::append(Instant *node) {
    Instant *curr = this;

    while (curr != nullptr) curr = curr->next;

    curr->next = node;
}
