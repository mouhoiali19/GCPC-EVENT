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
namespace bobo {
 struct giga {
    string type;
    long long int num;

    void print(void){
        cout << "type: " << type << " num: " << num << '\n'; 
    }
};   
}


// returns bytes
long long int makeout(const bobo::giga& a){
    if(a.type == "Kb"){
        return a.num*1024;
    }
    if(a.type == "kB"){
        return a.num*1024;
    }
    if(a.type == "B"){
        return a.num;
    }
    if(a.type == "MB" || a.type == "mB"){
        return a.num*1024*1024;
    }
    if(a.type == "GB"){
        return a.num*1024*1024*1024;
    }
    if(a.type == "gb"){
        return a.num*1024*1024*1024/8;
    }
    if(a.type == "TB"){
        return a.num*1024*1024*1024*1024;
    }
    if(a.type == "tb"){
        return a.num*1024*1024*1024*1024/8;
    }
    return 0;
}
double youaresexy(const bobo::giga& a){
    return a.num/8.f;
}
int main(void){
    string buffer;
    getline(cin,buffer);
    vector<string> entries = split(buffer," ");
    for(string n:entries){
        bobo::giga parsed;
        parsed.num = 0;
        for(int i = 0 ; i < n.length() ; i++){
            char c = n[i];
            if(std::isdigit(c)){
                parsed.num *= 10;
                parsed.num += c - '0';
                continue;
            }else{
                parsed.type = n.substr(i,n.length()-i); 
                break;
            }
        }
        // parsed.print();
        if(parsed.type == "b") cout << youaresexy(parsed) << ' ';
        else cout << makeout(parsed) << ' ';
    }
    cout << '\n';

    return 0;
}
