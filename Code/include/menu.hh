#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>
#include <functional>

struct MenuItem {
    std::string name;
    int8_t id;
    int(*action)();

    MenuItem(int8_t id, std::string name, int(*action)());
};

class Menu {
    std::unordered_map<int8_t, MenuItem> options = std::unordered_map<int8_t, MenuItem>();

public:

    Menu() = default;

    Menu(std::unordered_map<int8_t, MenuItem> initializer);

    /**
     * Move constructor
     */
    Menu(Menu&&) = default;

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
    void addItem(MenuItem *item);
};
