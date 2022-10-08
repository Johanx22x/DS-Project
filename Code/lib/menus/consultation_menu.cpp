#include <cstdint>
#include <menu.hh>
#include <program.hh>
#include <string>
#include <util.hh>

extern "C" {
MenuItem *consultationMenu[] = {
    new MenuItem(4, "Display the person with the most registrations",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   Person *maxRegs = ctx->people;
                   Person *tmp = ctx->people;

                   for (; tmp != nullptr; tmp = tmp->next) {
                     if (tmp->climates->size() > maxRegs->climates->size())
                       maxRegs = tmp;
                   }

                   std::cout << maxRegs->str() << "\n";

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

          for (Proxy<Climate> *tmp = found->climate; tmp != nullptr;
               tmp = tmp->next) {
            if (gmtime(&tmp->link->date)->tm_year + 1900 == year) {
              if (maxRr == nullptr)
                maxRr = tmp->link;
              if (tmp->link->rain->average() > maxRr->rain->average()) {
                maxRr = tmp->link;
              }
            }
          }

          if (maxRr == nullptr) {
            fprintf(stderr, "No rains stored for the given year\n");

            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }

          std::cout << maxRr->str() << "\n";

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

          /* free(today); */

          // calculate max startTime
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year &&
                tmp->startTime > max->startTime)
              max = tmp;
          }

          // calculate min startTime
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year &&
                tmp->startTime < min->startTime)
              min = tmp;
          }

          if (max == nullptr || min == nullptr) {
            eprint("Couldn't find anything for the given year\n");
            ctx->consultations->display();
            return CommandCodes::CONTINUE;
          }

          if (max == min) {
            if (max == nullptr) {
              eprint("No max or min!\n");
            }
            std::cout << max->str() << "\n";
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
        // FIXME: In case of a tie print them all
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

          // calculate max endTime
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (max == nullptr)
                max = tmp;
              if (tmp->endTime > max->endTime) {
                max = tmp;
              }
            }
          }

          // calculate min startTime
          for (Instant *tmp = ctx->instants; tmp != nullptr; tmp = tmp->next) {
            if ((gmtime(&tmp->date)->tm_year + 1900) == year) {
              if (min == nullptr)
                min = tmp;
              if (tmp->startTime < min->startTime) {
                min = tmp;
              }
            }
          }

          if (max == min) {
            if (max == nullptr) {
              eprint("Couldn't find anything for the given year\n");
              ctx->consultations->display();
              return CommandCodes::CONTINUE;
            }
            std::cout << "Max sunset and min sunrise times: \n"
                      << max->str() << "\n";
            std::cout << min->str();
          } else {
            std::cout << "\nMax sunset end time: \n"
                      << max->str() << "\n\nMin sunrise start time: \n"
                      << min->str() << "\n\n";
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
