#include <iostream>
#include <conio.h>
#include "game.h"

using namespace std;

int main(void){
    Game* game=new Game();

    game->play();

    system("pause");
}