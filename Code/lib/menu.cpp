#include <cstdint>
#include <menu.hh>
#include <unordered_map>

Menu::Menu() {
    this->options = new std::unordered_map<int8_t, MenuItem>();
}
