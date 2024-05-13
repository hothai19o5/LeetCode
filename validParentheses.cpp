#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validParenthese(string s) {
    stack<char> myStack;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            myStack.push(s[i]);
        } else {
            if (myStack.empty()) {
                return false; // Nếu myStack rỗng, không có ngoặc để đóng ngoặc đóng
            }
            if ((s[i] == ')' && myStack.top() != '(') ||
                (s[i] == ']' && myStack.top() != '[') ||
                (s[i] == '}' && myStack.top() != '{')) {
                return false; // Nếu không khớp, trả về false
            }
            myStack.pop();
        }
    }
    return myStack.empty(); // Nếu myStack rỗng, tất cả ngoặc đã được đóng đúng cách
}

int main() {
    string s = "()[{}]";
    if (validParenthese(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}