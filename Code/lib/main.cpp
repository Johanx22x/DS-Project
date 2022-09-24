#include <cstdio>
#include <iostream>
#include <menu.hh>

int main() {
    // Principal menu definition
    Menu menu = Menu();

    // Sub-menus definition
    Menu dataManagement = Menu();
    Menu consult = Menu();
    Menu report = Menu();

    /* auto lambda = [&dataManagement]() { */
    /* auto lambda = []() { */
    /*     dataManagement.display(); */
    /*     while (dataManagement.prompt()); */
    /*     return -1; */
    /* }; */

    menu.addItem(new MenuItem(0, "Exit", []() {
                return -1;
                }));
    /* menu.addItem(new MenuItem(1, "Data management", *lambda)); */

    menu.addItem(new MenuItem(2, "Consults", []() {
                return -1;
                }));
    menu.addItem(new MenuItem(3, "Reports", []() {
                return -1;
                }));

    menu.display();

    while (!menu.prompt());

    return 0;
}
