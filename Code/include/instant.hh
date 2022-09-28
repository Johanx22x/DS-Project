#pragma once
//#include <bits/types/time_t.h>
#include <string>

/**
 * Defines a structure that represents an instant in time
 */
class Instant {
public:
    std::string name;
    time_t date;
    time_t startTime;
    time_t endTime;
    Instant *prev = nullptr;
    Instant *next = nullptr;

    Instant(std::string name, time_t date, time_t startTime, time_t endTime);

    /**
     * Appends an element to the end of the list
     *
     * @param node The node to be appended
     */
    void append(Instant *node);

    /**
     * Show all the nodes of a list
     *
     * @return nothing
     */
    void show();
};
