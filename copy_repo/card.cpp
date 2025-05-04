#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int twist(int num){
    int ni = (num-1);
    if(num % 2 == 0) return num/2;
    for(int i = num/2-1 ; i >= 1 ;i--){
        if(num % i == 0) return i; 
    }
    return 1;
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        int size;
        cin>>size;
        int cpy = size;
        vector<int> g1;
        vector<int> g2;
        while(cpy--){
            int gotten;
            cin>>gotten;
            g1.push_back(gotten);
        }
        while(size--){
            int gotten;
            cin>>gotten;
            g2.push_back(gotten);
        }
        int counter_maxiamal = 0;
        int index = 0;
        for (int i = 0; i < g1.size(); i++) {
            while(g1[i] != g2[i]){
                if(g1[i] > g2[i]){
                    g1[i] = twist(g1[i]);
                    counter_maxiamal++;
                }else{
                    g2[i] = twist(g2[i]);
                    counter_maxiamal++;
                } 
            } 
        }
        cout << counter_maxiamal << '\n';
    }
    
    return 0;
}
