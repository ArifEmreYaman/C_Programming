#ifndef SETTINGS_H
#define SETTINGS_H

#include "library.h"

void UserSettingsChoice(){
    printf("Make your choice (1-8): ");
    scanf("%d", &userChoice);
    if (userChoice == ' ' || userChoice < 1 || userChoice > 8) { 
        system("cls");
        showSettings();
    }
    SettingsChoice(userChoice);

}

//Settings Menu
void showSettings() {
    printf("Settings\n");
    printf("1. SNAKE TYPE\n");
    printf("2. POINT VALUE FOR BONUS LIFE\n");
    printf("3. DIFFICULTY\n");
    printf("4. STARTING POSITION OF THE SNAKE\n");
    printf("5. SNAKE INITIAL SIZE\n");
    printf("6. FOOD TYPE\n");
    printf("7. MAP SIZE\n");
    printf("8. MAIN MENU\n\n\n");

    UserSettingsChoice();

}

void SettingsChoice(int choice) {
    system("cls");
    switch (choice) {
        case 1:
            printf("Type a one-character letter or symbol: ");
            scanf(" %c", &snakeType);
            if (snakeType == ' ') { 
                snakeType = '*'; 
            }
            system("cls");
            showSettings();

            break;
        case 2:
            printf("How many points will get you bonus lives: ");
            scanf(" %d", &bonusLifeScore);
            system("cls");
            showSettings();

            break;
        case 3:
            printf("Enter the difficulty level Hard 1, Medium 2, Easy 3, INSANE 4: ");
            scanf(" %d", &gameDiff);

            if(gameDiff == 1){
                gameDiffText = "Hard";
            }
            else if(gameDiff == 2){
                gameDiffText = "Medium";
            }
            else if(gameDiff == 4){
                gameDiffText = "INSANE";
            }
            else{
                gameDiffText = "Easy";
            }

            system("cls");
            showSettings();

            break;
        case 4:
            printf("Initial position of the snake X (15-60): ");
            scanf(" %d", &locationX);
            printf("Initial position of the snake Y (15-25): ");
            scanf(" %d", &locationY);
            if (locationX > 60 || locationX < 15) { 
                locationX = 25; 
            }
            if (locationY > 25 || locationY < 15) { 
                locationY = 20; 
            }
            system("cls");
            showSettings();
            
            break;
        case 5:
            printf("Type the snake initial size: ");
            scanf(" %d", &snakeSize);
            if (snakeSize == ' ' || snakeSize == 0 || snakeSize < 0) { 
                snakeSize = 1; 
            }
            system("cls");
            showSettings();
            
            break;
        case 6:
            printf("Type a one-character letter or symbol: ");
            scanf(" %c", &foodType);
            if (foodType == ' ') { 
                foodType = 'F'; 
            }
            system("cls");
            showSettings();
            
            break;
        case 7:
            printf("Type the map size (70-150): ");
            scanf(" %d", &mapSize);
            if (mapSize == ' ' || mapSize < 70) { 
                mapSize = 70; 
            }
            if (mapSize > 150) { 
                mapSize = 150; 
            }
            system("cls");
            showSettings();
            
            break;
        case 8:
            showMainMenu();
            
            break;
        default:
            showSettings();

            break;
    }
}

#endif // SETTINGS_H