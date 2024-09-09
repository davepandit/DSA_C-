#include <bits/stdc++.h>
using namespace std;

bool checkValidParanthesis(string s){
    stack<char> stck;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            //then push into the stack 
            stck.push(s[i]);
        }
        else{
            //take out the top ele and then compare 
            if((s[i] == ')'  && stck.top() == '(') || (s[i] == ']' && stck.top() == '[') || (s[i] == '}' && stck.top() == '{')){
                //then move ahead
                stck.pop();
                continue;
            }else{
                return false;
            }
        }
    }

    return true;
}

int main() {
    string s = "()[{}()]";
    if (checkValidParanthesis(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }
    return 0;
}