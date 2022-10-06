#include <algorithm>
#include <cstdio>
#include <ctime>
#include <instant.hh>
#include <sstream>
#include <string>

Instant::Instant(std::string name, time_t date, time_t startTime,
                 time_t endTime) {
  this->name = name;
  this->date = date;
  this->startTime = startTime;
  this->endTime = endTime;
}

std::string Instant::str() {
  std::ostringstream out;
  char endBuf[13];
  char startBuf[13];
  char dateBuf[200];

  tm *datetmp = gmtime(&this->date);
  strftime(dateBuf, sizeof(dateBuf), "%a %b %d %Y", datetmp);

  tm *endtmp = gmtime(&this->endTime);
  strftime(endBuf, sizeof(endBuf), "%H:%M:%S", endtmp);

  tm *starttmp = gmtime(&this->startTime);
  strftime(startBuf, sizeof(startBuf), "%H:%M:%S", starttmp);

  out << "Name: " << this->name << "\nDate: " << dateBuf
      << "\nStart Time: " << startBuf << "\nEnd Time: " << endBuf;
  return out.str();
}

void Instant::show() {
  Instant *curr = this;

  while (curr != nullptr) {
    printf("\n%s\n", curr->str().c_str());
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
    if (curr->name == name)
      return curr;
    curr = curr->next;
  }

  return nullptr;
}
