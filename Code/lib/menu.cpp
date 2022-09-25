#include <menu.hh>
#include <cstdint>
#include <unordered_map>
#include <cstdio>
#include <util.hh>

MenuItem::MenuItem(int8_t id, std::string name, ::action *action) {
    this->id = id;
    this->name = name;
    this->action = action;
}

MenuItem *MenuItem::withId(uint8_t id) {
    this->id = id;
    return this;
}

MenuItem *MenuItem::withName(std::string name) {
    this->name = name;
    return this;
}

MenuItem *MenuItem::withAction(::action *action) {
    this->action = action;
    return this;
}

MenuItem *MenuItem::withMenu(Menu* menu) {
    this->menu = menu;
    return this;
}

Menu::Menu(std::string name, std::unordered_map<int8_t, MenuItem*> initializer) {
    this->name = name;
    this->options = initializer;
}

Menu::Menu(std::string name) {
    this->name = name;
}

void Menu::display() {
    printf("%s\n", this->name.c_str());
    for (const auto& [id, value] : this->options) {
        printf("(%d) -> %s\n", id, value->name.c_str());
    }
}

int Menu::prompt() {
    printf("Select an option: ");
    int option = getInt();

    MenuItem *curr = options.at(option);

    return curr->action(this, curr->menu);
}

void Menu::addItem(MenuItem *item) {
    options.insert_or_assign(item->id, item);
}
