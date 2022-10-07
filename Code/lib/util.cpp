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

void flush() {
  char __c;
  while ((__c = getchar() != '\n' && __c != EOF))
    ;
}

// FIXME: This function produces an error sorting alphabetical
Person *sortedInsert(Person *list, Person *node) {
    if (list == nullptr) return node;
    if (node == nullptr) return list;

    if (list->name.at(0) >= node->name.at(0)) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Person *tmp = list;

    while (node->name.at(0) >= tmp->name.at(0)) {
        if (tmp->next == nullptr) {
            break;
        }
        tmp = tmp->next;
    }

    std::cout << tmp->name << " es menor que " << node->name << "\n";

    if (tmp->next == nullptr) {
        tmp->next = node;
        node->prev = tmp;
        return list;
    } else { // case for when the new node ends up between 2 nodes
        node->next = tmp->next;
        tmp->next->prev = node;
        node->prev = tmp;
        tmp->next = node;
        return list;
    }
}

Place *insert(Place *list, Place *node) {
  if (list == nullptr)
    return node;

  node->next = list;

  Place *curr = list;

  do {
    curr = curr->next;
  } while (curr != list);

  curr->next = node;

  return list;
}

Instant *sortedInsert(Instant *list, Instant* node) {
    if (list == nullptr) return node;
    if (node == nullptr) return list;

    if (list->date < node->date) {
        node->next = list;
        list->prev = node;
        return node;
    }

    Instant *tmp = list;

    while (node->date > tmp->date) {
        if (tmp->next == nullptr) break;
        tmp = tmp->next;
    }

    // case for when the new node ends up between 2 nodes
    if (tmp->next != nullptr) {
        node->next = tmp->next;
        tmp->next->prev = node;
        node->prev = tmp;
        tmp->next = node;
    } else { // this one executes if the new node ends up at the end
        tmp->next = node;
        node->prev = tmp;
    }

    return list;
}

Climate *sortedInsert(Climate *list, Climate *node) {
  if (list == nullptr)
    return node;

  if (list->date < node->date) {
    node->next = list;
    return node;
  }

  Climate *tmp = list;

  while (node->date > tmp->date) {
    if (tmp->next == nullptr)
      break;
    tmp = tmp->next;
  }

  if (tmp->next !=
      nullptr) { // this executes when the new node ends up at the end
    node->next = tmp->next;
    tmp->next = node;
  } else {

    tmp->next = node;
  }

  return list;
}

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

void eprint(std::string message) {
    printf("\u001b[31m%s\u001b[0m\n", message.c_str());
}

void printValid(std::string message) {
    printf("\u001b[34m%s\u001b[0m\n", message.c_str());
}

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
    while (minutes < 1 || minutes > 59) {
        eprint("Invalid input, must be a number between 1 and 59!");
        minutes = getInt("Enter the minutes");
    }
    newTime->tm_min = minutes;

    // Set the seconds to 0
    newTime->tm_sec = 0;

    time_t time = mktime(newTime);
    return time;
}
