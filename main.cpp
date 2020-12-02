#include <iostream>
#include <algorithm>
#include "board.h"

using namespace std;

int main(void){
    Board* board;
    board=new Board();
    board->setValue(3, 2, 2);
    board->printBoard();
}