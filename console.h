#include <iostream>
#include <windows.h>
#pragma once

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

using namespace std;

void colorText(string i, bool canMod, int val){
    int color;
    if(canMod){
        if(val==0) color=BLUE;
        else color=YELLOW;
    }
    else color=RED;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void cT(string i, int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout<<i;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

void gotoXY(int x, int y){
    COORD pos={x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printCongratulation(){
    cT("== ", WHITE);
    cT("C", RED); cT("o", YELLOW); cT("n", CYAN); cT("g", LIGHTGREEN); cT("r", MAGENTA); cT("a", BROWN); cT("t", LIGHTGREY); 
    cT("u", YELLOW); cT("l", CYAN); cT("a", RED); cT("t", MAGENTA); cT("i", LIGHTGREEN); cT("o", LIGHTGREY); cT("n", BROWN); 
    cT(" ==", WHITE);
}

void printIntro(){
    cout<<"■■■■■■■■■■■■■■■■■■■■■"<<"\n";
    cout<<"■   _____           _       _          ■"<<"\n";
    cout<<"■  / ____|         | |     | |         ■"<<"\n";
    cout<<"■ | (___  _   _  __| | ___ | | ___   _ ■"<<"\n";
    cout<<"■  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |■"<<"\n";
    cout<<"■  ____) | |_| | (_| | (_) |   <| |_| |■"<<"\n";
    cout<<"■ |_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_|■"<<"\n";
    cout<<"■■■■■■■■■■■■■■■■■■■■■"<<"\n";
}