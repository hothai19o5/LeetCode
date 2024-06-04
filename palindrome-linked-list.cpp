#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        if (fast != nullptr)
        {
            slow = slow->next;
        }

        while (slow != nullptr && prev != nullptr)
        {
            if (slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }

        return true;
    }
};