#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue(){}
    void push(int x) {
        stack1.push(x);
        if(stack2.empty()){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
    }
    
    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int pop = stack2.top();
        stack2.pop();
        return pop;
    }
    
    int peek() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int pop = stack2.top();
        return pop;
    }
    
    bool empty() {
        if(stack1.empty() && stack2.empty()) return true;
        return false;
    }
};