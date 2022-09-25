#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>

typedef int(action)();

struct MenuItem {
    std::string name;
    int8_t id;
    /* int(*action)(); */
    action *action;

    MenuItem() = default;
    MenuItem(int8_t id, std::string name, ::action *action);

    MenuItem *withId(uint8_t id);
    MenuItem *withName(std::string name);
    MenuItem *withAction(::action action);
};

class Menu {
    std::string name;
    std::unordered_map<int8_t, MenuItem> options = std::unordered_map<int8_t, MenuItem>();

public:

    Menu() = default;

    Menu(std::string name);

    Menu(std::string name, std::unordered_map<int8_t, MenuItem> initializer);

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
