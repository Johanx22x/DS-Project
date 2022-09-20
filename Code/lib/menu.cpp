#include <cstdio>
#include <menu.hh>
#include <iostream>
#include <string>

using std::string;

/// Return a int value
static int getInt() {
    // TODO: Find a better way to implement this function
    int ret = getchar();
    while (getchar() != '\n');
    return ret - 0x30;
}

/// Display options of principal menu
static void displayOptions() {
    std::cout << "0 - Exit Program\n";
    std::cout << "2 - Data Maintenance\n";
    std::cout << "3 - Consults\n";
    std::cout << "4 - Reports\n\n";
}

/// Display options of data maintenance menu
static void dataMaintenanceOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

/// Display options of consults menu
static void consultsOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

/// Display options of reports menu
static void reportsOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

/// Display a welcome message for the data maintenance menu
static void dataMaintenanceWelcome() {
    std::system("clear");
    std::cout << "\
╔═══╗      ╔╗          ╔═╗╔═╗            ╔╗                          \n\
╚╗╔╗║     ╔╝╚╗         ║║╚╝║║           ╔╝╚╗                         \n\
 ║║║║╔══╗ ╚╗╔╝╔══╗     ║╔╗╔╗║╔══╗ ╔╗╔═╗ ╚╗╔╝╔══╗╔═╗ ╔══╗ ╔═╗ ╔══╗╔══╗\n\
 ║║║║╚ ╗║  ║║ ╚ ╗║     ║║║║║║╚ ╗║ ╠╣║╔╗╗ ║║ ║╔╗║║╔╗╗╚ ╗║ ║╔╗╗║╔═╝║╔╗║\n\
╔╝╚╝║║╚╝╚╗ ║╚╗║╚╝╚╗    ║║║║║║║╚╝╚╗║║║║║║ ║╚╗║║═╣║║║║║╚╝╚╗║║║║║╚═╗║║═╣\n\
╚═══╝╚═══╝ ╚═╝╚═══╝    ╚╝╚╝╚╝╚═══╝╚╝╚╝╚╝ ╚═╝╚══╝╚╝╚╝╚═══╝╚╝╚╝╚══╝╚══╝\n\n";
}

/// Display a welcome message for the consults menu
static void consultsWelcome() {
    std::system("clear");
    std::cout << "\
╔═══╗                ╔╗  ╔╗     \n\
║╔═╗║                ║║ ╔╝╚╗    \n\
║║ ╚╝╔══╗╔═╗ ╔══╗╔╗╔╗║║ ╚╗╔╝╔══╗\n\
║║ ╔╗║╔╗║║╔╗╗║══╣║║║║║║  ║║ ║══╣\n\
║╚═╝║║╚╝║║║║║╠══║║╚╝║║╚╗ ║╚╗╠══║\n\
╚═══╝╚══╝╚╝╚╝╚══╝╚══╝╚═╝ ╚═╝╚══╝\n\n";
}

/// Display a welcome message for the reports menu
static void reportsWelcome() {
    std::system("clear");
    std::cout << "\
╔═══╗                ╔╗     \n\
║╔═╗║               ╔╝╚╗    \n\
║╚═╝║╔══╗╔══╗╔══╗╔═╗╚╗╔╝╔══╗\n\
║╔╗╔╝║╔╗║║╔╗║║╔╗║║╔╝ ║║ ║══╣\n\
║║║╚╗║║═╣║╚╝║║╚╝║║║  ║╚╗╠══║\n\
╚╝╚═╝╚══╝║╔═╝╚══╝╚╝  ╚═╝╚══╝\n\
         ║║                 \n\
         ╚╝                 \n\n";
}

/// Display a welcome message for the principal menu
static void welcomeMessage() {
    std::system("clear");
    std::cout <<"\
╔════╗                                ╔╗        \n\
║╔╗╔╗║                               ╔╝╚╗       \n\
╚╝║║╚╝╔╗╔╗╔╗╔══╗    ╔═╗╔══╗╔══╗╔╗╔══╗╚╗╔╝╔══╗╔═╗\n\
  ║║  ╠╣║╚╝║║╔╗║    ║╔╝║╔╗║║╔╗║╠╣║══╣ ║║ ║╔╗║║╔╝\n\
 ╔╝╚╗ ║║║║║║║║═╣    ║║ ║║═╣║╚╝║║║╠══║ ║╚╗║║═╣║║ \n\
 ╚══╝ ╚╝╚╩╩╝╚══╝    ╚╝ ╚══╝╚═╗║╚╝╚══╝ ╚═╝╚══╝╚╝ \n\
                           ╔═╝║                 \n\
                           ╚══╝                 \n\n";
}

/// Data maintenance menu using a while true
static void dataMaintenanceMenu() {
    dataMaintenanceWelcome();
    while (true) {
        std::cout << "Enter an option (1 display options / 0 return to principal menu): ";
        int option = getInt();
        switch (option) {
            case 0:
                return;
            case 1:
                dataMaintenanceWelcome();
                dataMaintenanceOptions();
                break;
            default:
                dataMaintenanceWelcome();
                std::cout << "Invalid option!!!\n\n";
                break;
        }
    }
}

/// Consults menu using a while true
static void consultsMenu() {
    consultsWelcome();
    while (true) {
        std::cout << "Enter an option (1 display options / 0 return to principal menu): ";
        int option = getInt();
        switch (option) {
            case 0:
                return;
            case 1:
                consultsWelcome();
                consultsOptions();
                break;
            default:
                consultsWelcome();
                std::cout << "Invalid option!!!\n\n";
                break;
        }
    }
}

/// Reports menu using a while true
static void reportsMenu() {
    reportsWelcome();
    while (true) {
        std::cout << "Enter an option (1 display options / 0 return to principal menu): ";
        int option = getInt();
        switch (option) {
            case 0:
                return;
            case 1:
                reportsWelcome();
                reportsOptions();
                break;
            default:
                reportsWelcome();
                std::cout << "Invalid option!!!\n\n";
                break;
        }
    }
}

/// Principal menu implementation using a while true
void menu() {
    std::system("clear");
    welcomeMessage();

    while (true) {
        std::cout << "Enter an option (1 display options / 0 exit): ";
        int option = getInt();
        switch (option) {
            case 0:
                welcomeMessage();
                std::cout << "Thank you for use the program, have a nice day!\n";
                return;
            case 1:
                welcomeMessage();
                displayOptions();
                break;
            case 2:
                dataMaintenanceMenu();
                welcomeMessage();
                break;
            case 3:
                consultsMenu();
                welcomeMessage();
                break;
            case 4:
                reportsMenu();
                welcomeMessage();
                break;
            default:
                welcomeMessage();
                std::cout << "Invalid option!!!\n\n";
                break;
        }
    }
}
