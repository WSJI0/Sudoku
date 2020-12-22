#include <iostream>
#include <vector>
#include <string>
#include "console.h"
#pragma once
using namespace std;

int number[]={1, 2, 3, 4, 5, 6, 7, 8, 9};

void rSort(){
    for(int i=0; i<9; i++){
        int r=rand()%9;
        swap(number[i], number[r]);
    }
}

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
        void remove();
        void setMod(bool b){ canMod=b; }
        bool canModify(){ return this->canMod; }
        void printBlock() const;
};
Block::Block():val(0), canMod(true){}
Block::Block(int v):val(v), canMod(false){}
void Block::remove(){
    canMod=true;
    val=0;
}
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
        void init(int);
        void getFullBoard(int, int);
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
    if(!checkBlock(x, y)) return false;
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
void Board::init(int dif){
    getFullBoard(0, 0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int r=rand()%dif;
            if(!r) b[i][j]->remove(); 
        }
    }
}
bool over=false;
void Board::getFullBoard(int x, int y){
    if(x==9 && y==8){
        if(finish() && !over){
            over=true;
        }
        return;
    }
    if(over) return;
    if(x>8){ x=0; y++; }
    rSort();
    for(int i=0; i<9; i++){
        int num=number[i];
        if(canPlace(x, y, num)){
            b[x][y]->place(num);
            getFullBoard(x+1, y);
            if(!over) b[x][y]->remove();
        }
    }
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
        } delete[] b[i];
    }
}