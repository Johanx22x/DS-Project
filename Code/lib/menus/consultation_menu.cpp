/**
 * Script to charge the consultations MenuItems in the dinamic library
 * Here is defined all the consultations management and functionality
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 07/10/2022
 */

#include "command_codes.hh"
#include "instant.hh"
#include <cstdint>
#include <ctime>
#include <menu.hh>
#include <program.hh>
#include <string>
#include <util.hh>

extern "C" {
MenuItem *consultationMenu[] = {
    new MenuItem(4, "Display the person with the most registrations",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   Person *maxRegs = ctx->people;

                   for (Person *tmp = ctx->people; tmp != nullptr;
                        tmp = tmp->next) {
                     if (tmp->climates == nullptr)
                       continue;
                     if (tmp->climates->size() > maxRegs->climates->size())
                       maxRegs = tmp;
                   }

                   std::cout << "\n"
                             << maxRegs->str() << "Total registrations: "
                             << maxRegs->climates->size() << "\n";

                   ctx->consultations->display();
                   return CommandCodes::CONTINUE;
                 }),
    new MenuItem(
        3,
        "Show the month with the most extreme rains of a given year and place",
        // NOTE: Print both, extremely rainy and extremely dry
        // NOTE: In case of tie print all the months with the max tie
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = gmtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          ctx->places->showByName();

          printf("Enter the name of the place: ");
          std::string name;
          std::cin.clear();
          std::cin.ignore(INT32_MAX, '\n');
          getline(std::cin, name);

          Place *found = ctx->places->find(name);

          if (found == nullptr) {
            printf("Can't find that place\n");

            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }

          // here maxRr is initialized as a null pointer becaus we also need to
          // validate the year, since this function asks the user for a year and
          // a place
          Climate *maxRr = nullptr;

          Proxy<Climate> *tmp = found->climate;

          if (tmp == nullptr) {
            printf("No rain data stored in %s for the year %d\n",
                   found->name.c_str(), year);

            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }

          //     month amount
          int maxDryMonths[12] = {
              -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
          };
          int maxRainyMonths[12] = {
              -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
          };

          while (tmp->next != nullptr) {
            Climate *tmpClt = tmp->link;
            tm *__t = gmtime(&tmpClt->date);
            if ((__t->tm_year + 1900) == year) {
              if (maxRr == nullptr) {
                maxRr = tmpClt;
              }

              std::cout << tmpClt->str() << "\n";

              if (tmpClt->itRained &&
                  tmpClt->rain->fmtRainfall().compare("extremo lluvioso")) {
                int __curr = maxRainyMonths[__t->tm_mon];
                maxRainyMonths[__t->tm_mon] = __curr + 1;
              } else if (!tmpClt->itRained) {
                // TODO: finish this
                int __curr = maxDryMonths[__t->tm_mon];
                maxDryMonths[__t->tm_mon] = __curr + 1;
              }
              // Here is all the data of the given year and place
            }

            tmp = tmp->next;
          }

          int maxDryMonth = -1;
          int maxRainyMonth = -1;

          for (int mon = 0; mon < 12; mon++) {
            if (maxDryMonths[mon] > maxDryMonth)
              maxDryMonth = mon;
            if (maxRainyMonths[mon] > maxRainyMonth)
              maxRainyMonth = mon;
          }

          char *monthNames[12] = {"Enero",   "Febrero",   "Marzo",
                                  "Abril",   "Mayo",      "Junio",
                                  "Julio",   "Agosto",    "Septiembre",
                                  "Octubre", "Noviembre", "Diciembre"};

          if (maxRr == nullptr) {
            fprintf(stderr, "No rains stored for the given year\n");

            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }

          if (maxRainyMonth > -1)
            printf("%s estuvo en extremo lluvioso\n",
                   monthNames[maxRainyMonth]);
          if (maxDryMonth > -1)
            printf("%s estuvo en extremo seco\n", monthNames[maxDryMonth]);

          ctx->consultations->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        2, "Display earliest and latest sunrise for a given year",
        // NOTE: In case of a tie print only one
        [](Menu *, Program *ctx) -> CommandCodes {
          Instant *max = nullptr;
          Instant *min = nullptr;

          // t represents today in milliseconds
          time_t t = time(nullptr);

          // today holds an instance of tm, its only use if to hold the current
          // year kind of a waste of resources, but who cares, we're in 2022 not
          // in the 80's ram is one of the cheapest and most affordable
          // resources
          //
          // today
          tm *today = gmtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          // calculate max sunset
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (min == nullptr) {
                min = tmp;
              }
              if (tmp->startTime >= min->startTime) {
                min = tmp;
              }
            }
          }

          // calculate min sunset
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (max == nullptr) {
                max = tmp;
              }
              if (tmp->startTime <= max->startTime) {
                max = tmp;
              }
            }
          }

          if (max == nullptr || min == nullptr) {
            fprintf(stderr, "Couldn't find anything for the given year\n");
            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }
          if (max == min) {
            std::cout << "\nMax and Min start time (tie): \n"
                      << max->str() << "\n";
          } else {
            std::cout << "\nMax start time: \n"
                      << max->str() << "\n\nMin start time: \n"
                      << min->str() << "\n";
          }

          ctx->consultations->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        1, "Show earliest sunrise and latest sunset within a given year",
        [](Menu *, Program *ctx) -> CommandCodes {
          Instant *max = nullptr;
          Instant *min = nullptr;

          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = gmtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          // calculate min sunrise
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (min == nullptr) {
                min = tmp;
              }
              if (tmp->endTime > min->endTime) {
                min = tmp;
              }
            }
          }

          // calculate max sunset
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (max == nullptr) {
                max = tmp;
              }
              if (tmp->startTime < max->startTime) {
                max = tmp;
              }
            }
          }

          if (max == nullptr || min == nullptr) {
            /* fprintf(stderr, "Couldn't find anything for the given year\n");
             */
            eprint("Couldn't find anything for the given year");
            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }
          if (max == min) {
            std::cout << "\nMax sunset and min sunrise times (tie): \n"
                      << max->str() << "\n";
          } else {
            std::cout << "\nMax sunset end time: \n"
                      << max->str() << "\n\nMin sunrise start time: \n"
                      << min->str() << "\n";
          }

          ctx->consultations->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(0, "Back", [](Menu *, Program *) -> CommandCodes {
      return CommandCodes::EXIT;
    })};

void DllExport setup(Program *program) {
  for (MenuItem *item : consultationMenu) {
    program->consultations->addItem(item->withContext(program));
  }
}
}
