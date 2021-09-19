#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = nullptr;
        ListNode* q = head;
        ListNode* t;
        while (q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        
        return p;
    }
};