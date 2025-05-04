#include <iostream>
#include <bits/stdc++.h>
using namespace std;



std::vector<std::string> split(const std::string& expr,const std::string& delim){
    // strtok is still better ...
    std::vector<std::string> tokens = std::vector<std::string>();
    std::string strcpy = expr;
    std::string token;

    std::size_t pos = strcpy.find(delim);

    while(pos != std::string::npos){
        token = strcpy.substr(0,pos);
        strcpy.erase(0,pos+(size_t)delim.length());

        tokens.push_back(token);
        pos = strcpy.find(delim);
    }

    if(strcpy.length() > 0){
        tokens.push_back(strcpy);
    }
    return tokens;
}

bool is_end(const vector<long int>&vec,int index){
    if(index == vec.size()-1) return true;
    bool possible = false;
    int pos_leaps = vec[index];
    for(int i = index+1 ; i <= (index + pos_leaps) && i < vec.size(); i++){
        possible |= is_end(vec,i);
    }
    return possible;
}

int main(void){
    string buffer;
    getline(cin,buffer);
    vector<string> fat = split(buffer," ");
    vector<long int> arr = vector<long int>((long int)fat.size()); 
    for(int i = 0 ; i < fat.size() ; i++){
        arr[i] = std::stoi(fat[i]);
    }
    // This is cute thank you yousuf and Ali <3
    long int reach = 1;
    int pivot = arr.size() -1;
    for(int i = arr.size()-2 ; i >= 0 ; i--){
        if(arr[i] >= reach){
            pivot = i;
            reach = 1;
        }else{
            reach++;
        } 
    }
    if(pivot == 0) cout << "True\n";
    else cout << "False\n";
    return 0;
}
