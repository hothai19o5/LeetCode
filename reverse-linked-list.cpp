#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        stack<int> myStack;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            myStack.push(temp->val);
            temp = temp->next;
        }

        ListNode *myList = new ListNode();
        ListNode *currentNode = myList;

        while (!myStack.empty())
        {
            ListNode *tNode = new ListNode(myStack.top());
            currentNode->next = tNode;
            currentNode = tNode;
            myStack.pop();
        }

        return myList->next;
    }
};