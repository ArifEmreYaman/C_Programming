#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "library.h"

void UserMainMenuChoice(){
    printf("Make your choice (1-3): ");
    scanf("%d", &userChoice);
    if (userChoice == ' ' || userChoice < 1 || userChoice > 3) { 
        system("cls");
        showMainMenu();
    }
    MainMenuChoice(userChoice);

}

//Main Menu
void showMainMenu() {
    system("cls");
    printf("\x1b[40m");
    printf("Main Menu\n");
    printf("1. START GAME\n");
    printf("2. SETTINGS\n");
    printf("3. EXIT\n\n\n");
    printf("NOTE: PLAY IN FULL SCREEN!!!\n\n\n");

    UserMainMenuChoice();

}

void MainMenuChoice(int choice) {
    system("cls");
    switch (choice) {
        case 1:
            StartGame();

            break;
        case 2:
            showSettings();

            break;
        case 3:
            exit(0);

            break;
        default:
            showMainMenu();

            break;
    }
}

#endif // MAIN_MENU_H