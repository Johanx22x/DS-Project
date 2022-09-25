#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>

typedef int(action)(class Menu*, class Menu*);

class MenuItem {
public:
    int8_t id;
    action *action;
    std::string name;
    class Menu *menu;

    MenuItem() = default;

    /**
     * Basic constructor with all three basic parameters
     *
     * @param id Item's id
     * @param name Item's name
     * @param *action The action to be run
     */
    MenuItem(int8_t id, std::string name, ::action *action);

    MenuItem *withId(uint8_t id);
    MenuItem *withName(std::string name);
    MenuItem *withAction(::action action);
    MenuItem *withMenu(class Menu *menu);
};

class Menu {
    std::string name;
    std::unordered_map<int8_t, MenuItem*> options = std::unordered_map<int8_t, MenuItem*>();

public:

    /**
     * Basic constructor with a name
     *
     * @param name The name for the current menu
     */
    Menu(std::string name);

    /**
     * Basic constructor with a name and an initializer unordered_map
     *
     * @param name The name for the current menu
     * @param initializer An initializer to prefill the current menu
     */
    Menu(std::string name, std::unordered_map<int8_t, MenuItem*> initializer);

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
