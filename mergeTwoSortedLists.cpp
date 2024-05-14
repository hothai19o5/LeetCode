#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode() : value(0), next(nullptr) {};
    ListNode(int x) : value(x), next(nullptr) {};
    ListNode(int x, ListNode *node) : value(x), next(node) {};
};

void push_back(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

ListNode* mergeTwoSortedList(ListNode *list1, ListNode *list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->value <= list2->value){
        list1->next = mergeTwoSortedList(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoSortedList(list1, list2->next);
        return list2;
    }
}

int main(){
    // Test
    ListNode *head1 = nullptr;
    push_back(head1, 1);
    push_back(head1, 2);
    push_back(head1, 4);
    ListNode *head2 = nullptr;
    push_back(head2, 1);
    push_back(head2, 3);
    push_back(head2, 6);
    ListNode *result = mergeTwoSortedList(head1, head2);
    printList(result);
    return 0;
}