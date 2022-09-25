#include <cstdio>
#include <iostream>
#include <menu.hh>
#include <person.hh>
#include <rain.hh>
#include <region.hh>
#include <util.hh>
#include <instant.hh>

/**
 * Inserts an element at the beginning of a list
 *
 * @tparam T The type of the list
 * @param list The list
 * @param node The element to be inserted
 */
template<typename T>
T *insert(T *list, T* node) {
    if (list == nullptr) return node;
    node->next = list;
    return node;
}

// TODO: check implementation for climate
// actually works only for instant
template<typename T>
T *sortedInsert(T *list, T* node) {
    if (list == nullptr) return node;

    T *curr = list;
    while (curr->date <= node->date);

    node->prev = curr->prev;
    curr->prev->next = node;
    node->next = curr;
    curr->prev = node;

    return list;
}

// Create structures
// TODO: Fix time_t params for new Person
Person *personList = new Person("Johan", "2210", 18, 0);
Rain *rainList = new Rain("Storm", "1", 0.2);
Region *regionList = new Region("San Carlos", "5", "Alajuela, Costa Rica");
// TODO: Fix time_t params for new Instant
Instant *instantList = new Instant("A beautiful day", 0, 0, 0);

int main() {
    // Principal menu definition
    Menu *menu = new Menu("Main Menu");

    // Sub-menus definition
    Menu *dataManagement = new Menu("Data Management Menu");
    /* Menu *consultations = new Menu("Consultations Menu"); */
    /* Menu *report = new Menu("Reports Menu"); */
    
    // dataManagement menu items definition
    dataManagement->addItem(new MenuItem(12, "Show registered instants",
                [](Menu *dataManagement, Menu *) -> int {
                    instantList->show();
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(11, "Modify a registered instant",
                [](Menu *dataManagement, Menu *) -> int {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(10, "Add a new Instant", 
                [](Menu *dataManagement, Menu *) -> int {
                    // TODO: Fix time_t params
                    instantList = sortedInsert<Instant>(instantList, new Instant("Sol", 1, 1, 1));
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(9, "Show registered regions",
                [](Menu *dataManagement, Menu *) -> int {
                    regionList->show();
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(8, "Modify a registered region", 
                [](Menu *dataManagement, Menu *) -> int {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(7, "Add a new region", 
                [](Menu *dataManagement, Menu*) -> int {
                    regionList = insert<Region>(regionList, new Region("San Ramon", "4", "Alajuela, Costa Rica"));
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(6, "Show registered rains", 
                [](Menu *dataManagement, Menu*) -> int {
                    rainList->show();
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(5, "Modify a registered rain", 
                [](Menu *dataManagement, Menu *) -> int {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(4, "Add a new rain",
                [](Menu *dataManagement, Menu *) -> int {
                    rainList = insert(rainList, new Rain("Lluvia fuerte", "2", 0.3));
                    dataManagement->display();
                    return 0;
                })); 
    dataManagement->addItem(new MenuItem(3, "Show registered persons", 
                [](Menu *dataManagement, Menu*) -> int {
                    personList->show();
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(2, "Modify a registered person", 
                [](Menu *dataManagement, Menu *) -> int {
                    printf("Not yet implemented!\n");
                    dataManagement->display();
                    return 0;
                }));
    dataManagement->addItem(new MenuItem(1, "Add a new person",
                [](Menu *dataManagement, Menu *) -> int {
                    // TODO: Fix time_t params for new Person
                    personList->append(new Person("Aaron", "1507", 19, 0));
                    dataManagement->display();
                    return 0;
                })); 
    dataManagement->addItem( new MenuItem(0, "Back", 
                [](Menu *, Menu *) -> int {
                    return -1;
                }));

    // Main Menu items definition
    menu->addItem((new MenuItem(1, "Show data options", 
                [](Menu *menu, Menu *dataManagement) -> int { 
                    dataManagement->display();
                    while (!dataManagement->prompt());
                    menu->display();
                    return 0;
                }))->withMenu(dataManagement));
    menu->addItem(new MenuItem(0, "Exit",
                [](Menu*, Menu*) -> int {
                    printf("\n\u001b[31mThank you for using the system!\u001b[0m\n");
                    return -1;
                }));

    menu->display();

    while (!menu->prompt());

    return 0;
}
