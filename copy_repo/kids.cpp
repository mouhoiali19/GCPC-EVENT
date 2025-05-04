#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(void){
    int size;
    cin>>size;
    map<int,int> table;
    vector<int> kids;
    while(size--){
        int kid;
        int dist;
        cin>>kid;
        cin>>dist;
        table[kid] = dist+kid;
        kids.push_back(kid);
    }
    for(int n:kids){
        if(n == table[table[n]]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
