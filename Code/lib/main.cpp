#include <proxy.hh>
/* #include <bits/types/time_t.h> */
#include <climate.hh>
#include <place.hh>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <command_codes.hh>
#include <menu.hh>
#include <person.hh>
#include <rain.hh>
#include <region.hh>
#include <string>
#include <util.hh>
#include <instant.hh>
#include <string>

using std::string;

Person *people = new Person("Johan Rodriguez", "2022141892", 18, 1531721412);
Region *regions = new Region("San Carlos", "5", "Alajuela, Costa Rica");
Place *places = new Place("Santa Clara", 500, 1250.3, regions);
// FIXME: time_t params for new Instant
Instant *instants = new Instant("A beautiful day", 0, 0, 0);
// FIXME: time_t params for new climate
Rain *rains = new Rain("Storm", "1", 0.2);
Climate *climates = new Climate("1", 2.3, 4.1, 8.2, 0.4, 31.8, 'N', true, 0, 1, 2, rains, places, people);

int main() {
    // NOTE: Load data
    regions->places = new Proxy(places);
    people->climates = new Proxy(climates);
    places->climate = new Proxy(climates);

    // NOTE: Main menu definition
    Menu *menu = new Menu("Main Menu");

    // NOTE: Sub-menus definition
    Menu *dataManagement = new Menu("Data Management Menu");
    Menu *consultations = new Menu("Consultations Menu");
    Menu *reports = new Menu("Reports Menu");

    // NOTE: reports menu items definition
    // TODO: Implement all the 9 items of reports
    reports->addItem( new MenuItem(9, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(8, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(7, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(6, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(5, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(4, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(3, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(2, "Not yet implemented!",
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(1, "Display the information of all the lists", 
                [](Menu *reports, Menu *) -> CommandCodes {
                    // TODO: Print detailed information for every node, including sub-lists
                    printf("\n\u001b[4;34mPerson list:\u001b[0m");
                    people->show();
                    printf("\n\u001b[4;34mRegion list:\u001b[0m");
                    regions->show();
                    printf("\n\u001b[4;34mPlace list:\u001b[0m");
                    places->show();
                    printf("\n\u001b[4;34mClimate list:\u001b[0m");
                    climates->show();
                    printf("\n\u001b[4;34mRain list:\u001b[0m");
                    rains->show();
                    printf("\n\u001b[4;34mInstant list:\u001b[0m");
                    instants->show();
                    reports->display();
                    return CommandCodes::CONTINUE;
                }));
    reports->addItem( new MenuItem(0, "Back", 
                [](Menu *, Menu *) -> CommandCodes {
                    return CommandCodes::EXIT;
                }));

    // NOTE: consultations menu items definition
    consultations->addItem( new MenuItem(4, "Display the person with more registers", 
                [](Menu *consultations, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    consultations->display();
                    return CommandCodes::CONTINUE;
                }));
    consultations->addItem( new MenuItem(3, "Show the month with more extreme rain registers of a given year and place", 
                // NOTE: Print both, extremely rainy and extremely dry
                // NOTE: In case of tie print all the months with the max tie
                [](Menu *consultations, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    consultations->display();
                    return CommandCodes::CONTINUE;
                }));
    consultations->addItem( new MenuItem(2, "Display the dates with more minutes difference in sunrise", 
                // NOTE: In case of a tie print only one
                [](Menu *consultations, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    consultations->display();
                    return CommandCodes::CONTINUE;
                }));
    consultations->addItem( new MenuItem(1, "Earliest sunrise and latest occultation time of the sun of a given year", 
                // NOTE: In case of a tie print them all
                [](Menu *consultations, Menu *) -> CommandCodes {
                    // TODO: implement function body
                    consultations->display();
                    return CommandCodes::CONTINUE;
                }));
    consultations->addItem( new MenuItem(0, "Back", 
                [](Menu *, Menu *) -> CommandCodes {
                    return CommandCodes::EXIT;
                }));
    
    // NOTE: dataManagement menu items definition
    dataManagement->addItem(new MenuItem(15, "Show registered instants",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (places == nullptr) {
                        printf("\n\u001b[31mNo elements in the instants list!\u001b[0m\n");
                    } else {
                        instants->show();
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(14, "Modify a registered instant",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (instants == nullptr) {
                        printf("\n\u001b[31mNo elements to modify in the instants list!\u001b[0m\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 

                    instants->showByName();

                    printf("\nEnter the name of the instant: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    Instant *toModify = instants->search(name);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe instant with name %s doesn't exist in the register!\n\u001b[0m", name.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: Validate user input (1 or 2)
                    int option;
                    printf("\n\u001b[34m%s\u001b[0m\n(1) - Modify this place register\n(2) - Delete this place register\nSelect an option: ", toModify->name.c_str());
                    std::cin >> option; 

                    if (option == 2) {
                        instants = deleteNode(instants, toModify);  
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
                                    string newName;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    while (true) {
                                        printf("Enter the new name for the instant: ");
                                        getline(std::cin, newName);
                                        if (name == newName) {
                                            printf("\u001b[31mThe name is the same as the current!\u001b[0m\n");
                                            continue;
                                        } else if (places->search(newName) != nullptr) {
                                            printf("\u001b[31mThe name already exist! Choose another name...\u001b[0m\n");
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

                            string attributeModify;
                            printf("Do you want to modify another information of this instant register? [y/n]: ");
                            getline(std::cin, attributeModify);
                            if (!(attributeModify == "y" or attributeModify == "Y")) {
                                break;
                            }
                        }
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(13, "Add a new instant", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    while (true) {
                        printf("\nEnter a descriptive name for the instant register: ");
                        getline(std::cin, name);
                        if (instants == nullptr) { break; } 
                        if (instants->search(name) == nullptr) { break; }
                        printf("\u001b[31mThis instant already exist! Choose another name...\u001b[0m\n");
                    }

                    // TODO: Implement time_t input
                    // FIXME: time_t params
                    if (instants == nullptr) {
                        instants = new Instant(name, 1, 1, 1);
                    } else {
                        instants = sortedInsert(instants, new Instant(name, 1, 1, 1));
                    }
                    printf("\n\u001b[34m%s was added to instant register!\u001b[0m\n", name.c_str());
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(12, "Show registered climates",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (climates == nullptr) {
                        printf("\n\u001b[31mNo elements in the climates list!\u001b[0m\n");
                    } else {
                        climates->show();
                    }

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(11, "Modify a registered climate",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (climates == nullptr) {
                        printf("\n\u001b[31mNo elements to modify in the climates list!\u001b[0m\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 

                    climates->showById();

                    printf("\nEnter the ID of the climate: ");
                    string id;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, id);

                    Climate *toModify = climates->search(id);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe climate with the id %s doesn't exist in the register!\n\u001b[0m", id.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: Validate user input (1 or 2)
                    int option;
                    printf("\n\u001b[34m%s\u001b[0m\n(1) - Modify this climate register\n(2) - Delete this climate register\nSelect an option: ", toModify->id.c_str());
                    std::cin >> option; 

                    if (option == 2) {
                        Place *foundPlace = places->search(toModify->place->name);
                        Person *foundPerson = people->search(toModify->person->id);
                        foundPlace->climate = foundPlace->climate->deleteNode(foundPlace->climate, new Proxy(toModify));
                        foundPerson->climates = foundPerson->climates->deleteNode(foundPerson->climates, new Proxy(toModify));
                        rains = deleteNode(rains, toModify->rain);
                        climates = deleteNode(climates, toModify);  
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
                                    string newId;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    while (true) {
                                        printf("Enter the new id for the climate register: ");
                                        getline(std::cin, newId);
                                        if (id == newId) {
                                            printf("\u001b[31mThe ID is the same as the current!\u001b[0m\n");
                                            continue;
                                        } else if (rains->search(newId) != nullptr) {
                                            printf("\u001b[31mThe ID already exist! Choose another ID...\u001b[0m\n");
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
                                                string newId;
                                                // Flush buffer
                                                std::cin.clear();
                                                std::cin.ignore(INT32_MAX, '\n');
                                                while (true) {
                                                    printf("Enter the new id for the rain register: ");
                                                    getline(std::cin, newId);
                                                    if (id == newId) {
                                                        printf("\u001b[31mThe ID is the same as the current!\u001b[0m\n");
                                                        continue;
                                                    } else if (rains->search(newId) != nullptr) {
                                                        printf("\u001b[31mThe ID already exist! Choose another ID...\u001b[0m\n");
                                                        continue;
                                                    }
                                                    rainToModify->id = newId;
                                                    break;
                                                }
                                                break;
                                            }
                                            case 2: {
                                                printf("Enter the new name for the rain register: ");
                                                string newName;
                                                // Flush buffer
                                                std::cin.clear();
                                                std::cin.ignore(INT32_MAX, '\n');
                                                getline(std::cin, newName);
                                                rainToModify->name = newName;
                                                break;
                                            }
                                            case 3: {
                                                printf("Enter the new rainfall value for the rain register: ");
                                                // TODO: validate user input
                                                double newRainfall;
                                                std::cin >> newRainfall;
                                                rainToModify->rainfall = newRainfall;
                                                break;
                                            }
                                        }
                                        string attributeModify;
                                        printf("Do you want to modify another information of this rain register? [y/n]: ");
                                        // Flush buffer
                                        std::cin.clear();
                                        std::cin.ignore(INT32_MAX, '\n');
                                        getline(std::cin, attributeModify);
                                        if (!(attributeModify == "y" or attributeModify == "Y")) {
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            string attributeModify;
                            printf("Do you want to modify another information of this climate register? [y/n]: ");
                            getline(std::cin, attributeModify);
                            if (!(attributeModify == "y" or attributeModify == "Y")) {
                                break;
                            }
                        }
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(10, "Add a new climate to the register", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (people == nullptr) {
                        printf("\u001b[31mThere isn't a person to associate this new climate!\u001b[0m\n");
                        return CommandCodes::CONTINUE;
                    } 
                    if (places == nullptr) {
                        printf("\u001b[31mThere isn't a place to associate this new climate!\u001b[0m\n");
                        return CommandCodes::CONTINUE;
                    }

                    people->showByNameId();
                    printf("\nEnter the ID of the person making the registration: ");
                    string personId;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, personId);

                    Person *foundPerson = people->search(personId);
                    if (foundPerson == nullptr) {
                        printf("\n\u001b[31mThe person with the ID %s doesn't exist in the register!\n\u001b[0m", personId.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    places->showByName();
                    printf("\nEnter the name of the place where the climate will be registered: ");
                    string placeName;
                    getline(std::cin, placeName);

                    Place *foundPlace = places->search(placeName);
                    if (foundPlace == nullptr) {
                        printf("\n\u001b[31mThe place with the name %s doesn't exist in the register!\n\u001b[0m", placeName.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: implement function body (user input for climate)
                    
                    // TODO: Implement time_t input
                    // FIXME: time_t params

                    string climateId;
                    while (true) {
                        printf("\nEnter an ID for the climate: ");
                        getline(std::cin, climateId);
                        if (climates == nullptr) { break; } 
                        if (climates->search(climateId) == nullptr) { break; }
                        printf("\u001b[31mThis ID already exist! Choose another id...\u001b[0m\n");
                    }
                    
                    // NOTE: Add the rain of the climate
                    printf("\nEnter a descriptive name for the rain: ");
                    string rainName;
                    getline(std::cin, rainName);

                    string id;
                    while (true) {
                        printf("Enter the id of the rain: ");
                        getline(std::cin, id);
                        if (rains == nullptr) { break; } 
                        if (rains->search(id) == nullptr) { break; }
                        printf("\u001b[31mThis ID already exist! Choose another id...\u001b[0m\n");
                    }

                    // TODO: Do a validation to rainfall
                    printf("Enter the average mm rainfall value of the rain: ");
                    double rainfall = 0.0;
                    std::cin >> rainfall;

                    Rain *newRain = new Rain(rainName, id, rainfall);
                    if (rains == nullptr) {
                        rains = newRain;
                    } else {
                        rains = insert(rains, newRain);
                    }

                    Climate *newClimate = new Climate(climateId, 3.2, 1.0, 2.1, 4.9, 1.8, 'N', false, 8, 9, 10, newRain, foundPlace, foundPerson);
                    if (climates == nullptr) {
                        climates = newClimate;
                    } else {
                        climates->append(newClimate);
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

                    printf("\n\u001b[34mThe data was added to the person %s!\u001b[0m\n", foundPerson->name.c_str());
                    printf("\n\u001b[34mThe data was added to the place %s!\u001b[0m\n", foundPlace->name.c_str());

                    printf("\n\u001b[34mThe data was added to climate register!\u001b[0m\n");
                    printf("\n\u001b[34mAdded a new rain register called: %s\u001b[0m\n", rainName.c_str());

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(9, "Show registered places",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (places == nullptr) {
                        printf("\n\u001b[31mNo elements in the places list!\u001b[0m\n");
                    } else {
                        places->show();
                    }

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(8, "Modify a registered place",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (places == nullptr) {
                        printf("\n\u001b[31mNo elements to modify in the places list!\u001b[0m\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 

                    places->showByName();

                    printf("\nEnter the name of the place: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    Place *toModify = places->search(name);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe place with name %s doesn't exist in the register!\n\u001b[0m", name.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: Validate user input (1 or 2)
                    int option;
                    printf("\n\u001b[34m%s\u001b[0m\n(1) - Modify this place register\n(2) - Delete this place register\nSelect an option: ", toModify->name.c_str());
                    std::cin >> option; 

                    if (option == 2) {
                        places = deleteNode(places, toModify);  
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
                                    string newName;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    while (true) {
                                        printf("Enter the new name for the place: ");
                                        getline(std::cin, newName);
                                        if (name == newName) {
                                            printf("\u001b[31mThe name is the same as the current!\u001b[0m\n");
                                            continue;
                                        } else if (places->search(newName) != nullptr) {
                                            printf("\u001b[31mThe name already exist! Choose another name...\u001b[0m\n");
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

                            string attributeModify;
                            printf("Do you want to modify another information of this place? [y/n]: ");
                            getline(std::cin, attributeModify);
                            if (!(attributeModify == "y" or attributeModify == "Y")) {
                                break;
                            }
                        }
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(7, "Add a new place",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (regions == nullptr) {
                        printf("\n\u001b[31mThere is no region to which to relate this new place!\u001b[0m\n\n");
                        return CommandCodes::CONTINUE;
                    }

                    regions->showByNameId();

                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    printf("\nEnter the id of the region to which whis new place belongs: ");
                    string regionId;
                    getline(std::cin, regionId);
                    Region *foundRegion = regions->search(regionId);
                    if (foundRegion == nullptr) {
                        printf("\n\u001b[31mRegion with the id %s not found!\u001b[0m\n", regionId.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    while (true) {
                        printf("\nEnter the name of the place: ");
                        getline(std::cin, name);
                        if (places == nullptr) { break; } 
                        if (places->search(name) == nullptr) { break; }
                        printf("\u001b[31mThis place already exist! Choose another place or try to add the distric in the name...\u001b[0m\n");
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
                    if (places == nullptr) {
                        places = newPlace;
                    } else {
                        places = insert(places, newPlace);
                    }
                    
                    if (foundRegion->places == nullptr) {
                        foundRegion->places = new Proxy(newPlace);
                    } else {
                        foundRegion->places->append(new Proxy<Place>(newPlace));
                    }

                    printf("\n\u001b[34m%s was added to places!\u001b[0m\n", name.c_str());
                    printf("\n\u001b[34mPlace %s successfully related to region %s!\u001b[0m\n", newPlace->name.c_str(), foundRegion->name.c_str());
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(6, "Show registered regions",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (regions == nullptr) {
                        printf("\n\u001b[31mNo elements in the region list!\u001b[0m\n");
                    } else {
                        regions->show();
                    }

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(5, "Modify a registered region", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (regions == nullptr) {
                        printf("\n\u001b[31mNo elements to modify in the region list!\u001b[0m\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 

                    regions->showByNameId();

                    printf("\nEnter the ID of the region: ");
                    string id;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, id);

                    Region *toModify = regions->search(id);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe region with id %s doesn't exist in the register!\n\u001b[0m", id.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: Validate user input (1 or 2)
                    int option;
                    printf("\n\u001b[34m%s - %s\u001b[0m\n(1) - Modify this region register\n(2) - Delete this region register\nSelect an option: ", toModify->name.c_str(), toModify->id.c_str());
                    std::cin >> option; 

                    if (option == 2) {
                        regions = deleteNode(regions, toModify);  
                    } else if (option == 1) {
                        bool modifyFlag = true;
                        while (modifyFlag) {
                            printf("\n(1) - Modify id\n");
                            printf("(2) - Modify name\n");
                            printf("(3) - Modify location\n");
                            printf("Select an option: ");

                            // TODO: Validate user input 
                            int modifyOption;
                            std::cin >> modifyOption;

                            switch (modifyOption) {
                                case 1: {
                                    string newId;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    while (true) {
                                        printf("Enter the new id for the region register: ");
                                        getline(std::cin, newId);
                                        if (id == newId) {
                                            printf("\u001b[31mThe ID is the same as the current!\u001b[0m\n");
                                            continue;
                                        } else if (regions->search(newId) != nullptr) {
                                            printf("\u001b[31mThe ID already exist! Choose another ID...\u001b[0m\n");
                                            continue;
                                        }
                                        toModify->id = newId;
                                        break;
                                    }
                                    break;
                                }
                                case 2: {
                                    printf("Enter the new name for the region register: ");
                                    string newName;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    getline(std::cin, newName);
                                    toModify->name = newName;
                                    break;
                                }
                                case 3: {
                                    printf("Enter the new location for the region register: ");
                                    // TODO: validate user input
                                    string newLocation;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    getline(std::cin, newLocation);
                                    toModify->location = newLocation;
                                    break;
                                }
                            }

                            string attributeModify;
                            printf("Do you want to modify another information of this region? [y/n]: ");
                            getline(std::cin, attributeModify);
                            if (!(attributeModify == "y" or attributeModify == "Y")) {
                                break;
                            }
                        }
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(4, "Add a new region", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    printf("\nEnter the name of the region: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    string id;
                    while (true) {
                        printf("Enter the ID of the region: ");
                        getline(std::cin, id);
                        if (regions == nullptr) { break; } 
                        if (regions->search(id) == nullptr) { break; }
                        printf("\u001b[31mThis ID already exist! Choose another id...\u001b[0m\n");
                    }

                    string location;
                    printf("Enter the location of the region: ");
                    getline(std::cin, location);

                    if (regions == nullptr) {
                        regions = new Region(name, id , location);
                    } else {
                        regions = insert(regions, new Region(name, id , location));
                    }
                    printf("\n\u001b[34m%s was added to regions!\u001b[0m\n", name.c_str());

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(3, "Show registered persons", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    if (people == nullptr) {
                        printf("\n\u001b[31mNo elements in the person list!\u001b[0m\n");
                    } else {
                        people->show();
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(2, "Modify a registered person", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (people == nullptr) {
                        printf("\n\u001b[31mNo elements to modify in the person list!\u001b[0m\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 

                    people->showByNameId();

                    printf("\nEnter the ID of the person: ");
                    string id;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, id);

                    Person *toModify = people->search(id);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe person with the id %s doesn't exist in the register!\n\u001b[0m", id.c_str());
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    }

                    // TODO: Validate user input (1 or 2)
                    int option;
                    printf("\n\u001b[34m%s - %s\u001b[0m\n(1) - Modify this person\n(2) - Delete this person\nSelect an option: ", toModify->name.c_str(), toModify->id.c_str());
                    std::cin >> option; 

                    if (option == 2) {
                        people = deleteNode(people, toModify);  
                    } else if (option == 1) {
                        bool modifyFlag = true;
                        while (modifyFlag) {
                            printf("\n(1) - Modify id\n");
                            printf("(2) - Modify name\n");
                            printf("(3) - Modify age\n");
                            printf("Select an option: ");

                            // TODO: Validate user input 
                            int modifyOption;
                            std::cin >> modifyOption;

                            switch (modifyOption) {
                                case 1: {
                                    string newId;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    while (true) {
                                        printf("Enter the new id for the person: ");
                                        getline(std::cin, newId);
                                        if (id == newId) {
                                            printf("\u001b[31mThe ID is the same as the current!\u001b[0m\n");
                                            continue;
                                        } else if (people->search(newId) != nullptr) {
                                            printf("\u001b[31mThe ID already exist! Choose another ID...\u001b[0m\n");
                                            continue;
                                        }
                                        toModify->id = newId;
                                        break;
                                    }
                                    break;
                                }
                                case 2: {
                                    printf("Enter the new name for the person: ");
                                    string newName;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    getline(std::cin, newName);
                                    toModify->name = newName;
                                    break;
                                }
                                case 3: {
                                    printf("Enter the new age for the person: ");
                                    // TODO: validate user input
                                    short newAge;
                                    std::cin >> newAge;
                                    toModify->age = newAge;
                                    break;
                                }
                            }

                            string attributeModify;
                            printf("Do you want to modify another information of this person? [y/n]: ");
                            getline(std::cin, attributeModify);
                            if (!(attributeModify == "y" or attributeModify == "Y")) {
                                break;
                            }
                        }
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(1, "Add a new person",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("\n");

                    printf("Enter the name of the person: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    string id;
                    while (true) {
                        printf("Enter the id of the person: ");
                        getline(std::cin, id);
                        if (people == nullptr) { break; } 
                        if (people->search(id) == nullptr) { break; }
                        printf("\u001b[31mThis ID already exist! Choose another id...\u001b[0m\n");
                    }

                    printf("Enter the age of the person: ");
                    int age = 0;
                    // TODO: Do a validation to age
                    std::cin >> age;

                    // TODO: Implement join date based on user input
                    time_t joinDate;
                    time(&joinDate);

                    if (people == nullptr) {
                        people = new Person(name, id, age, joinDate);
                    } else {
                        people = sortedInsert(people, new Person(name, id, age, joinDate));
                    }
                    printf("\n\u001b[34m%s joined at %s\u001b[0m", name.c_str(), asctime(gmtime(&joinDate)));

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                })); 
    dataManagement->addItem( new MenuItem(0, "Back", 
                [](Menu *, Menu *) -> CommandCodes {
                    return CommandCodes::EXIT;
                }));

    // NOTE: Main Menu items definition
    menu->addItem((new MenuItem(3, "Show reports options", 
                [](Menu *menu, Menu *reports) -> CommandCodes { 
                    reports->display();
                    while (reports->prompt() == CommandCodes::CONTINUE);
                    menu->display();
                    return CommandCodes::CONTINUE;
                }))->withMenu(reports));
    menu->addItem((new MenuItem(2, "Show consultations options", 
                [](Menu *menu, Menu *consultations) -> CommandCodes { 
                    consultations->display();
                    while (consultations->prompt() == CommandCodes::CONTINUE);
                    menu->display();
                    return CommandCodes::CONTINUE;
                }))->withMenu(consultations));
    menu->addItem((new MenuItem(1, "Show data options", 
                [](Menu *menu, Menu *dataManagement) -> CommandCodes { 
                    dataManagement->display();
                    while (dataManagement->prompt() == CommandCodes::CONTINUE);
                    menu->display();
                    return CommandCodes::CONTINUE;
                }))->withMenu(dataManagement));
    menu->addItem(new MenuItem(0, "Exit",
                [](Menu*, Menu*) -> CommandCodes {
                    printf("\n\u001b[31mThank you for using the system!\u001b[0m\n");
                    return CommandCodes::EXIT;
                }));

    menu->display();

    while (menu->prompt() == CommandCodes::CONTINUE);

    return 0;
}
