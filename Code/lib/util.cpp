/**
 * Here is implemented all the methods from the util header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 07/10/2022
 */

#include <cctype>
#include <climate.hh>
#include <climits>
#include <clocale>
#include <ctime>
#include <person.hh>
#include <util.hh>
#include <cstdio>
#include <instant.hh>
#include <iostream>
#include <person.hh>
#include <place.hh>
#include <region.hh>
#include <util.hh>
#include <map>

/// Flush the std::cin buffer
void flush() {
  char __c; 
  while ((__c = getchar() != '\n' && __c != EOF)) ;
}

/// See the documentation defined in the header file
Person *sortedInsert(Person *list, Person *node) {
    if (list == nullptr) return nullptr;
    if (node == nullptr) return list;

    if (node->name < list->name) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Person *curr = list;
    Person *prev;

    while (curr != nullptr) {
        if (node->name <= curr->name) {
            if (prev->next == nullptr) {
                prev->next = node;
                node->prev = curr;
            } else {
                node->next = prev->next;
                node->prev = prev;
                curr->prev = node;
                prev->next = node;
            }
            return list;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = node;
    node->prev = prev;

    return list;
}

/// See the documentation defined in the header file
Place *insert(Place *list, Place *node) {
  if (list == nullptr) return node;
  if (node == nullptr) return list;

  node->next = list;

  Place *curr = list;

  do {
    curr = curr->next;
  } while (curr->next != list);

  curr->next = node;

  return node;
}

/// See the documentation defined in the header file
Climate *sortedInsert(Climate *list, Climate *node) {
    if (list == nullptr) return nullptr;
    if (node == nullptr) return list;

    if (node->date < list->date) {
        node->next = list;
        return node;
    }

    Climate *curr = list;
    Climate *prev;

    while (curr != nullptr) {
        if (node->date <= curr->date) {
            if (prev->next == nullptr) {
                prev->next = node;
            } else {
                node->next = prev->next;
                prev->next = node;
            }
            return list;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = node;

    return list;
}

/// See the documentation defined in the header file
Instant *sortedInsert(Instant *list, Instant* node) {
    if (list == nullptr) return nullptr;
    if (node == nullptr) return list;

    if (node->date < list->date) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Instant *curr = list;
    Instant *prev;

    while (curr != nullptr) {
        if (node->date <= curr->date) {
            if (prev->next == nullptr) {
                prev->next = node;
                node->prev = curr;
            } else {
                node->next = prev->next;
                node->prev = prev;
                curr->prev = node;
                prev->next = node;
            }
            return list;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = node;
    node->prev = prev;

    return list;
}

/// See the documentation defined in the header file
Person *deleteNode(Person *list, Person *node) {
    if (list == nullptr) return nullptr;
    else if (node == nullptr) return list;

    // Check for the first node
    if (list->id == node->id) {
        if (list->next == nullptr) return nullptr;
        list->next->prev = nullptr;
        return list->next;
    }

    Person *curr = list;
    Person *prev = nullptr;
    while (curr != nullptr) {
        if (curr->id == node->id && curr->next == nullptr) {
            prev->next = curr->next;
        } else if (curr->id == node->id) {
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    return list;
}

/// See the documentation defined in the header file
Rain *deleteNode(Rain *list, Rain *node) {
  if (list == nullptr)
    return nullptr;
  else if (node == nullptr)
    return list;

  // Check for the first node
  if (list->id == node->id) {
    return list->next;
  }

  Rain *curr = list;
  Rain *prev;
  while (curr != nullptr) {
    if (curr->id == node->id) {
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  }

  return list;
}

/// See the documentation defined in the header file
Region *deleteNode(Region *list, Region *node) {
  if (list == nullptr)
    return nullptr;
  else if (node == nullptr)
    return list;

  // Check for the first node
  if (list->id == node->id) {
    return list->next;
  }

  Region *curr = list;
  Region *prev;
  while (curr != nullptr) {
    if (curr->id == node->id) {
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  }

  return list;
}

/// See the documentation defined in the header file
Place *deleteNode(Place *list, Place *node) {
  if (list == nullptr)
    return nullptr;
  else if (node == nullptr)
    return list;

  // Check for the first node
  if (list->name == node->name) {
    if (list->next == list) {
      return nullptr;
    } else {
      return list->next;
    }
  }

  Place *curr = list;
  Place *prev;
  do {
    if (curr->name == node->name) {
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  } while (curr != list);

  return list;
}

/// See the documentation defined in the header file
Instant *deleteNode(Instant *list, Instant *node) {
    if (list == nullptr) return nullptr;
    else if (node == nullptr) return list;

    // Check for the first node
    if (list->name == node->name) {
        if (list->next == nullptr) return nullptr;
        list->next->prev = nullptr;
        return list->next;
    }

    Instant *curr = list;
    Instant *prev;
    while (curr != nullptr) {
        if (curr->name == node->name && curr->next == nullptr) {
            prev->next = curr->next;
        } else if (curr->name == node->name) {
            prev->next = curr->next;
            curr->next->prev = prev;
        }
        prev = curr;
        curr = curr->next;
    }

    return list;
}

/// See the documentation defined in the header file
Climate *deleteNode(Climate *list, Climate *node) {
  if (list == nullptr)
    return nullptr;
  else if (node == nullptr)
    return list;

  // Check for the first node
  if (list->id == node->id) {
    return list->next;
  }

  Climate *curr = list;
  Climate *prev;
  while (curr != nullptr) {
    if (curr->id == node->id) {
      prev->next = curr->next;
    }
    prev = curr;
    curr = curr->next;
  }

  return list;
}

/// See the documentation defined in the header file
double getDouble(std::string message) {
    double input;
    bool valid = false;

    while (!valid) { // repeat as long as the input is not valid
        printf("%s: ", message.c_str());
        std::cin >> input;

        if (std::cin.fail()) {
            printf("\u001b[31mIt isn't a double!\u001b[0m\n");
            // clear error flags
            std::cin.clear(); 
            // Wrong input remains on the stream, so you need to get rid of it
            std::cin.ignore(INT_MAX, '\n');
        } else {
            valid = true;
        }
    }
    return input;
}

/// See the documentation defined in the header file
int getInt(std::string message) {
    int input;
    bool valid = false;

    while (!valid) { // repeat as long as the input is not valid
        printf("%s: ", message.c_str());
        std::cin >> input;

        if (std::cin.fail()) {
            printf("\u001b[31mIt isn't an integer!\u001b[0m\n");
            // clear error flags
            std::cin.clear(); 
            // Wrong input remains on the stream, so you need to get rid of it
            std::cin.ignore(INT_MAX, '\n');
        } else {
            valid = true;
        }
    }
    return input;
}

/// See the documentation defined in the header file
void eprint(std::string message) {
    printf("\u001b[31m%s\u001b[0m\n", message.c_str());
}

/// See the documentation defined in the header file
void printValid(std::string message) {
    printf("\u001b[34m%s\u001b[0m\n", message.c_str());
}

/// See the documentation defined in the header file
time_t getDate() {
    time_t now = time(0);
    tm *newTime = localtime(&now);

    int year = getInt("Enter the year");
    while (year-1900 > newTime->tm_year) {
        eprint("Invalid year!");
        year = getInt("Enter the year");
    }

    newTime->tm_year = year-1900;

    int month = getInt("Enter the month");
    while (month < 1 || month > 12) {
        eprint("Invalid month!");
        month = getInt("Enter the month");
    }

    newTime->tm_mon = month-1;

    // empty months map container
    std::map<int, int> months;
    // insert elements in random order
    months.insert(std::pair<int, int>(2, 31));
    months.insert(std::pair<int, int>(3, 28));
    months.insert(std::pair<int, int>(4, 31));
    months.insert(std::pair<int, int>(5, 30));
    months.insert(std::pair<int, int>(6, 31));
    months.insert(std::pair<int, int>(7, 30));
    months.insert(std::pair<int, int>(8, 31));
    months.insert(std::pair<int, int>(9, 31));
    months.insert(std::pair<int, int>(10, 30));
    months.insert(std::pair<int, int>(11, 31));
    months.insert(std::pair<int, int>(12, 30));
    months.insert(std::pair<int, int>(13, 31));

    int daysNumber = months.upper_bound(month)->second;
    printf("\u001b[34mThis month has only %d days!\u001b[0m\n", daysNumber);
    int day = getInt("Enter the day");

    while (day < 1 || day > daysNumber) {
        printf("\u001b[31mThis month has only %d days!\u001b[0m\n", daysNumber);
        day = getInt("Enter the day");
    }
    
    newTime->tm_mday = day;

    time_t time = mktime(newTime);
    return time;
}

/// See the documentation defined in the header file
time_t getTime() {
    time_t now = time(0);
    tm *newTime = localtime(&now);

    int hours = getInt("Enter the hour");
    while (hours < 0 || hours > 23) {
        eprint("Invalid input, must be a number between 1 and 23!");
        hours = getInt("Enter the hour");
    }

    newTime->tm_hour = hours - 6;

    int minutes = getInt("Enter the minutes");
    while (minutes < 0 || minutes > 59) {
        eprint("Invalid input, must be a number between 1 and 59!");
        minutes = getInt("Enter the minutes");
    }
    newTime->tm_min = minutes;

    // Set the seconds to 0
    newTime->tm_sec = 0;

    time_t time = mktime(newTime);
    return time;
}
