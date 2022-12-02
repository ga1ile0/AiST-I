#include <iostream>
#include "LinkedStack.hpp"
#include <string>

using namespace std;

int prec(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
    
}

string infixtoPostfix(string s){
    LinkedStack stack;
    string res;
    char top_; 

    for(long unsigned int i=0;i<s.length() ; ++i){
        if(s[i] == ' ')
            continue;
        else if((s[i] >= '0' && s[i] <= '9') && (s[i+1] >= '0' && s[i+1] <= '9')){ 
            res += s[i];
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9' ){
            res += s[i];
            res += " ";
        }
        else if(s[i] == '('){
            stack.push((int)s[i]);
        }
        else if(s[i] == ')'){
            while(!stack.empty() && ((top_ = (char)stack.pop()) != '(')){
                res += top_;
                if(i != (s.length()- 1)){res += " ";} //bez warunku dodaje pojedyncza spacje na koniec, której nie chcemy
            }
            stack.push((int)top_);
            if(!stack.empty()){
                stack.pop();
            }
        }
        else{
            while((!stack.empty()) && (prec(top_ = (char)stack.pop()) > prec(s[i]))){
                res += top_;
            }
            stack.push((int)top_);
            stack.push((int)s[i]);
            
        }
    }
    while(!stack.empty()){
        res += (char)stack.pop();
    }
    
    return res;
}

int main(){
    string infix_exp;
    getline(cin, infix_exp);
    cout << infixtoPostfix(infix_exp) << endl;
    
}