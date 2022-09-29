#include <cstdio>
#include <rain.hh>
#include <string>

Rain::Rain(std::string name, std::string id, double rainfall) {
    this->name = name;
    this->id = id;
    this->rainfall = rainfall;
}

double Rain::min() {
    Rain *tmp = this;
    double mini = 0;
    while (tmp != nullptr) {
        if (tmp->rainfall < mini) mini = tmp->rainfall;
        tmp = tmp->next;
    }

    return mini;
}

double Rain::max() {
    Rain *tmp = this;
    double maxi = 0;
    while (tmp != nullptr) {
        if (tmp->rainfall > maxi) maxi = tmp->rainfall;
        tmp = tmp->next;
    }

    return maxi;
}

std::string Rain::averageRainfall() {
    double average = 0;
    int nodes = 0;
    Rain *tmp = this;

    double mini = this->min();

    double maxi = this->max();

    for (;tmp != nullptr; tmp = tmp->next) {
        // normalization formula z1 = (x1 - min(x)) / (max(x) - min(x))
        average += (tmp->rainfall - mini) / (maxi - mini);
        nodes++;
    }
    
    average = average / nodes;

    std::string out;

    if (average == 0) {
        out = "extremo seco";
    } else if (average < 0.2) {
        out = "seco";
    } else if (average < 0.4) {
        out = "normal";
    } else if (average < 0.8) {
        out = "lluvioso";
    } else {
        out = "extremo lluvioso";
    }

    return out;
}

void Rain::show() {
    Rain *curr = this;

    while (curr != nullptr) {
        printf("\nRain ID: %s\nRain name: %s\nRain average rainfall: %f\n", curr->id.c_str(), curr->name.c_str(), curr->rainfall);
        curr = curr->next;
    }
}
