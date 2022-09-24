#include <cstdio>
#include <iostream>
#include <menu.hh>

int main() {
    Menu menu = Menu();

    menu.addItem(new MenuItem(0, "Exit", []() {
                return -1;
                }));

    menu.display();

    while (!menu.prompt());

    return 0;
}
