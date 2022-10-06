#include <climits>
#include <cstdint>
#include <ios>
#include <menu.hh>
#include <program.hh>
#include <string>
#include <util.hh>

extern "C" {
// NOTE: dataManagement menu items definition
MenuItem *dataItems[] = {
  new MenuItem(
      15, 
      "Show registered instants",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->places == nullptr) {
          printf("\n\u001b[31mNo elements in the instants list!\u001b[0m\n");
        } else {
          ctx->instants->show();
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      14, 
      "Modify a registered instant",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->instants == nullptr) {
          printf("\n\u001b[31mNo elements to modify in the instants "
                 "list!\u001b[0m\n");
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->instants->showByName();

        printf("\nEnter the name of the instant: ");
        std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, name);

        Instant *toModify = ctx->instants->search(name);
        if (toModify == nullptr) {
          printf("\n\u001b[31mThe instant with name %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 name.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        // TODO: Validate user input (1 or 2)
        int option;
        printf("\n\u001b[34m%s\u001b[0m\n(1) - Modify this place register\n(2) "
               "- Delete this place register\nSelect an option: ",
               toModify->name.c_str());
        std::cin >> option;

        if (option == 2) {
          ctx->instants = deleteNode(ctx->instants, toModify);
        } else if (option == 1) {
          bool modifyFlag = true;
          while (modifyFlag) {
            printf("\n(1) - Modify name\n");
            printf("(2) - Modify date\n");
            printf("(3) - Modify start time\n");
            printf("(4) - Modify end time\n");
            printf("Select an option: ");

            // TODO: Validate user input
            int modifyOption;
            std::cin >> modifyOption;

            // FIXME: Provide a time_t management
            switch (modifyOption) {
            case 1: {
              std::string newName;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              while (true) {
                printf("Enter the new name for the instant: ");
                getline(std::cin, newName);
                if (name == newName) {
                  printf("\u001b[31mThe name is the same as the "
                         "current!\u001b[0m\n");
                  continue;
                } else if (ctx->places->find(newName) != nullptr) {
                  printf("\u001b[31mThe name already exist! Choose another "
                         "name...\u001b[0m\n");
                  continue;
                }
                toModify->name = newName;
                break;
              }
              break;
            }
            case 2: {
              // TODO: Do a validation to date
              int date;
              printf("Enter the new date for the instant: ");
              std::cin >> date;
              toModify->date = date;
              break;
            }
            case 3: {
              // TODO: Do a validation to start time
              int startTime;
              printf("Enter the new start time for the instant: ");
              std::cin >> startTime;
              toModify->startTime = startTime;
              break;
            }
            case 4: {
              // TODO: Do a validation to end time
              int endTime;
              printf("Enter the new end time for the instant: ");
              std::cin >> endTime;
              toModify->endTime = endTime;
              break;
            }
            }

            std::string attributeModify;
            printf("Do you want to modify another information of this instant "
                   "register? [y/n]: ");
            getline(std::cin, attributeModify);
            if (!(attributeModify == "y" || attributeModify == "Y")) {
              break;
            }
          }
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      13, 
      "Add a new instant",
      [](Menu *, Program *ctx) -> CommandCodes {
      std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        while (true) {
          printf("\nEnter a descriptive name for the instant register: ");
          getline(std::cin, name);
          if (ctx->instants == nullptr) {
            break;
          }
          if (ctx->instants->search(name) == nullptr) {
            break;
          }
          printf("\u001b[31mThis instant already exist! Choose another "
                 "name...\u001b[0m\n");
        }

        // TODO: Implement time_t input
        // FIXME: time_t params
        if (ctx->instants == nullptr) {
          ctx->instants = new Instant(name, 1, 1, 1);
        } else {
          ctx->instants = sortedInsert(ctx->instants, new Instant(name, 1, 1, 1));
        }
        printf("\n\u001b[34m%s was added to instant register!\u001b[0m\n",
               name.c_str());
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      12, 
      "Show registered climates",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->climates == nullptr) {
          printf("\n\u001b[31mNo elements in the climates list!\u001b[0m\n");
        } else {
          ctx->climates->show();
        }

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      11, 
      "Modify a registered climate",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->climates == nullptr) {
          printf("\n\u001b[31mNo elements to modify in the climates "
                 "list!\u001b[0m\n");
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->climates->showById();

        printf("\nEnter the ID of the climate: ");
        std::string id;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, id);

        Climate *toModify = ctx->climates->search(id);
        if (toModify == nullptr) {
          printf("\n\u001b[31mThe climate with the id %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 id.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        // TODO: Validate user input (1 or 2)
        int option;
        printf(
            "\n\u001b[34m%s\u001b[0m\n(1) - Modify this climate register\n(2) "
            "- Delete this climate register\nSelect an option: ",
            toModify->id.c_str());
        std::cin >> option;

        if (option == 2) {
          Place *foundPlace = ctx->places->find(toModify->place->name);
          Person *foundPerson = ctx->people->search(toModify->person->id);
          foundPlace->climate = foundPlace->climate->deleteNode(
              foundPlace->climate, new Proxy(toModify));
          foundPerson->climates = foundPerson->climates->deleteNode(
              foundPerson->climates, new Proxy(toModify));
          ctx->rains = deleteNode(ctx->rains, toModify->rain);
          ctx->climates = deleteNode(ctx->climates, toModify);
        } else if (option == 1) {
          bool modifyFlag = true;
          while (modifyFlag) {
            printf("\n(1) - Modify id\n");
            printf("(2) - Modify the precipitation\n");
            printf("(3) - Modify the max temperature\n");
            printf("(4) - Modify min temperature\n");
            printf("(5) - Modify the wind speed\n");
            printf("(6) - Modify the the humidity\n");
            printf("(7) - Modify the wind direction\n");
            printf("(8) - Modify the rained state (yes or no)\n");
            printf("(9) - Modify the date\n");
            printf("(10) - Modify the start time\n");
            printf("(11) - Modify the end time\n");
            printf("(12) - Modify the associate rain register\n");
            printf("Select an option: ");

            // TODO: Validate user input
            int modifyOption;
            std::cin >> modifyOption;

            switch (modifyOption) {
            case 1: {
              std::string newId;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              while (true) {
                printf("Enter the new id for the climate register: ");
                getline(std::cin, newId);
                if (id == newId) {
                  printf("\u001b[31mThe ID is the same as the "
                         "current!\u001b[0m\n");
                  continue;
                } else if (ctx->rains->search(newId) != nullptr) {
                  printf("\u001b[31mThe ID already exist! Choose another "
                         "ID...\u001b[0m\n");
                  continue;
                }
                toModify->id = newId;
                break;
              }
              break;
            }
            case 12: {
              Rain *rainToModify = toModify->rain;

              bool modifyFlag = true;
              while (modifyFlag) {
                printf("\n(1) - Modify id\n");
                printf("(2) - Modify name\n");
                printf("(3) - Modify rainfall value\n");
                printf("Select an option: ");

                // TODO: Validate user input
                int modifyOption;
                std::cin >> modifyOption;

                switch (modifyOption) {
                case 1: {
                  std::string newId;
                  // Flush buffer
                  std::cin.clear();
                  std::cin.ignore(INT32_MAX, '\n');
                  while (true) {
                    printf("Enter the new id for the rain register: ");
                    getline(std::cin, newId);
                    if (id == newId) {
                      printf("\u001b[31mThe ID is the same as the "
                             "current!\u001b[0m\n");
                      continue;
                    } else if (ctx->rains->search(newId) != nullptr) {
                      printf("\u001b[31mThe ID already exist! Choose another "
                             "ID...\u001b[0m\n");
                      continue;
                    }
                    rainToModify->id = newId;
                    break;
                  }
                  break;
                }
                case 2: {
                  printf("Enter the new name for the rain register: ");
                  std::string newName;
                  // Flush buffer
                  std::cin.clear();
                  std::cin.ignore(INT32_MAX, '\n');
                  getline(std::cin, newName);
                  rainToModify->name = newName;
                  break;
                }
                case 3: {
                  printf(
                      "Enter the new rainfall value for the rain register: ");
                  // TODO: validate user input
                  double newRainfall;
                  std::cin >> newRainfall;
                  rainToModify->rainfall = newRainfall;
                  break;
                }
                }
                std::string attributeModify;
                printf("Do you want to modify another information of this rain "
                       "register? [y/n]: ");
                // Flush buffer
                std::cin.clear();
                std::cin.ignore(INT32_MAX, '\n');
                getline(std::cin, attributeModify);
                if (!(attributeModify == "y" || attributeModify == "Y")) {
                  break;
                }
              }
              break;
            }
            }
            std::string attributeModify;
            printf("Do you want to modify another information of this climate "
                   "register? [y/n]: ");
            getline(std::cin, attributeModify);
            if (!(attributeModify == "y" || attributeModify == "Y")) {
              break;
            }
          }
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      10, 
      "Add a new climate to the register",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->people == nullptr) {
          printf("\u001b[31mThere isn't a person to associate this new "
                 "climate!\u001b[0m\n");
          return CommandCodes::CONTINUE;
        }
        if (ctx->places == nullptr) {
          printf("\u001b[31mThere isn't a place to associate this new "
                 "climate!\u001b[0m\n");
          return CommandCodes::CONTINUE;
        }

        ctx->people->showByNameId();
        printf("\nEnter the ID of the person making the registration: ");
        std::string personId;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, personId);

        Person *foundPerson = ctx->people->search(personId);
        if (foundPerson == nullptr) {
          printf("\n\u001b[31mThe person with the ID %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 personId.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->places->showByName();
        printf("\nEnter the name of the place where the climate will be "
               "registered: ");
        std::string placeName;
        getline(std::cin, placeName);

        Place *foundPlace = ctx->places->find(placeName);
        if (foundPlace == nullptr) {
          printf("\n\u001b[31mThe place with the name %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 placeName.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        // TODO: implement function body (user input for climate)

        // TODO: Implement time_t input
        // FIXME: time_t params

        std::string climateId;
        while (true) {
          printf("\nEnter an ID for the climate: ");
          getline(std::cin, climateId);
          if (ctx->climates == nullptr) {
            break;
          }
          if (ctx->climates->search(climateId) == nullptr) {
            break;
          }
          printf("\u001b[31mThis ID already exist! Choose another "
                 "id...\u001b[0m\n");
        }

        // NOTE: Add the rain of the climate
        printf("\nEnter a descriptive name for the rain: ");
        std::string rainName;
        getline(std::cin, rainName);

        std::string id;
        while (true) {
          printf("Enter the id of the rain: ");
          getline(std::cin, id);
          if (ctx->rains == nullptr) {
            break;
          }
          if (ctx->rains->search(id) == nullptr) {
            break;
          }
          printf("\u001b[31mThis ID already exist! Choose another "
                 "id...\u001b[0m\n");
        }

        // TODO: Do a validation to rainfall
        printf("Enter the average mm rainfall value of the rain: ");
        double rainfall = 0.0;
        std::cin >> rainfall;

        Rain *newRain = new Rain(rainName, id, rainfall);
        if (ctx->rains == nullptr) {
          ctx->rains = newRain;
        } else {
          ctx->rains = insert(ctx->rains, newRain);
        }

        Climate *newClimate =
            new Climate(climateId, 3.2, 1.0, 2.1, 4.9, 1.8, 'N', false, 8, 9,
                        10, newRain, foundPlace, foundPerson);
        if (ctx->climates == nullptr) {
          ctx->climates = newClimate;
        } else {
          ctx->climates->append(newClimate);
        }

        if (foundPerson->climates == nullptr) {
          foundPerson->climates = new Proxy(newClimate);
        } else {
          foundPerson->climates->append(new Proxy(newClimate));
        }

        if (foundPlace->climate == nullptr) {
          foundPlace->climate = new Proxy(newClimate);
        } else {
          foundPlace->climate->append(new Proxy(newClimate));
        }

        printf("\n\u001b[34mThe data was added to the person %s!\u001b[0m\n",
               foundPerson->name.c_str());
        printf("\n\u001b[34mThe data was added to the place %s!\u001b[0m\n",
               foundPlace->name.c_str());

        printf(
            "\n\u001b[34mThe data was added to climate register!\u001b[0m\n");
        printf("\n\u001b[34mAdded a new rain register called: %s\u001b[0m\n",
               rainName.c_str());

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      9, 
      "Show registered places",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->places == nullptr) {
          printf("\n\u001b[31mNo elements in the places list!\u001b[0m\n");
        } else {
          ctx->places->show();
        }

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      8, 
      "Modify a registered place",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->places == nullptr) {
          printf("\n\u001b[31mNo elements to modify in the places "
                 "list!\u001b[0m\n");
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->places->showByName();

        printf("\nEnter the name of the place: ");
        std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, name);

        Place *toModify = ctx->places->find(name);
        if (toModify == nullptr) {
          printf("\n\u001b[31mThe place with name %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 name.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        // TODO: Validate user input (1 or 2)
        int option;
        printf("\n\u001b[34m%s\u001b[0m\n(1) - Modify this place register\n(2) "
               "- Delete this place register\nSelect an option: ",
               toModify->name.c_str());
        std::cin >> option;

        if (option == 2) {
          ctx->places = deleteNode(ctx->places, toModify);
        } else if (option == 1) {
          bool modifyFlag = true;
          while (modifyFlag) {
            printf("\n(1) - Modify name\n");
            printf("(2) - Modify population\n");
            printf("(3) - Modify area\n");
            printf("Select an option: ");

            // TODO: Validate user input
            int modifyOption;
            std::cin >> modifyOption;

            switch (modifyOption) {
            case 1: {
              std::string newName;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              while (true) {
                printf("Enter the new name for the place: ");
                getline(std::cin, newName);
                if (name == newName) {
                  printf("\u001b[31mThe name is the same as the "
                         "current!\u001b[0m\n");
                  continue;
                } else if (ctx->places->find(newName) != nullptr) {
                  printf("\u001b[31mThe name already exist! Choose another "
                         "name...\u001b[0m\n");
                  continue;
                }
                toModify->name = newName;
                break;
              }
              break;
            }
            case 2: {
              // TODO: Do a validation to population
              int population;
              printf("Enter the new population value for the place: ");
              std::cin >> population;
              toModify->population = population;
              break;
            }
            case 3: {
              // TODO: Do a validation to area
              double area;
              printf("Enter the new area for the region register: ");
              std::cin >> area;
              toModify->area = area;
              break;
            }
            }

            std::string attributeModify;
            printf("Do you want to modify another information of this place? "
                   "[y/n]: ");
            getline(std::cin, attributeModify);
            if (!(attributeModify == "y" || attributeModify == "Y")) {
              break;
            }
          }
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      7, 
      "Add a new place", 
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->regions == nullptr) {
          printf("\n\u001b[31mThere is no region to which to relate this new "
                 "place!\u001b[0m\n\n");
          return CommandCodes::CONTINUE;
        }

        ctx->regions->showByNameId();

        std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        printf(
            "\nEnter the id of the region to which whis new place belongs: ");
        std::string regionId;
        getline(std::cin, regionId);
        Region *foundRegion = ctx->regions->search(regionId);
        if (foundRegion == nullptr) {
          printf("\n\u001b[31mRegion with the id %s not found!\u001b[0m\n",
                 regionId.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        while (true) {
          printf("\nEnter the name of the place: ");
          getline(std::cin, name);
          if (ctx->places == nullptr) {
            break;
          }
          if (ctx->places->find(name) == nullptr) {
            break;
          }
          printf("\u001b[31mThis place already exist! Choose another place or "
                 "try to add the distric in the name...\u001b[0m\n");
        }

        // TODO: Do a validation to population
        int population;
        printf("Enter the population of the place: ");
        std::cin >> population;

        // TODO: Do a validation to area
        double area;
        printf("Enter the area of the place: ");
        std::cin >> area;

        Place *newPlace = new Place(name, population, area, foundRegion);
        if (ctx->places == nullptr) {
          ctx->places = newPlace;
        } else {
          ctx->places = insert(ctx->places, newPlace);
        }

        if (foundRegion->places == nullptr) {
          foundRegion->places = new Proxy(newPlace);
        } else {
          foundRegion->places->append(new Proxy<Place>(newPlace));
        }

        printf("\n\u001b[34m%s was added to places!\u001b[0m\n", name.c_str());
        printf("\n\u001b[34mPlace %s successfully related to region "
               "%s!\u001b[0m\n",
               newPlace->name.c_str(), foundRegion->name.c_str());
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      6, 
      "Show registered regions",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->regions == nullptr) {
          printf("\n\u001b[31mNo elements in the region list!\u001b[0m\n");
        } else {
          ctx->regions->show();
        }

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      5, 
      "Modify a registered region",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->regions == nullptr) {
          printf("\n\u001b[31mNo elements to modify in the region "
                 "list!\u001b[0m\n");
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->regions->showByNameId();

        printf("\nEnter the ID of the region: ");
        std::string id;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, id);

        Region *toModify = ctx->regions->search(id);
        if (toModify == nullptr) {
          printf("\n\u001b[31mThe region with id %s doesn't exist in the "
                 "register!\n\u001b[0m",
                 id.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        // TODO: Validate user input (1 or 2)
        printf(
            "\n\u001b[34m%s - %s\u001b[0m\n(1) - Modify this region "
            "register\n(2) - Delete this region register\n",
            toModify->name.c_str(), toModify->id.c_str());
        int option = validateInt("Select an option");
        while (option < 1 || option > 2) {
            printf("Invalid option!");
            option = validateInt("Select an option");
        }

        if (option == 2) {
          ctx->regions = deleteNode(ctx->regions, toModify);
        } else if (option == 1) {
          bool modifyFlag = true;
          while (modifyFlag) {
            printf("\n(0) - Cancel\n");
            printf("(1) - Modify id\n");
            printf("(2) - Modify name\n");
            printf("(3) - Modify location\n");
            int modifyOption = validateInt("Select an option");

            switch (modifyOption) {
            case 1: {
              std::string newId;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              while (true) {
                printf("Enter the new id for the region register: ");
                getline(std::cin, newId);
                if (id == newId) {
                  printf("\u001b[31mThe ID is the same as the "
                         "current!\u001b[0m\n");
                  continue;
                } else if (ctx->regions->search(newId) != nullptr) {
                  printf("\u001b[31mThe ID already exist! Choose another "
                         "ID...\u001b[0m\n");
                  continue;
                }
                toModify->id = newId;
                break;
              }
              break;
            }
            case 2: {
              printf("Enter the new name for the region register: ");
              std::string newName;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              getline(std::cin, newName);
              toModify->name = newName;
              break;
            }
            case 3: {
              printf("Enter the new location for the region register: ");
              std::string newLocation;
              // Flush buffer
              std::cin.clear();
              std::cin.ignore(INT32_MAX, '\n');
              getline(std::cin, newLocation);
              toModify->location = newLocation;
              break;
            }
            default:
              break;
            }

            std::string attributeModify;
            printf("Do you want to modify another information of this region? "
                   "[y/n]: ");
            getline(std::cin, attributeModify);
            if (!(attributeModify == "y" || attributeModify == "Y")) {
              break;
            }
          }
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      4, 
      "Add a new region", 
      [](Menu *, Program *ctx) -> CommandCodes {
        printf("\nEnter the name of the region: ");
        std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, name);

        std::string id;
        while (true) {
          printf("Enter the ID of the region: ");
          getline(std::cin, id);
          if (ctx->regions == nullptr) {
            break;
          }
          if (ctx->regions->search(id) == nullptr) {
            break;
          }
          printf("\u001b[31mThis ID already exist! Choose another "
                 "id...\u001b[0m\n");
        }

        std::string location;
        printf("Enter the location of the region: ");
        getline(std::cin, location);

        if (ctx->regions == nullptr) {
          ctx->regions = new Region(name, id, location);
        } else {
          ctx->regions = insert(ctx->regions, new Region(name, id, location));
        }
        printf("\n\u001b[34m%s was added to regions!\u001b[0m\n", name.c_str());

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      3, 
      "Show registered persons",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->people == nullptr) {
          printf("\n\u001b[31mNo elements in the person list!\u001b[0m\n");
        } else {
          ctx->people->show();
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      2, 
      "Modify a registered person",
      [](Menu *, Program *ctx) -> CommandCodes {
        if (ctx->people == nullptr) {
          printf("\n\u001b[31mNo elements to modify in the person "
                 "list!\u001b[0m\n");
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        ctx->people->showByNameId();

        printf("\nEnter the ID of the person: ");
        std::string id;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, id);

        Person *toModify = ctx->people->search(id);
        if (toModify == nullptr) {
          printf("\n\u001b[31mThe person with the id %s doesn't exist in the register!\n\u001b[0m", id.c_str());
          ctx->dataManagement->display();
          return CommandCodes::CONTINUE;
        }

        printf("\n\u001b[34m%s - %s\u001b[0m\n", toModify->name.c_str(), toModify->id.c_str());
        printf("(0) - Cancel\n");
        printf("(1) - Modify this person\n");
        printf("(2) - Delete this person\n");

        int option = validateInt("Select an option");
        while (option < 0 || option > 2) {
            printErr("Invalid option!");
            option = validateInt("Select an option");
        }

        if (option == 0) {
            ctx->dataManagement->display();
            return CommandCodes::CONTINUE;
        } 
        if (option == 2) {
            std::string attributeModify;
            printf("Are you sure you want do delete \u001b[34m%s %s\u001b[0m? [y/n]: ", toModify->name.c_str(), toModify->id.c_str());
            // Flush buffer
            std::cin.clear();
            std::cin.ignore(INT32_MAX, '\n');
            getline(std::cin, attributeModify);
            if (attributeModify == "y" || attributeModify == "Y") {
                ctx->people = deleteNode(ctx->people, toModify);
                ctx->dataManagement->display();
                printf("\u001b[34m%s was removed from the registry!\u001b[0m\n", toModify->name.c_str());
                ctx->dataManagement->display();
                return CommandCodes::CONTINUE;
            }
            printf("\u001b[31m%s was not removed from the registry!\u001b[0m\n", toModify->name.c_str());
            ctx->dataManagement->display();
            return CommandCodes::CONTINUE;
        }
        bool modifyFlag = true;
        while (modifyFlag) {
            printf("\n(0) - Cancel\n");
            printf("(1) - Modify id\n");
            printf("(2) - Modify name\n");
            printf("(3) - Modify age\n");
            printf("(4) - Modify location\n");

            int modifyOption = validateInt("Select an option");
            while (modifyOption < 0 || modifyOption > 4) {
                printErr("Invalid option!");
                modifyOption = validateInt("Select an option");
            }

            switch (modifyOption) {
                case 0: {
                            ctx->dataManagement->display();
                            return CommandCodes::CONTINUE;
                        }
                case 1: {
                            std::string newId;
                            // Flush buffer
                            std::cin.clear();
                            std::cin.ignore(INT32_MAX, '\n');
                            while (true) {
                                printf("Enter the new id for the person: ");
                                getline(std::cin, newId);
                                if (id == newId) {
                                    printf("\u001b[31mThe ID is the same as the "
                                            "current!\u001b[0m\n");
                                    continue;
                                } else if (ctx->people->search(newId) != nullptr) {
                                    printf("\u001b[31mThe ID already exist! Choose another "
                                            "ID...\u001b[0m\n");
                                    continue;
                                }
                                toModify->id = newId;

                                printValid("Person's ID changed");

                                break;
                            }
                            break;
                        }
                case 2: {
                            printf("Enter the new person's name: ");
                            std::string newName;
                            // Flush buffer
                            std::cin.clear();
                            std::cin.ignore(INT32_MAX, '\n');
                            getline(std::cin, newName);
                            toModify->name = newName;

                            printValid("Person's name changed");

                            break;
                        }
                case 3: {
                            short int newAge = validateInt("Enter the new person's age");
                            while (newAge < 12 || newAge > 125) {
                                printf("\u001b[31mThe person's age must be an integer value between 12 and 125!\u001b[0m\n");
                                newAge = validateInt("Enter the person's age");
                            }
                            toModify->age = newAge;

                            printValid("Person's age changed!");

                            break;
                        }
                case 4: {
                            printf("Enter the new location for the person: ");
                            std::string newLocation;
                            // Flush buffer
                            std::cin.clear();
                            std::cin.ignore(INT32_MAX, '\n');
                            getline(std::cin, newLocation);
                            toModify->name = newLocation;

                            printValid("Person's location changed!");

                            break;
                        }
                default:
                        printErr("Invalid input!");
                        break;
            }

            std::string attributeModify;
            printf("Do you want to modify another information of this person? [y/n]: ");
            getline(std::cin, attributeModify);
            if (!(attributeModify == "y" || attributeModify == "Y")) {
                break;
            }
        }
        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
  new MenuItem(
      1, 
      "Add a new person", 
      [](Menu *, Program *ctx) -> CommandCodes {
        printf("\n");

        printf("Enter the name of the person: ");
        std::string name;
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, name);

        std::string id;
        while (true) {
          printf("Enter the id of the person: ");
          getline(std::cin, id);
          if (ctx->people == nullptr) {
            break;
          }
          if (ctx->people->search(id) == nullptr) {
            break;
          }
          printf("\u001b[31mThis ID already exist! Choose another "
                 "id...\u001b[0m\n");
        }

        short int age = validateInt("Enter the person's age");
        while (age < 12 || age > 125) {
            printf("\u001b[31mThe person's age must be an integer value between 12 and 125!\u001b[0m\n");
            age = validateInt("Enter the person's age");
        }

        std::string location;
        printf("Enter the location of the person: ");
        // Flush buffer
        std::cin.clear();
        std::cin.ignore(INT32_MAX, '\n');
        getline(std::cin, location);

        // TODO: Implement join date based on user input
        time_t joinDate;
        time(&joinDate);

        if (ctx->people == nullptr) {
          ctx->people = new Person(name, id, age, location, joinDate);
        } else {
          ctx->people = sortedInsert(ctx->people,
                                new Person(name, id, age, location, joinDate));
        }
        printf("\n\u001b[34m%s joined at %s\u001b[0m", name.c_str(),
               asctime(gmtime(&joinDate)));

        ctx->dataManagement->display();
        return CommandCodes::CONTINUE;
      }),
      new MenuItem(
        0, 
        "Back", 
        [](Menu *, Program *) -> CommandCodes {
        return CommandCodes::EXIT;
      })
};

void DllExport setup(Program *program) {
  for (MenuItem *item : dataItems) {
    program->dataManagement->addItem(item->withContext(program));
  }
}
}
