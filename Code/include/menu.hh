/**
 * In this header file is defined all the Menu and MenuItem class behavior and parameters
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 04/09/2022
 */

#pragma once
#include "command_codes.hh"
#include <cstdint>
#include <map>
#include <string>

// typedef to manage the lambda types and return values
typedef CommandCodes(action)(class Menu *, class Program *);

/**
 * Class that represents a Menu Item
 */
class MenuItem {
public:
  int8_t id;
  std::string name;
  ::action *action;
  class Menu *menu;
  class Program *ctx;

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
  MenuItem *withContext(class Program *ctx);
};

/**
 * Class that represents the a Menu in the system
 */
class Menu {
  std::string name;
  std::map<int8_t, MenuItem *> options = std::map<int8_t, MenuItem *>();

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
  Menu(std::string name, std::map<int8_t, MenuItem *> initializer);

  /**
   * Move constructor
   */
  Menu(Menu &&) = default;

  /**
   * Displays the current menu items
   */
  void display();

  /**
   * Prompts the user for input
   *
   * @returns int A return code that dictates whether or not the call was
   * successful
   */
  CommandCodes prompt();

  /**
   * Appends an item to the items vector
   *
   * It uses the item's internal id property as the key
   */
  void addItem(MenuItem *item);
};
