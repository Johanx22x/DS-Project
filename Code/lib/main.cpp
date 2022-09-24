#include <menu.hh>
#include <cstdio>
#include <iostream>

int opt1() {
    std::cout << "hola\n";
    return 0;
};

int main() {
    Menu menu = Menu();

    menu.addItem(new MenuItem(1, "Sexo canino", &opt1));

    menu.display();

    return menu.prompt();
}
