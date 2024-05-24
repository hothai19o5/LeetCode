#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return (compare(s) == compare(t));
    }
    string compare(string s){
        stack<char> myStack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '#') {
                myStack.push(s[i]);
            }else if(s[i] == '#' && myStack.empty() == false){
                myStack.pop();
            }
        }
        string myString = "";
        while(!myStack.empty()){
            char c = myStack.top();
            myStack.pop();
            myString += c;
        }
        return myString;
    }
};