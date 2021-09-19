#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 1. 原地翻转链表： O(n)空间
//    需要提供两个指针，分别指向头和尾
//    然后用两个指针pre, back, 遍历，直到back == tail
// 2. K个一组，注意子链表拼接

// head = [1,2,3,4,5], k = 3

class Solution {
public:
    // 输入输出采用pair：头尾指针
    pair<ListNode*, ListNode*>  reverseList(ListNode* head, ListNode* tail) {
        ListNode * pre = head;
        ListNode * back = tail->next;
        while (back != tail)
        {
            ListNode * temp = pre->next;
            pre->next = back;
            back = pre;
            pre = temp;

        }
        return pair<ListNode*, ListNode*> (tail, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* ptr = head;

        ListNode* pre = head;
        ListNode* next;

        ListNode* h;
        ListNode* t;

        while (ptr)
        {
            if (cnt % k == 0)
            {
                h = ptr;
                cout << "head: " << h->val << endl;
            }
            else if (cnt % k == k-1)
            {
                t = ptr;
                cout << "tail: " << t->val << endl;
                
                next = t->next;
                pair<ListNode*, ListNode*> p = reverseList(h, t);
                if (h == head)
                {
                    head = p.first;   
                }
                else {
                    pre->next = p.first;
                }
                p.second->next = next;
                ptr = p.second;
                pre = ptr;
            }
            
            cnt ++;
            
            ptr = ptr->next;
        }
        
        return head;
    }
};
void printList(ListNode* head) {
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    string input;
    cin >> input;
    input = input.substr(1, input.length() - 2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    istringstream output(input);
    ListNode * head = new ListNode(-1);
    ListNode * ptr = head;
    string row;
    while (output >> row)
    {
        ptr->next = new ListNode(atoi(row.c_str()));
        ptr = ptr->next;
    }
    int k;
    cin >> k;

    ListNode* tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    
    printList(head->next);
    Solution S;
    printList(S.reverseKGroup(head->next, k));
    // cout << head->next->val << endl;
    // cout << tail->val << endl;
    // printList(S.reverseList(head->next, tail));
    return 0;
}