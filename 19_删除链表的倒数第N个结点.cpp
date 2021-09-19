#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 快慢指针

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = 0;
        while (fast && cnt < n) 
        {
            cnt ++;
            fast = fast->next;
        }
        ListNode* preNode = slow;
        while (fast) 
        {
            fast = fast->next;
            preNode = slow;
            slow = slow->next;
        }
        if (preNode == slow)
        {
            return slow->next;
        }
        else {
            preNode->next = slow->next;
            return head;
        }
    }
};

void printList(ListNode * head) {
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
}
// 输入：head = [1,2,3,4,5], n = 2
// 输出：[1,2,3,5]

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
    ListNode * head = new ListNode(-1);
    ListNode * p = head;
    istringstream out(input);
    string s;
    while(out >> s) {
        head->next = new ListNode(atoi(s.c_str()));
        head = head->next;
    }

    int n;
    cin >> n;

    cout << endl;
    Solution S;
    ListNode * res = S.removeNthFromEnd(p->next, n);
    printList(res);
    return 0;
}