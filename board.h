#include <iostream>
#include <string>
#include "console.h"
#pragma once
using namespace std;

class Block{
    private:
        int val;
        bool canMod;
    public:
        Block();
        Block(int v);
        int getValue(){ return this->val; }
        void setValue(int v){ val=v; }
        void place(int v){ val=v; canMod=false; }
        void setMod(bool b){ canMod=b; }
        bool canModify(){ return this->canMod; }
        void printBlock() const;
};
Block::Block():val(0), canMod(true){}
Block::Block(int v):val(v), canMod(false){}
void Block::printBlock() const{
    colorText(to_string(this->val)+" ", this->canMod, this->val);
}

class Board{
    private:
        Block*** b;
    public:
        Board();
        void printBoard() const;
        bool checkBlock(int, int);
        bool canPlace(int, int, int);
        void setValue(int, int, int);
        void init();
        bool finish();
        ~Board();
};
Board::Board(){
    b=new Block**[9];
    for(int i=0; i<9; i++){
        b[i]=new Block*[9];
        for(int j=0; j<9; j++){
            b[i][j]=new Block();
        }
    }
}
void Board::printBoard() const{
    for(int i=0; i<9; i++){
        if(i%3==0) cout<<"\n";
        for(int j=0; j<9; j++){
            if(j%3==0) cout<<" ";
            b[j][i]->printBlock();
        } cout<<" \n";
    } cout<<"\n";
}
bool Board::checkBlock(int x, int y){
    return b[x][y]->canModify();
}
bool Board::canPlace(int x, int y, int v){
    for(int i=0; i<9; i++){
        if(b[i][y]->getValue()==v || b[x][i]->getValue()==v)
            return false;
    } 
    for(int i=x-x%3; i<x-x%3+3; i++){
        for(int j=y-y%3; j<y-y%3+3; j++){
            if(b[i][j]->getValue()==v)
                return false;
        }
    }
    return true;
}
void Board::setValue(int x, int y, int v){
    if(checkBlock(x, y)){
        b[x][y]->setValue(v);
    }
}
void Board::init(){
    /*b[0][0]->place(1);*/ b[1][0]->place(2); b[2][0]->place(3); b[3][0]->place(4); b[4][0]->place(5); b[5][0]->place(6); b[6][0]->place(7); b[7][0]->place(8); b[8][0]->place(9);
    b[0][1]->place(4); b[1][1]->place(5); b[2][1]->place(6); b[3][1]->place(7); b[4][1]->place(8); b[5][1]->place(9); b[6][1]->place(1); b[7][1]->place(2); b[8][1]->place(3);
    b[0][2]->place(7); b[1][2]->place(8); /*b[2][2]->place(9);*/ b[3][2]->place(1); b[4][2]->place(2); b[5][2]->place(3); b[6][2]->place(4); b[7][2]->place(5); b[8][2]->place(6);
    b[0][3]->place(2); b[1][3]->place(3); b[2][3]->place(4); b[3][3]->place(5); b[4][3]->place(6); b[5][3]->place(7); b[6][3]->place(8); b[7][3]->place(9); b[8][3]->place(1);
    b[0][4]->place(5); b[1][4]->place(6); b[2][4]->place(7); b[3][4]->place(8); b[4][4]->place(9); b[5][4]->place(1); b[6][4]->place(2); b[7][4]->place(3); b[8][4]->place(4);
    b[0][5]->place(8); b[1][5]->place(9); b[2][5]->place(1); b[3][5]->place(2); b[4][5]->place(3); b[5][5]->place(4); b[6][5]->place(5); b[7][5]->place(6); b[8][5]->place(7);
    b[0][6]->place(3); b[1][6]->place(4); b[2][6]->place(5); b[3][6]->place(6); b[4][6]->place(7); b[5][6]->place(8); b[6][6]->place(9); b[7][6]->place(1); b[8][6]->place(2);
    /*b[0][7]->place(6);*/ b[1][7]->place(7); b[2][7]->place(8); b[3][7]->place(9); b[4][7]->place(1); b[5][7]->place(2); b[6][7]->place(3); b[7][7]->place(4); b[8][7]->place(5);
    b[0][8]->place(9); b[1][8]->place(1); b[2][8]->place(2); b[3][8]->place(3); b[4][8]->place(4); b[5][8]->place(5); b[6][8]->place(6); b[7][8]->place(7); b[8][8]->place(8);
}
bool Board::finish(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(b[i][j]->getValue()==0) 
                return false;
        }
    }
    return true;
}
Board::~Board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            delete b[i][j];
        }
    }
}