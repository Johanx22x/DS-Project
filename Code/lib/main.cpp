#include "climate.hh"
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



// TODO: Create structures
// FIXME: time_t params for new Person
Person *personList = new Person("Johan", "2210", 18, 0);
Rain *rainList = new Rain("Storm", "1", 0.2);
Region *regionList = new Region("San Carlos", "5", "Alajuela, Costa Rica");

// TODO: Fix time_t params for new Instant
Instant *instantList = new Instant("A beautiful day", 0, 0, 0);

// TODO: Change
// TODO: Ma johan, a que diablos se refiere con change?????
int main() {
    // Principal menu definition
    Menu *menu = new Menu("Main Menu");

    // Sub-menus definition
    Menu *dataManagement = new Menu("Data Management Menu");
    /* Menu *consultations = new Menu("Consultations Menu"); */
    /* Menu *report = new Menu("Reports Menu"); */
    
    // dataManagement menu items definition
    dataManagement->addItem(new MenuItem(15, "Show registered instants",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    instantList->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(14, "Modify a registered instant",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(13, "Add a new instant", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: Change last argument in Instant constructor instantiation to be of an actual time_t type, and not just a 1
                    instantList = sortedInsert(instantList, new Instant("Sol", 1, 1, 1));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));

    // TODO: Implement MenuItems for Places
    dataManagement->addItem(new MenuItem(10, "Add a new place",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: add function body
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));

    dataManagement->addItem(new MenuItem(9, "Show registered regions",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    regionList->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(8, "Modify a registered region", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(7, "Add a new region", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    regionList = insert(regionList, new Region("San Ramon", "4", "Alajuela, Costa Rica"));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(6, "Show registered rains", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    rainList->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(5, "Modify a registered rain", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(4, "Add a new rain",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    rainList = insert(rainList, new Rain("Lluvia fuerte", "2", 0.3));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                })); 
    dataManagement->addItem(new MenuItem(3, "Show registered persons", 
                [](Menu *dataManagement, Menu*) -> CommandCodes {
                    personList->show();
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(2, "Modify a registered person", 
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                }));
    dataManagement->addItem(new MenuItem(1, "Add a new person",
                [](Menu *dataManagement, Menu *) -> CommandCodes {
                    // TODO: Fix time_t params for new Person
                    personList->append(new Person("Aaron", "1507", 19, 0));
                    dataManagement->display();
                    return CommandCodes::CONTINUE;
                })); 
    dataManagement->addItem( new MenuItem(0, "Back", 
                [](Menu *, Menu *) -> CommandCodes {
                    return CommandCodes::EXIT;
                }));

    // Main Menu items definition
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
