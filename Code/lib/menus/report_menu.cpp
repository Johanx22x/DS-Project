/**
 * Script to charge the reports MenuItems in the dinamic library
 * Here is defined all the report management and functionality
 *
 * @author Aaron Gonzalez, Johan Rodriguez
 * @version 1.0
 *
 * last modification: 08/10/2022
 */

#include <array>
#include <climate.hh>
#include <command_codes.hh>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iterator>
#include <map>
#include <menu.hh>
#include <place.hh>
#include <program.hh>
#include <queue>
#include <rain.hh>
#include <string>
#include <unordered_map>
#include <util.hh>
#include <vector>

std::string monthName[] = {"January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December"};
extern "C" {

MenuItem *reportItems[] = {
    new MenuItem(
        9,
        "Max and min temperature register of a given year and place per month",
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = localtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          ctx->places->showByName();
          printf("Enter place name: ");
          std::string placeName;
          std::cin.clear();
          std::cin.ignore(INT32_MAX, '\n');
          getline(std::cin, placeName);

          Place *place = ctx->places->find(placeName);

          if (place == nullptr) {
            fprintf(stderr, "Couldn't find a place with that name!\n");
            return CommandCodes::CONTINUE;
          }

          // empty months map container
          std::map<int, double> monthsMinTemp;
          // insert elements in random order
          monthsMinTemp.insert(std::pair<int, double>(1, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(2, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(3, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(4, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(5, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(6, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(7, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(8, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(9, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(10, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(11, 1000.0));
          monthsMinTemp.insert(std::pair<int, double>(12, 1000.0));

          // empty months map container
          std::map<int, double> monthsMaxTemp;
          // insert elements in random order
          monthsMaxTemp.insert(std::pair<int, double>(1, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(2, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(3, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(4, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(5, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(6, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(7, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(8, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(9, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(10, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(11, 0.0));
          monthsMaxTemp.insert(std::pair<int, double>(12, 0.0));

          // calculate max endTime
          for (Climate *tmp = ctx->climates; tmp != nullptr; tmp = tmp->next) {
            tm *date = (localtime(&tmp->date));
            if ((date->tm_year + 1900) == year) {
              if (tmp->place->name == place->name) {
                int month = date->tm_mon;
                double maxTemp = monthsMaxTemp.upper_bound(month)->second;
                double minTemp = monthsMinTemp.upper_bound(month)->second;

                if (tmp->maxTemp > maxTemp) {
                  monthsMaxTemp.upper_bound(month)->second = tmp->maxTemp;
                }
                if (tmp->minTemp < minTemp) {
                  monthsMinTemp.upper_bound(month)->second = tmp->minTemp;
                }
              }
            }
          }

          printf("\nPlace: %s\n", place->name.c_str());
          for (size_t i = 0; i < monthsMaxTemp.size(); i++) {
            double maxTemp = monthsMaxTemp.upper_bound(i)->second;
            double minTemp = monthsMinTemp.upper_bound(i)->second;

            std::string monthstr = monthName[i];

            printf("\u001b[34mMonth: %s\u001b[0m\n", monthstr.c_str());
            printf("Maximum temperature -> %f\n", maxTemp);
            if (minTemp == 1000) {
              printf("Minimum temperature -> %f\n\n", 0.0);
            } else {
              printf("Minimum temperature -> %f\n\n", minTemp);
            }
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        8,
        "Display the amount of rainy days of a given year and place per month",
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = localtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          ctx->places->showByName();
          printf("Enter place name: ");
          std::string placeName;
          std::cin.clear();
          std::cin.ignore(INT32_MAX, '\n');
          getline(std::cin, placeName);

          Place *place = ctx->places->find(placeName);

          if (place == nullptr) {
            fprintf(stderr, "Couldn't find a place with that name!\n");
            return CommandCodes::CONTINUE;
          }

          // empty months map container
          std::map<int, int> rainyDays;
          // insert elements in random order
          rainyDays.insert(std::pair<int, int>(2, 0));
          rainyDays.insert(std::pair<int, int>(3, 0));
          rainyDays.insert(std::pair<int, int>(4, 0));
          rainyDays.insert(std::pair<int, int>(5, 0));
          rainyDays.insert(std::pair<int, int>(6, 0));
          rainyDays.insert(std::pair<int, int>(7, 0));
          rainyDays.insert(std::pair<int, int>(8, 0));
          rainyDays.insert(std::pair<int, int>(9, 0));
          rainyDays.insert(std::pair<int, int>(10, 0));
          rainyDays.insert(std::pair<int, int>(11, 0));
          rainyDays.insert(std::pair<int, int>(12, 0));
          rainyDays.insert(std::pair<int, int>(13, 0));

          for (Climate *tmp = ctx->climates; tmp != nullptr; tmp = tmp->next) {
            tm *date = (localtime(&tmp->date));
            if ((date->tm_year + 1900) == year) {
              if (tmp->place->name == place->name) {
                int month = date->tm_mon + 1;

                if (tmp->itRained) {
                  rainyDays.upper_bound(month)->second++;
                }
              }
            }
          }

          std::string monthName[] = {"January", "February", "March",
                                     "April",   "May",      "June",
                                     "July",    "August",   "September",
                                     "October", "November", "December"};
          printf("\nPlace: %s\n", place->name.c_str());
          for (size_t i = 0; i < rainyDays.size(); i++) {
            int rainMonth = rainyDays.upper_bound(i)->second;

            std::string monthstr = monthName[i];
            printf("\u001b[34mMonth: %s\u001b[0m\n", monthstr.c_str());
            printf("Rain days: %d\n\n", rainMonth);
          }
          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(7, "Show the porcentage of rains of a given region and year",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   // t represents today in milliseconds
                   time_t t = time(nullptr);
                   // today
                   tm *today = localtime(&t);

                   int year = getInt("Type in the year");
                   while (year > (*today).tm_year + 1900) {
                     eprint("Invalid year!");
                     year = getInt("Type in the year");
                   }

                   ctx->places->showByName();
                   printf("Enter place name: ");
                   std::string placeName;
                   std::cin.clear();
                   std::cin.ignore(INT32_MAX, '\n');
                   getline(std::cin, placeName);

                   Place *place = ctx->places->find(placeName);

                   if (place == nullptr) {
                     eprint("Couldn't find a place with that name!");
                     return CommandCodes::CONTINUE;
                   }

                   Proxy<Climate> *tmp = place->climate;

                   std::map<int, std::map<std::string, int>> rains =
                       std::map<int, std::map<std::string, int>>();

                   int totalRains[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                   while (tmp != nullptr) {
                     tm *date = (localtime(&tmp->link->date));

                     if ((date->tm_year + 1900) == year) {
                       rains[date->tm_mon][tmp->link->rain->fmtRainfall()] += 1;
                       totalRains[date->tm_mon] += 1;
                     }

                     tmp = tmp->next;
                   }

                   for (const auto &[month, val] : rains) {
                     std::cout << "\n\u001b[4;34m" << monthName[month] << "\u001b[0m\n";
                     for (const auto &[type, amt] : val) {
                       std::cout << type << ": "
                                 << (amt * 100) / totalRains[month] << "%\n";
                     }
                   }

                   ctx->reports->display();
                   return CommandCodes::CONTINUE;
                 }),
    new MenuItem(
        6, "Print climate periods of a given year",
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = localtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          // 0x84b70 represents seven days from the Unix TimeStamp origin
          const int SEVEN_DAYS = 0x84b70;

          std::string months[] = {"January", "February", "March",
                                  "April",   "May",      "June",
                                  "July",    "August",   "September",
                                  "October", "November", "December"};

          time_t first = 0;
          std::string firstType;

          bool userFeedback = false;

          for (Climate *tmp = ctx->climates; tmp != nullptr; tmp = tmp->next) {
            tm *__tm = localtime(&tmp->date);
            if ((__tm->tm_year + 1900) == year) {
              if (first == 0) {
                first = tmp->date;
                firstType = tmp->rain->fmtRainfall();
              }

              if ((tmp->date - first < SEVEN_DAYS) && (tmp->rain->fmtRainfall() != firstType)) {
                  first = tmp->date;
                  firstType = tmp->rain->fmtRainfall();
              }

              if ((tmp->date - first >= SEVEN_DAYS || tmp->date - first < SEVEN_DAYS) && (tmp->rain->fmtRainfall() == firstType)) {
                  continue;
              }

              if ((tmp->date - first >= SEVEN_DAYS) && (tmp->rain->fmtRainfall() != firstType)) {
                std::cout << "\n\u001b[34mPeriod: " << firstType << "\u001b[0m\n";

                std::cout << "From " << months[localtime(&first)->tm_mon] << " " << localtime(&first)->tm_mday << " to "; 

                std::cout << months[localtime(&tmp->date)->tm_mon] << " " << localtime(&tmp->date)->tm_mday << "\n";

                firstType = tmp->rain->fmtRainfall();
                first = tmp->date;

                userFeedback = true;
              }
            }
          }

          if (!userFeedback) {
            eprint("No time period was found for the given year");
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        5, "Show climate values for a given region within a given time period",
        [](Menu *, Program *ctx) -> CommandCodes {
          int range[2] = {};

          printf("Enter period start year: ");
          std::cin >> range[0];
          flush();

          printf("Enter period end year: ");
          std::cin >> range[1];
          flush();

          ctx->regions->showByNameId();

          printf("Enter region id: ");
          std::string regionId;
          getline(std::cin, regionId);

          Region *region = ctx->regions->search(regionId);

          if (region == nullptr) {
            eprint("Couldn't find a region with that name!");
            ctx->reports->display();
            return CommandCodes::CONTINUE;
          }

          Proxy<Place> *tmp = region->places;

          while (tmp != nullptr) {
            /* if (tmp->link == nullptr) continue; */
            int rainyDays = 0;
            double rainfall = 0;
            double maxTmp = 0;
            double minTmp = 10000;
            bool shouldPrint = false;

            std::cout << tmp->link->name << "\n";

            Proxy<Climate> *cTmp = tmp->link->climate;
            /* if (cTmp->link == nullptr) continue; */

            while (cTmp != nullptr) {
              tm *__tm = localtime(&cTmp->link->date);
              int year = __tm->tm_year + 1900;

              if (year >= range[0] && year <= range[1]) {
                shouldPrint = true;

                if (cTmp->link->itRained) {

                  rainyDays++;

                  rainfall += cTmp->link->rain->rainfall;
                }

                if (cTmp->link->maxTemp > maxTmp)
                  maxTmp = cTmp->link->maxTemp;

                if (cTmp->link->minTemp < minTmp)
                  minTmp = cTmp->link->minTemp;
              }
              cTmp = cTmp->next;
            }

            if (shouldPrint) {
              printf("\nPlace: %s\n\tRainy days: %d\n\tTotal Rainfall: %f\n\tMax "
                     "Temperature: "
                     "%f\n\tMin Temperature: %f\n",
                     tmp->link->name.c_str(), rainyDays, rainfall, maxTmp,
                     minTmp);
            } else {
              printf("\u001b[31mNo data found for %s\u001b[0m!\n",
                     tmp->link->name.c_str());
            }
            tmp = tmp->next;
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        4, "Show monthly average rainfall for each region",
        [](Menu *, Program *ctx) -> CommandCodes {
          printf("Enter year: ");
          int year;
          std::cin >> year;
          flush();

          printf("\n");
          for (Region *tmp = ctx->regions; tmp != nullptr; tmp = tmp->next) {
            double monthlyAvg[12] = {};
            int month = 0;
            while (month < 12) {
                double avg = 0;
                int avgCont = 0;
                Proxy<Place> *places = tmp->places;
                while (places != nullptr) {
                    if (places->link->climate == nullptr) {
                        places = places->next;
                        continue;
                    }
                    Proxy<Climate> *climates = places->link->climate;
                    while (climates != nullptr) {
                        tm *__t = localtime(&climates->link->date);
                        if (__t->tm_year + 1900 == year && __t->tm_mon == month) {
                            avg += climates->link->rain->rainfall;
                            avgCont++;
                          }
                        climates = climates->next;
                    }

                      if (avgCont != 0) {
                          monthlyAvg[month] = avg/avgCont;
                      } else {
                        monthlyAvg[month] = 0;
                      }
                    places = places->next;
                }
                month++;
            }
              printf("\n\u001b[34mRegion: %s\u001b[0m\n", tmp->name.c_str());
                for (int i = 0; i < 12; i++) {
                  if (monthlyAvg[i] != 0)
                  printf("\u001b[33mMonth: %d -> %f\u001b[0m\n", i + 1, monthlyAvg[i]);
                  else 
                  printf("Month: %d -> %f\n", i + 1, monthlyAvg[i]);
                }
        }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        3, "Display average monthly rainfall for all the places within a given year",
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = localtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          Place *tmp = ctx->places;
          do {
              double monthlyAvg[12] = {};
                int month = 0;
                while (month < 12) {
                  double avg = 0;
                  int avgCont = 0;
                  Proxy<Climate> *cTmp = tmp->climate;
                  while (cTmp != nullptr) {
                    tm *__t = localtime(&cTmp->link->date);
                    if (__t->tm_year + 1900 == year && __t->tm_mon == month) {
                        avg += cTmp->link->rain->rainfall;
                        avgCont++;
                      }
                      cTmp = cTmp->next;
                  }

                  if (avgCont != 0) {
                      monthlyAvg[month] = avg/avgCont;
                  } else {
                    monthlyAvg[month] = 0;
                  }

                  month++;
                  }

              printf("\n\u001b[34mPlace: %s\u001b[0m\n", tmp->name.c_str());
                for (int i = 0; i < 12; i++) {
                  if (monthlyAvg[i] != 0)
                  printf("\u001b[33mMonth: %d -> %f\u001b[0m\n", i + 1, monthlyAvg[i]);
                  else 
                  printf("Month: %d -> %f\n", i + 1, monthlyAvg[i]);
                }
              tmp = tmp->next;
          } while (tmp != ctx->places);

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        2, "Print the sunset and sunrise for all the months of a given year",
        [](Menu *, Program *ctx) -> CommandCodes {
          // t represents today in milliseconds
          time_t t = time(nullptr);
          // today
          tm *today = localtime(&t);

          int year = getInt("Type in the year");
          while (year > (*today).tm_year + 1900) {
            eprint("Invalid year!");
            year = getInt("Type in the year");
          }

          std::string months[] = {"January", "February", "March",
                                  "April",   "May",      "June",
                                  "July",    "August",   "September",
                                  "October", "November", "December"};

          for (int i = 1; i <= 12; i++) {
            Instant *tmp = ctx->instants;
            printf("\n\u001b[34mMonth: %s\u001b[0m\n", months[i - 1].c_str());
            while (tmp->next != nullptr) {
              tm *__t = localtime(&tmp->date);
              if (__t->tm_year + 1900 == year) {
                if (__t->tm_mon == i) {
                  tm *date = localtime(&tmp->date);
                  printf("\nDay: %d\n", date->tm_mday);

                  tm *start = localtime(&tmp->startTime);
                  printf("Sunrise: %d:%d:%d\n", start->tm_hour, start->tm_min,
                         start->tm_sec);

                  tm *end = localtime(&tmp->endTime);
                  printf("Sunset: %d:%d:%d\n", end->tm_hour, end->tm_min,
                         end->tm_sec);
                }
              }
              tmp = tmp->next;
            }
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(1, "Display the information of all the lists",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   printf("\n\u001b[4;34mPerson list:\u001b[0m");
                   ctx->people->show();

                   printf("\n\u001b[4;34mRegion list:\u001b[0m");
                   ctx->regions->show();

                   printf("\n\u001b[4;34mPlace list:\u001b[0m");
                   ctx->places->show();

                   printf("\n\u001b[4;34mClimate list:\u001b[0m");
                   ctx->climates->show();

                   printf("\n\u001b[4;34mRain list:\u001b[0m");
                   ctx->rains->show();

                   printf("\n\u001b[4;34mInstant list:\u001b[0m");
                   ctx->instants->show();

                   ctx->reports->display();
                   return CommandCodes::CONTINUE;
                 }),
    new MenuItem(0, "Back", [](Menu *, Program *) -> CommandCodes {
      return CommandCodes::EXIT;
    })};

void DllExport setup(Program *program) {
  for (MenuItem *item : reportItems) {
    program->reports->addItem(item->withContext(program));
  }
}
}
