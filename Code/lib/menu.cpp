#include <menu.hh>
#include <cstdint>
#include <unordered_map>
#include <cstdio>
#include <util.hh>
#include <functional>

MenuItem::MenuItem(int8_t id, std::string name, int(*action)() ) {
    this->id = id;
    this->name = name;
    this->action = action;
}

Menu::Menu(std::unordered_map<int8_t, MenuItem> initializer) {
  this->options = initializer;
}

void Menu::display() {
    for (const auto& [id, value] : this->options) {
        printf("(%d) -> %s", id, value.name.c_str());
    }
    printf("\n");
}

int Menu::prompt() {
    // TODO: implement user prompting

    printf("Select an option: ");
    int option = getInt();

    return this->options.at(option).action();
}

void Menu::addItem(MenuItem *item) {
    this->options.insert_or_assign(item->id, *item);
}
