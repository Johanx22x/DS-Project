#pragma once
#include <string>
#include <unordered_map>

struct MenuItem {
    std::string name;
    int8_t id;
    int (*action)();
};

class Menu {
    std::unordered_map<int8_t, MenuItem> options;

public:

    Menu();

    Menu(std::unordered_map<int8_t, MenuItem> initializer);

    /**
     * Displays the current menu items
     */
    void display();

    /**
     * Prompts the user for input
     *
     * @returns int A return code that dictates whether or not the call was successful
     */
    int prompt();

    /**
     * Appends an item to the items vector
     *
     * It uses the item's internal id property as the key
     */
    void setItem(MenuItem item);
};
