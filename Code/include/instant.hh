#pragma once
#include <bits/types/time_t.h>
#include <string>

class Instant {
public:
    std::string name;
    time_t date;
    time_t startTime;
    time_t endTime;
    Instant *prev = nullptr;
    Instant *next = nullptr;

    Instant(std::string name, time_t date, time_t startTime, time_t endTime);

    void append(Instant *node);
};
