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

static void displayOptions() {
    std::cout << "0 - Exit Program\n";
    std::cout << "2 - Data Maintenance\n";
    std::cout << "3 - Consults\n";
    std::cout << "4 - Reports\n\n";
}

static void dataMaintenanceOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

static void consultsOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

static void reportsOptions() {
    std::cout << "0 - Return to principal menu\n\n";
}

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
