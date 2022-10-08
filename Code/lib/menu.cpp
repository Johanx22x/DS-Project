/**
 * Here is implemented all the methods from the person header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez, Gabriel Alfaro
 * @version 1.0
 *
 * last modification: 06/10/2022
 */

#include "command_codes.hh"
#include <menu.hh>
#include <cstdint>
#include <unordered_map>
#include <cstdio>
#include <util.hh>

/// See the documentation declared in the MenuItem header file
MenuItem::MenuItem(int8_t id, std::string name, ::action *action) {
    this->id = id;
    this->name = name;
    this->action = action;
}

/// See the documentation declared in the MenuItem header file
MenuItem *MenuItem::withId(uint8_t id) {
    this->id = id;
    return this;
}

/// See the documentation declared in the MenuItem header file
MenuItem *MenuItem::withName(std::string name) {
    this->name = name;
    return this;
}

/// See the documentation declared in the MenuItem header file
MenuItem *MenuItem::withAction(::action *action) {
    this->action = action;
    return this;
}

/// See the documentation declared in the MenuItem header file
MenuItem *MenuItem::withMenu(Menu* menu) {
    this->menu = menu;
    return this;
}

/// See the documentation declared in the MenuItem header file
MenuItem *MenuItem::withContext(class Program *ctx) {
  this->ctx = ctx;
  return this;
}

/// See the documentation declared in the MenuItem header file
Menu::Menu(std::string name, std::map<int8_t, MenuItem*> initializer) {
    this->name = name;
    this->options = initializer;
}

/// See the documentation declared in the MenuItem header file
Menu::Menu(std::string name) {
    this->name = name;
}

/// See the documentation declared in the MenuItem header file
void Menu::display() {
    printf("\n\u001b[33m%s:\u001b[0m\n", this->name.c_str());
    for (const auto& [id, value] : this->options) {
        printf("(%d) -> %s\n", id, value->name.c_str());
    }
}

/// See the documentation declared in the MenuItem header file
CommandCodes Menu::prompt() {
    int option = getInt("Select an option");

    MenuItem *curr = options.at(option);

    return curr->action(this, curr->ctx);
}

/// See the documentation declared in the MenuItem header file
void Menu::addItem(MenuItem *item) {
    options.insert_or_assign(item->id, item);
}
