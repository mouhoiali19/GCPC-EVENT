#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    long int n;
    cin>>n;
    long int sum = 0;
    vector<long int> pac;
    while(n--){
        long int cur;
        cin>>cur;
        sum += cur;
        pac.push_back(cur);
    }
    long int q;
    cin>>q;
    vector<vector<long int>> queries;
    while(q--){
        int x,y,m;
        cin>>x;
        cin>>y;
        cin>>m;
        queries.push_back({x,y,m});
        long int min;
        long int mini = 0;
        for(int i = 0 ; i < m ;i++){
            mini += pac[i];
        }
        min = std::min(sum+x,y+mini);
        cout << min << '\n';
    } 
    return 0;
}
