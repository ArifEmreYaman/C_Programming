#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <stdbool.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

struct Player {
    char playerName[50]; 
    int score;           
};

struct coordinate
{
    int x;
    int y;
    int direction;
};

typedef  struct coordinate coordinate;
struct Player player1, player2;

coordinate head, bend[500],food,body[500];

bool scoreCheck = true;
char key, snakeType = '*', foodType = 'F', *gameDiffText = "Easy";

int gameTime = 0, nextGame, gameCount = 1, playerNumber, score, length, bend_no, len, life, bonusLifeScore = -1, snakeSize = 1, gameDiff = 3, locationX = 25, locationY = 20, mapSize = 70, userChoice;

void StartGame();
void load();
void Delay(long double);
void Move();
void Food();
int ScoreBoard();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
void TwoPlayer();
void showScore();
void wantNextGame();

void showMainMenu();
void UserMainMenuChoice();
void MainMenuChoice(int choice);

void showSettings();
void UserSettingsChoice();
void SettingsChoice(int choice);

#include "main_menu.h"
#include "settings.h"
#include "game_base.h"
#include "move_system.h"

#endif // LIBRARY_H