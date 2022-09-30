#include <bits/types/time_t.h>
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
Rain *rains = new Rain("Storm", "1", 0.2);
Region *regions = new Region("San Carlos", "5", "Alajuela, Costa Rica");
Place *places = new Place("Santa Clara", 500, 1250.3);
// FIXME: time_t params for new Instant
Instant *instants = new Instant("A beautiful day", 0, 0, 0);
// FIXME: time_t params for new climate
Climate *climates = new Climate(2.3, 4.1, 8.2, 0.4, 31.8, 'N', true, 0, 1, 2);

int main() {
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
                    people->show();
                    rains->show();
                    places->show();
                    regions->show();
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
    dataManagement->addItem(new MenuItem(21, "Relate a climate register to a person",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: Relate a climate register to a person
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(20, "Relate a place with a climate register",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (Relate a place with a region)
                    // TODO: Relate to the correspondient rain node
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(19, "Show registered climates",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    climates->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(18, "Modify a registered climate",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(17, "Add a new climate to the register", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    climates->append(new Climate(3.2, 1.0, 2.1, 4.9, 1.8, 'N', false, 8, 9, 10));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(16, "Show registered instants",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    instants->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(15, "Modify a registered instant",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(14, "Add a new instant", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    printf("\nEnter a descriptive name for the instant register: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    // FIXME: time_t params
                    instants = sortedInsert(instants, new Instant(name, 1, 1, 1));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(13, "Relate a place to a region", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (Relate a place with a region)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(12, "Show registered places",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    places->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(11, "Modify a registered place",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(10, "Add a new place",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("\nEnter the name of the place: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    // TODO: Do a validation to population
                    int population;
                    printf("Enter the population of the place: ");
                    std::cin >> population;

                    // TODO: Do a validation to area
                    double area;
                    printf("Enter the area of the place: ");
                    std::cin >> area;

                    places = insert(places, new Place(name, population, area));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(9, "Show registered regions",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    regions->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(8, "Modify a registered region", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(7, "Add a new region", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    printf("\nEnter the name of the region: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    string id;
                    printf("Enter the ID of the region: ");
                    getline(std::cin, id);

                    string location;
                    printf("Enter the location of the region: ");
                    getline(std::cin, location);

                    regions = insert(regions, new Region(name, id , location));
                    printf("\n\u001b[34m%s was inserted!\u001b[0m\n", name.c_str());

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(6, "Show registered rains", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    rains->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(5, "Modify a registered rain", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(4, "Add a new rain",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("\nEnter a descriptive name for the rain: ");
                    string name;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, name);

                    printf("Enter the id of the rain: ");
                    string id;
                    getline(std::cin, id);

                    printf("Enter the average mm rainfall value of the rain: ");
                    double rainfall = 0.0;
                    // TODO: Do a validation to rainfall
                    std::cin >> rainfall;

                    rains = insert(rains, new Rain(name, id, rainfall));
                    printf("\n\u001b[34mAdded a new rain register called: %s\u001b[0m\n", name.c_str());

                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                })); 
    dataManagement->addItem(new MenuItem(3, "Show registered persons", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    if (people == nullptr) {
                        printf("\nNo elements in the list!\n");
                    } else {
                        people->show();
                    }
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(2, "Modify a registered person", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    if (people == nullptr) {
                        printf("\nNo elements to modify in the list!\n");
                        dataManagement->display();
                        return CommandCodes::CONTINUE;
                    } 
                    printf("\nEnter the ID of the person: ");
                    string id;
                    // Flush buffer
                    std::cin.clear();
                    std::cin.ignore(INT32_MAX, '\n');
                    getline(std::cin, id);

                    printf("%s", id.c_str());
                    Person *toModify = people->search(id);
                    if (toModify == nullptr) {
                        printf("\n\u001b[31mThe person does't exist in the register!\n\u001b[0m");
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
                                    printf("Enter the new id for the person: ");
                                    string newId;
                                    // Flush buffer
                                    std::cin.clear();
                                    std::cin.ignore(INT32_MAX, '\n');
                                    getline(std::cin, newId);
                                    toModify->id = newId;
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

                    printf("Enter the id of the person: ");
                    string id;
                    getline(std::cin, id);

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
                    printf("\n\u001b[34m%s joined at %s\u001b[0m\n", name.c_str(), asctime(gmtime(&joinDate)));

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
