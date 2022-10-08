/**
 * Script to charge the main menu MenuItems in the dinamic library
 * Here is defined all the main menu management and functionality
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 05/10/2022
 */

#include <cstdint>
#include <menu.hh>
#include <program.hh>
#include <string>

extern "C" {
MenuItem *mainItems[] = {
    new MenuItem(
        0,
        "Exit",
        [](Menu *, Program *) -> CommandCodes {
          printf("\n\u001b[31mThank you for using the system!\u001b[0m\n");
          return CommandCodes::EXIT;
        }),
    new MenuItem(
        1,
        "Show data options",
        [](Menu *menu, Program *ctx) -> CommandCodes {
          ctx->dataManagement->display();
          while (ctx->dataManagement->prompt() == CommandCodes::CONTINUE) ;
          menu->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        2, 
        "Show consultations options",
        [](Menu *menu, Program *ctx) -> CommandCodes {
          ctx->consultations->display();
          while (ctx->consultations->prompt() == CommandCodes::CONTINUE) ;
          menu->display();
          return CommandCodes::CONTINUE;
        }),
    new MenuItem(
        3,
        "Show reports options",
        [](Menu *menu, Program *ctx) -> CommandCodes {
          ctx->reports->display();
          while (ctx->reports->prompt() == CommandCodes::CONTINUE) ;
          menu->display();
          return CommandCodes::CONTINUE;
        })
};

void DllExport setup(Program *program) {
  for (MenuItem *item : mainItems) {
    program->menu->addItem(item->withContext(program));
  }
}
}
