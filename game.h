#include <iostream>
#pragma once
#include "board.h"
#include "user.h"
#include <conio.h>
#include <ctime>

class Game{
    private:
        Board* board;
        User* player;
    public:
        Game(){}
        Game(User*);
        void play();
        void end();
        ~Game();
};

Game::Game(User* p):player(p){
    board=new Board();
    board->init();
    player->start();
}

void Game::play(){
    system("cls");
    board->printBoard();
    int cursor[2]={0, 0};
    while(1){
        gotoXY(cursor[0]*2+(cursor[0]/3)+1, cursor[1]+(cursor[1]/3)+1);

        int input=getch();
        if(board->canPlace(cursor[0], cursor[1], input-'0') && input>='1' && input<='9'){
            board->setValue(cursor[0], cursor[1], input-'0');
            colorText(to_string(input-'0'), true, input-'0');
        }
        else{
            if(input==72 && cursor[1]>0) cursor[1]--;
            else if(input==75 && cursor[0]>0) cursor[0]--;
            else if(input==80 && cursor[1]<8) cursor[1]++;
            else if(input==77 && cursor[0]<8) cursor[0]++;
        }
        if(board->finish()){
            end();
            return;
        }
    }
}

void Game::end(){
    player->win();
    system("color 0a");
    gotoXY(0, 6);
    printCongratulation();
    gotoXY(0, 12);
}

Game::~Game(){
    delete board;
}