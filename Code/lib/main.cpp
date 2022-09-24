#include <cstdio>
#include <iostream>
#include <menu.hh>

int main() {
    // Principal menu definition
    Menu *menu = new Menu();

    // Sub-menus definition
    Menu *dataManagement = new Menu();
    /* Menu *consult = new Menu(); */
    /* Menu *report = new Menu(); */

    dataManagement->addItem(new MenuItem(0, "Exit", [](Menu *, Menu *) {
                std::cout << "sex\n";
                return 1;
                }));

    menu->addItem(new MenuItem(1, "Show data options", [](Menu *, Menu *dataManagement) { 
                dataManagement->display();
                std::cout << "semen\n";
                return dataManagement->prompt();
                }));

    menu->display();

    while (!menu->prompt());

    return 0;
}
