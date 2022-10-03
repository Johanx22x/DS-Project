#include <cstdio>
#include <ctime>
#include <instant.hh>
#include <string>

Instant::Instant(std::string name, time_t date, time_t startTime, time_t endTime) {
    this->name = name;
    this->date = date;
    this->startTime = startTime;
    this->endTime = endTime;
}

void Instant::show() {
    Instant *curr = this;

    while (curr != nullptr) {
        // TODO: Implement start and end time
        printf("\nInstant name: %s\nInstant date: %s", curr->name.c_str(), asctime(gmtime(&curr->date)));
        curr = curr->next;
    }
}

void Instant::showByName() {
    Instant *curr = this;

    while (curr != nullptr) {
        printf("\nInstant name: %s", curr->name.c_str());
        curr = curr->next;
    }
}

Instant *Instant::search(std::string name) {
    Instant *curr = this;
    
    while (curr != nullptr) {
        if (curr->name == name) return curr;
        curr = curr->next;
    }

    return nullptr;
}
