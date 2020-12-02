#include <iostream>
#pragma once
using namespace std;

class Block{
    private:
        int val;
    public:
        Block(){ val=0; }
        Block(int v);
        int getValue(){ return this->val; }
        void setValue(int v){ val=v; }
};
Block::Block(int v):val(v){}

class Board{
    private:
        Block*** b;
    public:
        Board(){
            b=new Block**[9];
            for(int i=0; i<9; i++){
                b[i]=new Block*[9];
                for(int j=0; j<9; j++){
                    b[i][j]=new Block();
                }
            }
        }
        void printBoard(){
            for(int i=0; i<9; i++){
                if(i%3==0) cout<<"-------------------------"<<"\n";
                for(int j=0; j<9; j++){
                    if(j%3==0) cout<<"| ";
                    cout<<b[j][i]->getValue()<<" ";
                } cout<<"| \n";
            }
            cout<<"-------------------------"<<"\n";
        }   
        bool checkBlock(int x, int y){
            if(b[x][y]->getValue()==0) 
                return true;
            return false; 
        }
        void setValue(int x, int y, int v){
            if(checkBlock(x, y)){
                b[x][y]->setValue(v);
            }
        }
};