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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int cnt = 0;
        ListNode * ptr = head;
        ListNode * pre = head;
        while (head)
        {
            if (cnt % 2 == 0)
            {
                ListNode * next = head->next;
                if (next)
                {
                    if (pre == head)
                    {
                        head->next = next->next;
                        next->next = head;
                        head = next;
                        ptr = next;
                    }
                    else {
                        pre->next = next;
                        head->next = next->next;
                        next->next = head;
                        head = next;
                    }   
                }
            }
            
            cnt ++;
            pre = head;
            head = head->next;
        }
        return ptr;
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
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

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
    
    // printList(head->next);
    Solution S;
    printList(S.swapPairs(head->next));
    return 0;
}