#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public: 
    ListNode* sortList(ListNode* head) {
        // 快慢指针找中位数
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        // 递归左边
        ListNode* left = sortList(head);
        // 递归右边
        ListNode* right = sortList(slow);

        //只剩下两部分，合并
        return merge(left, right);
    } 
    // 合并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == nullptr)
        {
            cur->next = l2;
        }
        else {
            cur->next = l1;
        }
        return dummy->next;
    }
};

int main () {


    return 0;
}