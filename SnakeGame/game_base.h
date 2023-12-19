#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "library.h"

//Start Game
void StartGame(){

    load();

    length = snakeSize;

    head.x=locationX;

    head.y=locationY;

    head.direction=RIGHT;

    Boarder();

    Food(); 

    life=3; 

    bend[0]=head;

    Move();   
}

void load()
{
    system("cls");
    gameTime = 0;

    //Singleplayer or Two Player
    if(nextGame == 0 && gameCount == 1){
        while(1==1){
            printf("Enter 1 for Single player or 2 for Two players: ");
            scanf(" %d" , &playerNumber);

            if (playerNumber == 1 || playerNumber == 2) { 
                system("cls");
                break;
            }
        }
    }

    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); 
        printf("%c",177);
    }

    printf("\x1b[42m");
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

void Delay(long double k)
{
    ScoreBoard();
    long double i;
    for(i=0; i<=(k*1000000); i++);
}

void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++) 
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=mapSize||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else{
            TwoPlayer();
        }
    }
}

void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}

void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("%c",snakeType);
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("%c",snakeType);
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++)
                {
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("%c",snakeType);
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++)
                {
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("%c",snakeType);
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}

void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   
    printf("%c", foodType);
    for(i=10; i<mapSize+1; i++)
    {
        GotoXY(i,10);
        printf("!");
        GotoXY(i,30);
        printf("!");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(mapSize,i);
        printf("!");
    }
}

int ScoreBoard()
{

    GotoXY(15,5);
    score=length-snakeSize;
    printf("SCORE : %d",(length-snakeSize));
    score=length-snakeSize;
    GotoXY(30,5);
    printf("Life : %d",life);
    GotoXY(45,5);
    printf("Difficulty : %s",gameDiffText);

    //If two people, show scores on the screen
    if(playerNumber == 2){
        GotoXY(15,8);
        printf(" %s : %d", player1.playerName, player1.score);
        GotoXY(30,8);
        printf(" %s : %d", player2.playerName, player2.score);
    }

    GotoXY(45,8);
    if(gameDiff == 3){
        printf("Game Time : %d Seconds", gameTime / 140000);
    }
    else if(gameDiff == 2){
        printf("Game Time : %d Seconds", gameTime / 300000);
    }
    else{
        printf("Game Time : %d Seconds", gameTime / 270000);
    }

    if(bonusLifeScore == score){
        life = life + 1;
        bonusLifeScore = -1;
    }

    if(life == 1){
        printf("\x1b[41m");
    }

    //INSANE MODE
    if(gameDiff == 4 && score % 3 == 0 && score != 0 && scoreCheck && mapSize > 70){
        mapSize = mapSize - 10;
        scoreCheck = false;
    }
    if (score % 3 != 0) {
        scoreCheck = true;
    }

    return score;
}

void TwoPlayer(){
    system("cls");
    
    //SinglePlayer
    if(playerNumber == 1){
        printf("Score is: %d \n\n", score);
        wantNextGame();
    }

    //TwoPlayer
    if(playerNumber == 2){
        //first player
        if(gameCount == 1){
            printf("Enter Player %d name: ", gameCount);
            scanf(" %s", &player1.playerName);
            player1.score = score;
            gameCount = gameCount + 1;
            StartGame();
        }
        //second player
        if(gameCount == 2){
            printf("Enter Player %d name: ", gameCount);
            scanf(" %s", &player2.playerName);
            player2.score = score;
            system("cls");
            showScore();
            wantNextGame();
        }
    }
}

void showScore(){
    printf("Player Name \t Score\n");
    printf("-----------------------\n");
    printf("\t %s | \t %d \n " , player1.playerName , player1.score);
    printf("\t %s | \t %d \n" , player2.playerName , player2.score);
    printf("-----------------------\n\n\n");
    if (player1.score > player2.score)
    {
        printf("The winner is %s with score %d \n\n" , player1.playerName , player1.score);
    }
    else if(player1.score < player2.score){
        printf("The winner is %s with score %d \n\n" , player2.playerName , player2.score);
    }
    else
    {
        printf("The draw is score %d \n\n" , player2.score);
    }
}

void wantNextGame(){
    printf("All lives completed\nBetter Luck Next Time!!!\n\n\nDo You Want Another Game? 0-No 1-Yes\n");
    scanf("%d", &nextGame);
    if(nextGame == 1){
        gameCount = 1;
        //Clear player names
        memset(&player1.playerName, 0, sizeof(struct Player));
        memset(&player2.playerName, 0, sizeof(struct Player));
        StartGame();
    }
    else{
        showMainMenu();
    }
}

#endif // GAME_BASE_H