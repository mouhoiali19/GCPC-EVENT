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
    int i = 0;
    bool stuck = false;
    while(i < arr.size()-1 && !stuck){
        long int temp = arr[i];
        int max_index = 0;
        long int max_reach = 0; 
        for(int j = 1 ; j <= temp ;j++){
            if(i+j > arr.size()-1){
                cout << "True\n";
                return 0;
            }
            if(arr[i+j] + j - temp > max_reach){
                max_index = j + i;
                max_reach = arr[i+j] + j - temp;
            } 
        }
        if(max_reach > 0) i = max_index;
        if(max_reach == 0){
            stuck = true;
            break;
        }
    }
    if(stuck) cout << "False\n";
    else cout << "True\n";
    return 0;
}
