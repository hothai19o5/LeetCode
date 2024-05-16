#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;
};

bool hasCycle(ListNode* head){
    if(head == nullptr) return false;
    ListNode* rabbit = head;
    ListNode* tortoise = head;
    // Nếu có chu trình thì sẽ kh bị tới nullptr
    while(rabbit != nullptr && rabbit->next != nullptr) {
        // Thỏ nhảy 2 bước
        rabbit = rabbit->next->next;
        // Rùa đi 1 bước
        tortoise = tortoise->next;
        // Nếu 2 con chạm nhau thì có chu trình
        // Không phải là trùng giá trị mà là trùng Node
        if(rabbit == tortoise) return true;
    }
    return false;
}

int main(){

}