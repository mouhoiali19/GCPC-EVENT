#include <iostream>
#include <bits/stdc++.h>
using namespace std;


map<string,string> num_str;
map<char,string> str_num;



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

int main(void){
    num_str["2"] = "a";
    num_str["22"] = "b";
    num_str["222"] = "c";
    num_str["3"] = "d";
    num_str["33"] = "e";
    num_str["333"] = "f";
    num_str["4"] = "g";
    num_str["44"] = "h";
    num_str["444"] = "i";
    num_str["5"] = "j";
    num_str["55"] = "k";
    num_str["555"] = "l";
    num_str["6"] = "m";
    num_str["66"] = "n";
    num_str["666"] = "o";
    num_str["7"] = "p";
    num_str["77"] = "q";
    num_str["777"] = "r";
    num_str["7777"] = "s";
    num_str["8"] = "t";
    num_str["88"] = "u";
    num_str["888"] = "v";
    num_str["9"] = "w";
    num_str["99"] = "x";
    num_str["999"] = "y";
    num_str["9999"] = "z";
    num_str["0"] = " ";

    str_num['a'] = "2";
    str_num['b'] = "22";
    str_num['c'] = "222";
    str_num['d'] = "3";
    str_num['e'] = "33";
    str_num['f'] = "333";
    str_num['g'] = "4";
    str_num['h'] = "44";
    str_num['i'] = "444";
    str_num['j'] = "5";
    str_num['k'] = "55";
    str_num['l'] = "555";
    str_num['m'] = "6";
    str_num['n'] = "66";
    str_num['o'] = "666";
    str_num['p'] = "7";
    str_num['q'] = "77";
    str_num['r'] = "777";
    str_num['s'] = "7777";
    str_num['t'] = "8";
    str_num['u'] = "88";
    str_num['v'] = "888";
    str_num['w'] = "9";
    str_num['x'] = "99";
    str_num['y'] = "999";
    str_num['z'] = "9999";
    str_num[' '] = "0";
    
    string state;
    getline(cin,state);
    string result;
    if(state == "1"){
        string buffer;
        getline(cin,buffer);
        vector<string> pieces = split(buffer," ");
        for(string n:pieces){
            int mod = 3;
            if(n[0] == '9' || n[0] == '7') mod = 4; 
            string parsed;
            if(n.length()%mod == 0) parsed = n.substr(0,mod);
            else parsed = n.substr(0,n.length()%mod);  
            //cout << parsed << '\n';
            result += num_str[parsed];
        }
        cout << result << '\n';
        return 0;
    }else if(state == "2"){
        string buffer;
        getline(cin,buffer);
        for(char c:buffer){
            result += str_num[c];
            result += ' ';
        }
        cout << result << '\n';
    }
    
    return 0;
}
