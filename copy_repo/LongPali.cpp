#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool pali(const string&str,int i,int j){
    while(i <= j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

// pair<int,int> paligood(const string&str,int i,int j){
//     if(str[i] != str[j]){
//         pair<int,int> p1 = paligood(str,i+1,j);
//         pair<int,int> p2 = paligood(str,i,j-1);
//     }
//     return paligood(i+1,j-1);
// }

int main(void){
    string buffer;
    cin>>buffer;
    bool isFound = false;
    int len = buffer.length();
    int i,j;
    while(len >= 2){
        for(int k = 0 ; k + len -1 < buffer.length() ;k++){
            i = k; j = k+len-1;
            isFound = pali(buffer,i,j);
            // cout << isFound << '\n';
            // cout << i << " " << j << '\n';
            if(isFound) break;
        }
        if(isFound) break;
        else len--; 
    }
    if(isFound){
        cout << buffer.substr(i,len);
    }
    else cout << buffer[0];
    cout << '\n';
    return 0;
}
