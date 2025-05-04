#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define X 1
#define O 0

int table[3][3] = {};

bool checkr(int r,int x){
    for(int i = 0 ; i < 3 ; i++){
        if(table[r][i] != x) return false;
    }
    return true;
}
bool checkc(int c,int x){
    for(int i = 0 ; i < 3 ; i++){
        if(table[i][c] != x) return false;
    }
    return true;
}
bool checkright(int side,int x){
    for(int i = 0 ; i < 3 ; i++){
        if(table[i][3-i] != x) return false;
    }
    return true;
}
bool checkleft(int side,int x){
    for(int i = 0 ; i < 3 ; i++){
        if(table[i][i] != x) return false;
    }
    return true;
}
bool checkwin(int x){
    bool state = false;
    for(int i = 0 ; i < 3 ; i++){
        state |= checkr(i,x);
        state |= checkc(i,x);
        state |= checkc(i,x);
    }
    state |= checkright(i,x);
    state |= checkleft(i,x);
    return state;
}
int main(void){
    string buffer;
    bool turn;
    getline(cin,buffer);
    
    return 0;
}
