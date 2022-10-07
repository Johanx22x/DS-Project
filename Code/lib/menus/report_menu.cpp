#include <climate.hh>
#include <command_codes.hh>
#include <cstdint>
#include <cstdio>
#include <map>
#include <menu.hh>
#include <place.hh>
#include <program.hh>
#include <rain.hh>
#include <stack>
#include <string>
#include <unordered_map>
#include <util.hh>
#include <vector>

struct Period {
  time_t start = 0;
  time_t end = 0;
  std::string average;
};
static double paverage(Proxy<Rain> *);
static std::string fmtAverage(Proxy<Rain> *);

extern "C" {

// TODO: Implement all the 9 items of reports
MenuItem *reportItems[] = {
    new MenuItem(9, "Max and min temperature register of a given year and place per month",
            [](Menu *, Program *ctx) -> CommandCodes {
            // t represents today in milliseconds
            time_t t = time(nullptr);
            // today
            tm *today = gmtime(&t);

            int year = getInt("Type in the year");
            while (year > (*today).tm_year+1900) {
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
            monthsMinTemp.insert(std::pair<int, double>(13, 1000.0));

            // empty months map container
            std::map<int, double> monthsMaxTemp;
            // insert elements in random order
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
            monthsMaxTemp.insert(std::pair<int, double>(13, 0.0));

            // calculate max endTime
            for (Climate *tmp = ctx->climates; tmp != nullptr; tmp = tmp->next) {
                tm *date = (gmtime(&tmp->date));
                if ((date->tm_year + 1900) == year) {
                    if (tmp->place->name == place->name) {
                        int month = date->tm_mon + 1;
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

            for (unsigned long int i = 1; i <= monthsMaxTemp.size(); i++) {
                double maxTemp = monthsMaxTemp.upper_bound(i)->second;
                double minTemp = monthsMinTemp.upper_bound(i)->second;

                std::string monthstr;
                switch (i) {
                    case 1:
                        monthstr = "January";
                        break;
                    case 2:
                        monthstr = "February";
                        break;
                    case 3:
                        monthstr = "March";
                        break;
                    case 4:
                        monthstr = "April";
                        break;
                    case 5:
                        monthstr = "May";
                        break;
                    case 6:
                        monthstr = "June";
                        break;
                    case 7:
                        monthstr = "July";
                        break;
                    case 8:
                        monthstr = "August";
                        break;
                    case 9:
                        monthstr = "September";
                        break;
                    case 10:
                        monthstr = "October";
                        break;
                    case 11:
                        monthstr = "November";
                        break;
                    case 12:
                        monthstr = "December";
                        break;
                    default:
                        monthstr = "Not set";
                        break;
                }

                printf("Place: %s\nMonth: %s\n", place->name.c_str(), monthstr.c_str());
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
    new MenuItem(8, "Display the amount of rainy days of a given year and place per month",
                 [](Menu *, Program *ctx) -> CommandCodes {
                 // t represents today in milliseconds
                 time_t t = time(nullptr);
                 // today
                 tm *today = gmtime(&t);

                 int year = getInt("Type in the year");
                 while (year > (*today).tm_year+1900) {
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
                     tm *date = (gmtime(&tmp->date));
                     if ((date->tm_year + 1900) == year) {
                         if (tmp->place->name == place->name) {
                             int month = date->tm_mon + 1;

                             if (tmp->itRained) {
                                 rainyDays.upper_bound(month)->second++;
                             }
                         }
                     }
                 }

                 for (unsigned long int i = 1; i <= rainyDays.size(); i++) {
                     int rainMonth = rainyDays.upper_bound(i)->second;

                     std::string monthstr;
                     switch (i) {
                         case 1:
                             monthstr = "January";
                             break;
                         case 2:
                             monthstr = "February";
                             break;
                         case 3:
                             monthstr = "March";
                             break;
                         case 4:
                             monthstr = "April";
                             break;
                         case 5:
                             monthstr = "May";
                             break;
                         case 6:
                             monthstr = "June";
                             break;
                         case 7:
                             monthstr = "July";
                             break;
                         case 8:
                             monthstr = "August";
                             break;
                         case 9:
                             monthstr = "September";
                             break;
                         case 10:
                             monthstr = "October";
                             break;
                         case 11:
                             monthstr = "November";
                             break;
                         case 12:
                             monthstr = "December";
                             break;
                         default:
                             monthstr = "Not set";
                             break;
                     }

                     printf("Place: %s\nMonth: %s\n", place->name.c_str(), monthstr.c_str());
                     printf("Rain days: %d\n\n", rainMonth);
                 }
                   ctx->reports->display();
                   return CommandCodes::CONTINUE;
                 }),
    new MenuItem(
        7, "Not yet implemented!",
        [](Menu *, Program *ctx) -> CommandCodes {
          // TODO: implement function body
          printf("Enter the year: ");
          int year;
          std::cin >> year;
          flush();

          ctx->places->showByName();
          printf("Enter the place name: ");
          std::string placeName;
          getline(std::cin, placeName);
          Place *place = ctx->places->find(placeName);

          std::unordered_map<int, std::unordered_map<std::string, int>> months =
              std::unordered_map<int, std::unordered_map<std::string, int>>();

          for (Proxy<Climate> *tmp = place->climate; tmp != nullptr;
               tmp = tmp->next) {
            std::unordered_map<std::string, int> tt =
                std::unordered_map<std::string, int>();
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(6, "Print non equal climate periods",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   // TODO: implement function body

                   printf("Enter the year: ");
                   int year;
                   std::cin >> year;
                   flush();

                   printf("0");
                   std::vector<Period> periods = std::vector<Period>();

                   std::stack<std::string> avgs = std::stack<std::string>();

                   for (Climate *tmp = ctx->climates; tmp != nullptr;
                        tmp = tmp->next) {
                     tm *__tm = gmtime(&tmp->date);
                     if (__tm->tm_year + 1900 == year) {
                       // TODO: 💀💀💀💀💀

                       /* // WARNING: possible segfault due to uninitialized
                        * memory */
                       /* Period *currP = periods.at(currentPeriod); */
                       /* if (currP == nullptr) { */
                       /*   fprintf(stderr, "No periods registered"); */
                       /*   continue; */
                       /* } */

                       /* if (periods.at(currentPeriod) */
                       /*         ->average.compare(tmp->rain->fmtAverage()) !=
                        * 0) { */
                       /*   currentPeriod++; */
                       /* } */
                       /* if (currP->start > tmp->date) { */
                       /*   currP->start = tmp->date; */
                       /* } else if (currP->end < tmp->date) { */
                       /*   currP->end = tmp->date; */
                       /* } */

                       /* periods[currentPeriod] = currP; */
                     }
                   }
                   /* for (const Period *period : periods) { */
                   /*   printf("%s from %s to %s\n", period->average.c_str(), */
                   /*          asctime(gmtime(&period->start)), */
                   /*          asctime(gmtime(&period->end))); */
                   /* } */

                   ctx->reports->display();
                   return CommandCodes::CONTINUE;
                 }),
    new MenuItem(
        5, "Show climate values for a given region within a given time period",
        [](Menu *, Program *ctx) -> CommandCodes {
          // TODO: implement function body
          int range[2] = {};

          printf("Enter perdiod start year: ");
          std::cin >> range[0];
          flush();

          printf("Enter period end year: ");
          std::cin >> range[1];
          flush();

          ctx->regions->showByNameId();

          printf("Enter region id: ");
          std::string regionId;
          getline(std::cin, regionId);
          flush();

          printf("DEBUG: Region ID: %s\n", regionId.c_str());

          Region *region = ctx->regions->search(regionId);

          if (region == nullptr) {
            fprintf(stderr, "Couldn't find a region with that name!\n");
            return CommandCodes::CONTINUE;
          }

          for (Proxy<Place> *tmp = region->places; tmp != nullptr;
               tmp = tmp->next) {
            int rainyDays = 0;
            double rainfall = 0;
            double maxTmp = 0;
            double minTmp = 0;

            bool shouldPrint = false;
            for (Climate *cTmp = tmp->link->climate->link; cTmp != nullptr;
                 cTmp = cTmp->next) {

              tm *__tm = gmtime(&cTmp->date);
              int year = __tm->tm_year + 1900;

              if (year >= range[0] && year <= range[1]) {
                shouldPrint = true;

                if (cTmp->itRained) {

                  rainyDays++;

                  for (Rain *rTmp = cTmp->rain; rTmp != nullptr;
                       rTmp = rTmp->next) {

                    printf("DEBUG: sumando rainfall\n");
                    rainfall += rTmp->rainfall;
                  }
                }

                if (cTmp->maxTemp > maxTmp)
                  maxTmp = cTmp->maxTemp;

                if (cTmp->minTemp < minTmp)
                  minTmp = cTmp->minTemp;
              }
            }

            if (shouldPrint) {
              printf("Place: %s\n\tTotal Rainfall: %f\n\tMax Temperature: "
                     "%f\n\tMin Temperature: %f\n",
                     tmp->link->name.c_str(), rainfall, maxTmp, minTmp);
            } else {
              fprintf(stderr, "No data found for that date range!\n");
              return CommandCodes::CONTINUE;
            }
          }

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        4, "Show monthly average rainfall for each region",
        [](Menu *, Program *ctx) -> CommandCodes {
          // TODO: implement function body
          printf("Enter year: ");
          int year;
          std::cin >> year;

          flush();
          int monthlyAvg[12] = {};
          // \/ shame
          for (Region *tmp = ctx->regions; tmp != nullptr; tmp = tmp->next) {
            for (int month = 0; month < 12; month++) {
              for (Proxy<Climate> *cTmp = tmp->places->link->climate;

                   cTmp != nullptr; cTmp = cTmp->next) {
                tm *__t = gmtime(&cTmp->link->date);
                if (__t->tm_year + 1900 == year && __t->tm_mon == month) {
                  // NOTE: dear future self, do not fret, this does work as
                  // NOTE: expected what you thought would happen doesn't happen
                  // at NOTE: all, although you'll need those p* static
                  // functions defined NOTE: at the bottom of this file for
                  // other stuff
                  monthlyAvg[month] = cTmp->link->rain->average();
                }
              }
            }
          }

          for (const auto &d : monthlyAvg)
            printf("%d ", d);
          printf("\n");

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        3, "Display average monthly rainfall within a given year",
        [](Menu *, Program *ctx) -> CommandCodes {
          // TODO: implement function body
          printf("Enter year: ");
          int year;
          std::cin >> year;

          flush();

          Place *place = ctx->places;

          Place *tmp = place;
          do {
            if (gmtime(&tmp->climate->link->date)->tm_year + 1900 == year) {
              tmp->show();
              std::cout << tmp->climate->link->rain->fmtAverage() << "\n";
            }
            tmp = tmp->next;
          } while (tmp != place);
          /* for (Place *tmp = place; tmp != nullptr;) { */
          /* } */

          ctx->reports->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(2, "Not yet implemented!",
                 [](Menu *, Program *ctx) -> CommandCodes {
                   // TODO: implement function body
                   for (Instant *tmp = ctx->instants; tmp != nullptr;
                        tmp = tmp->next) {
                     // TODO: bribe johan into writing this function 💀💀💀💀
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

static double pmin(Proxy<Rain> *list) {
  Proxy<Rain> *tmp = list;
  double mini = 0;
  while (tmp != nullptr) {
    if (tmp->link->rainfall < mini)
      mini = tmp->link->rainfall;
    tmp = tmp->next;
  }

  return mini;
}

static double pmax(Proxy<Rain> *list) {
  Proxy<Rain> *tmp = list;
  double maxi = 0;
  while (tmp != nullptr) {
    if (tmp->link->rainfall > maxi)
      maxi = tmp->link->rainfall;
    tmp = tmp->next;
  }

  return maxi;
}

static double paverage(Proxy<Rain> *list) {
  double average = 0;
  int nodes = 0;

  double mini = pmin(list);

  double maxi = pmax(list);

  // 1
  for (Proxy<Rain> *tmp = list; tmp != nullptr; tmp = tmp->next) {
    // normalization formula z1 = (x1 - min(x)) / (max(x) - min(x))

    // WARNING: possibly unsafe calculation, although I'm not sure, this a math
    // formula after all
    average += (tmp->link->rainfall - mini) / (maxi - mini);
    nodes++;
  }

  average = average / nodes;

  return average;
}

static std::string fmtAverage(Proxy<Rain> *list) {
  double avg = paverage(list);

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
