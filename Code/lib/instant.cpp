/**
 * Here is implemented the Instant class parameters and method
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.2
 *
 * last modification: 07/10/2022
 */

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <instant.hh>
#include <sstream>
#include <string>

/**
 * Instant constructor
 */
Instant::Instant(std::string name, time_t date, time_t startTime,
                 time_t endTime) {
  this->name = name;
  this->date = date;
  this->startTime = startTime;
  this->endTime = endTime;
}

/// See the documentation declared in the header file
std::string Instant::str() {
  std::ostringstream out;
  char endBuf[13];
  char startBuf[13];
  char dateBuf[200];

  tm *datetmp = localtime(&this->date);
  strftime(dateBuf, sizeof(dateBuf), "%a %b %d %Y", datetmp);

  tm *endtmp = localtime(&this->endTime);
  strftime(endBuf, sizeof(endBuf), "%H:%M:%S", endtmp);

  tm *starttmp = localtime(&this->startTime);
  strftime(startBuf, sizeof(startBuf), "%H:%M:%S", starttmp);

  out << "Name: " << this->name << "\nDate: " << dateBuf
      << "\nStart Time: " << startBuf << "\nEnd Time: " << endBuf;
  return out.str();
}

/// See the documentation declared in the header file
void Instant::show() {
  Instant *curr = this;

  while (curr != nullptr) {
    printf("\n%s\n", curr->str().c_str());
    curr = curr->next;
  }
}

/// See the documentation declared in the header file
void Instant::showByName() {
  Instant *curr = this;

  while (curr != nullptr) {
    printf("\nInstant name: %s", curr->name.c_str());
    curr = curr->next;
  }
}

/// See the documentation declared in the header file
Instant *Instant::search(std::string name) {
  Instant *curr = this;

  while (curr != nullptr) {
    if (curr->name == name)
      return curr;
    curr = curr->next;
  }

  return nullptr;
}
