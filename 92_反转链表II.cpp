#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// 这题不难，和旋转链表很像，只不过还需要把剩下部分拼接起来
// 原地旋转链表：三个指针p = head; q = head->next; t = q->next;
// 做链表题有感：只要考虑清楚了，不要嫌多，多插指针。

// 2+3
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *n) : val(v), next(n) {}
};

class Solution {
public:
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right)
        {
            return head;
        }

        ListNode* fakeHead = new ListNode(-1, head);
        
        int cnt = 0;
        ListNode* t = nullptr;
        ListNode* p = fakeHead;
        ListNode* q = fakeHead->next;
        ListNode* pre = nullptr;
        ListNode* last = nullptr;
        ListNode* first = nullptr;
        while (q && cnt < left)
        {
            cnt ++;
            pre = p;
            p = p->next;
            q = q->next;
        }
        cout << "here" << endl;
        cout << pre->val << endl;
        first = p;
        cout << first->val << endl;
        while (q && cnt < right)
        {
            cnt ++;
            t =q->next;
            last = q;
            q->next = p;
            p = q;
            q = t;
        }
        cout << last->val <<endl;
        cout << p->val << endl;
        pre->next = last;
        first->next = t;
        return fakeHead->next;
    }

    void printList(ListNode* head) {
        ListNode* ph = head;
        while (ph)
        {
            cout << ph->val << " ";
            ph = ph->next;
        }
        cout << endl;
    }
};

int main() {
    string input;
    int left, right;
    cin >> input >> left >> right;

    input = input.substr(1, input.length() - 2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    
    istringstream output(input);

    ListNode* head = new ListNode(-1);
    ListNode* ph = head;
    string row;
    while (output>>row)
    {
        int num = atoi(row.c_str());
        ph->next = new ListNode(num);
        ph = ph->next;
    }
    
    Solution S;
    S.printList(head->next);
    S.printList(S.reverseBetween(head->next, left, right));
    // S.reverseBetween(head->next, left, right);
    return 0;
}