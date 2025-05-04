#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fibona(int step){
    if(step == 0 || step == 1) return 1;
    int prev = 1;
    int cur = 1;
    int s ;
    for(int i = 2 ; i <= step ; i++){
        s = cur;
        cur += prev;
        prev = s;
    }
    return cur;
}

int main(void){
    int size;
    cin>>size;
    vector<int> arr;
    while(size--){
        int n;
        cin>>n;
        arr.push_back(n);
    }
    int i = 0;
    int counter = 0;
    while(i < arr.size()){
        if(i >= arr.size()-1){
            cout << counter << '\n';
            return 0;
        }else if (arr[i] == 0){
            cout << -1 << '\n';
        } 
        i += fibona(i+2);
        counter++;
    } 
    for(;i < arr.size() ;i++){
        if(arr[i] == 0){
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << counter << '\n';
    return 0;
}
