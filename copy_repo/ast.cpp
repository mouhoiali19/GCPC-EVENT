#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float perform_ops(char op,float x,float y){
    switch (op) {
        case '*':
            return x*y;
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '/':
            assert(y != 0);
            return x/y;
        default:
            break;
    }
    return 0;
}


int main(void){
    string buffer;
    cin>>buffer;
    stack<long int> data;
    stack<char> ops;
    double result = 0;
    for(int i = 0 ; i < buffer.length() ; i++){
        char c = buffer[i];
        switch (c) {
            // getting op
            case '(':
                ops.push(buffer[i+2]);
                i+=4;
                break;
            // get operands
            case '1' || '2' || '3' || '4' || '5':
                double op1 = 0;
                int max = 0;
                while(std::isdigit(buffer[i]) || buffer[i] == '.'){
                    max++;
                }
                op1 = std::stod(buffer.substr(i,max));
                double op2 = 0;
                i += (max + 3);
                max = 0;
                while(std::isdigit(buffer[i]) || buffer[i] == '.'){
                    max++;
                }
                op2 = std::stod(buffer.substr(i,max));    
                cout << "gotten " << op1 << ' ' << op2 << '\n';
                break;
            // perform_ops
            case ')':
                int op1 = data.top();
                data.pop();
                int op2 = data.top();
                data.pop();
                result = perform_ops(ops.top(),op1,op2);
                ops.pop();
                data.push(result);
                break;




            default:
                break;
        }
    }

    return 0;
}
