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
#include <util.hh>
#include <instant.hh>

// FIXME: time_t params for new Person
Person *people = new Person("Johan", "2210", 18, 0);
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
                    // FIXME: time_t params
                    instants = sortedInsert(instants, new Instant("Sol", 1, 1, 1));
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
                    // TODO: implement function body (user input)
                    places = insert(places, new Place("Ciudad Quesada", 3000, 2342.2));
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
                    // TODO: implement function body (user input)
                    regions = insert(regions, new Region("San Ramon", "4", "Alajuela, Costa Rica"));
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
                    // TODO: implement function body (user input)
                    rains = insert(rains, new Rain("Lluvia fuerte", "2", 0.3));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                })); 
    dataManagement->addItem(new MenuItem(3, "Show registered persons", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    people->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(2, "Modify a registered person", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(1, "Add a new person",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: implement function body (user input)
                    // FIXME: time_t params for new Person
                    people->append(new Person("Aaron", "1507", 19, 0));
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
