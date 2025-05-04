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
    unordered_map<char,int> map1;  
    unordered_map<char,int> map2;
    for(char c:str1){
        if(CHAR(c)) map1[c]++;
    }
    for(char c:str2){
        if(CAP(c)) map2[getsmall(c)]++;
        else if(low(c)) map2[c]++;
    }
    // cout << map1['A'] << '\n';
    // return 0;
    string result;
    for(char c:str1){
        if(CAP(c) && map2[getsmall(c)] && !map1[getsmall(c)]){
            result += getsmall(c);
            map2[getsmall(c)]--;
        }else if(low(c) && map2[c]){
            result += c;
            map2[c]--;
        }else{
            continue;
        }
    }
    if(result == "") cout << "Not Found" << '\n';
    else cout << result << '\n';
    return 0;
}
