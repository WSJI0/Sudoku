#include <iostream>
#include <fstream>
#pragma once

using namespace std;

class User{
    private:
        string name;
        int clear;
        int tryCount;
    public:
        User(){}
        User(string n, int c, int t):name(n), clear(c), tryCount(t){}
        void print();
        void win();
        void start();
        void refresh();
};

void User::print(){
    cout<<"======"<<name<<"님의 전적======"<<"\n";
    cout<<"플레이 횟수 : "<<tryCount<<"\n";
    cout<<"성공한 횟수 : "<<clear<<"\n";
}
void User::win(){
    clear++;
    refresh();
}
void User::start(){
    tryCount++;
    refresh();
}
void User::refresh(){
    ofstream fout("user/user.dat");
    fout<<name<<"\n"<<clear<<"\n"<<tryCount;
    fout.close();
}

User* checkUserCard(){
    ifstream fin("user/user.dat");
    string name;
    int clear, tryCount;
    User* user;
    if(fin.fail()){
        cout<<"\n유저 카드가 없습니다. 아래 양식을 작성해주세요"<<"\n";
        cout<<"이름 : "; cin>>name;
        user=new User(name, 0, 0);
        ofstream fout("user/user.dat");
        fout<<name<<"\n0\n0";
        fout.close();
    }else{
        fin>>name;
        fin>>clear;
        fin>>tryCount;
        user=new User(name, clear, tryCount);
    }
    fin.close();
    return user;
}