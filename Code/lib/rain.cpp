/**
 * Here is implemented all the methods from the rain header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 01/10/2022
 */

#include <cstdio>
#include <rain.hh>
#include <string>

/// See the documentation declared in the rain header file
Rain::Rain(std::string name, std::string id, double rainfall) {
  this->name = name;
  this->id = id;
  this->rainfall = rainfall;
}

double Rain::min() {
  Rain *tmp = this;
  double mini = 0;
  while (tmp != nullptr) {
    if (tmp->rainfall < mini)
      mini = tmp->rainfall;
    tmp = tmp->next;
  }

  return mini;
}

/// See the documentation declared in the rain header file
double Rain::max() {
  Rain *tmp = this;
  double maxi = 0;
  while (tmp != nullptr) {
    if (tmp->rainfall > maxi)
      maxi = tmp->rainfall;
    tmp = tmp->next;
  }

  return maxi;
}

/// See the documentation declared in the rain header file
double Rain::average() {
  double average = 0;
  int nodes = 0;

  double mini = this->min();

  double maxi = this->max();

  // 1
  for (Rain *tmp = this; tmp != nullptr; tmp = tmp->next) {
    // normalization formula z1 = (x1 - min(x)) / (max(x) - min(x))

    // WARNING: possibly unsafe calculation, although I'm not sure, this a math
    // formula after all
    average += (tmp->rainfall - mini) / (maxi - mini);
    nodes++;
  }

  average = average / nodes;

  return average;
}

/// See the documentation declared in the rain header file
std::string Rain::fmtAverage() {
  double avg = average();

  std::string out;

  if (avg == 0) {
    out = "extremo seco";
  } else if (avg < 0.2) {
    out = "seco";
  } else if (avg < 0.4) {
    out = "normal";
  } else if (avg < 0.8) {
    out = "lluvioso";
  } else {
    out = "extremo lluvioso";
  }

  return out;
}

std::string Rain::fmtRainfall() {
  // TODO: define a better function for this
  std::string out;
  if (this->rainfall == 0) {
    out = "extremo seco";
  } else if (this->rainfall < 2) {
    out = "seco";
  } else if (this->rainfall < 4) {
    out = "normal";
  } else if (this->rainfall < 6) {
    out = "lluvioso";
  } else {
    out = "extremo lluvioso";
  }

  return out;
}

/// See the documentation declared in the rain header file
void Rain::show() {
  Rain *curr = this;

  while (curr != nullptr) {
    printf("\nRain ID: %s\nRain name: %s\nRain average rainfall: %f\n",
           curr->id.c_str(), curr->name.c_str(), curr->rainfall);
    curr = curr->next;
  }
}

/// See the documentation declared in the rain header file
void Rain::showByNameId() {
  Rain *curr = this;

  while (curr != nullptr) {
    printf("\nRain ID: %s\nRain name: %s\n", curr->id.c_str(),
           curr->name.c_str());
    curr = curr->next;
  }
}

/// See the documentation declared in the rain header file
Rain *Rain::search(std::string id) {
  Rain *curr = this;

  while (curr != nullptr) {
    if (curr->id == id)
      return curr;
    curr = curr->next;
  }

  return nullptr;
}
