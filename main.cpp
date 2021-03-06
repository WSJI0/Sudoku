#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include "console.h"
#include "game.h"
#include "user.h"

#pragma execution_character_set("utf-8")

using namespace std;

int main(void){
    srand((unsigned)time(NULL));
    SetConsoleOutputCP(65001); 
    printIntro();

    User* player;
    player=checkUserCard();
    player->print();
    cout<<"게임을 시작하려면 아무 키나 눌러주세요."<<"\n";
    char key=getch();

    //system("mode con cols=22 lines=15");

    Game* game=new Game(player);
    game->play();

    delete player;
    system("pause>null");
}