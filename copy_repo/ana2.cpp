#include <iostream>
#include <bits/stdc++.h>
using namespace std;
static const int di = 'a'-'A';
#define SMALL(c) c += (di)


inline bool CAP(char c){
    return (c >= 'A' && c <= 'Z');
}
inline bool low(char c){
    return (c >= 'a' && c <= 'z');
}
inline bool CHAR(char c){
    return (CAP(c) || low(c));
}
inline char getsmall(char c) {
    return c+di;
}



int main(void){
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin,str2);

    vector<unordered_map<strin,unordered_map<char,int>>> maps;
    unordered_map<int,int> master;
    // getting all the sub str 
    for(int i = 0 ; i < ; i++){
        unordered_map<strin,unordered_map<char,int>> temp;
        temp[str1.substr()]
        maps.push_back();
    }
    return 0;
}
