#include <cstdio>
#include <iostream>
#include <menu.hh>

int main() {
    // Principal menu definition
    Menu *menu = new Menu("Main Menu");

    // Sub-menus definition
    Menu *dataManagement = new Menu("Data Management");

    // TODO: stop johan from naming things 💀💀💀
    /* Menu *consult = new Menu(); */
    /* Menu *report = new Menu(); */

    dataManagement->addItem( new MenuItem(0, "Exit", 
                    [](Menu *, Menu *) -> int {
                        return 1;
                    }));
    // after a lot of pointer fuckery I finally
    // found the solution to our problem, it was
    // hiding in plain sight, we now look like the
    // I hereby declare that both Johan and I are
    // a pair of idiots that can't see shit hidden
    // in plain sight.
    menu->addItem((new MenuItem(1, "Show data options", 
                    [](Menu *, Menu *dataManagement) -> int { 
                        dataManagement->display();
                        return dataManagement->prompt();
                    }))->withMenu(dataManagement));
    // Of course the problem was that we didn't add the fucking
    // menu as a child of the current item and we were trying to access
    // it anyway, thus trying to dereference a null pointer.

    menu->display();

    while (!menu->prompt());

    return 0;
}
