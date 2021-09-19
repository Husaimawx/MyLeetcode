#include <iostream>
#include <vector>
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

// 从一开始就想错了思路，本来觉得用双指针能做，但其实在这道题里双指针会很复杂
// 其实这道题很简单，只要把重复的删了就行，通过比较cur->next和cur->next->next判断cur->next是否重复，如果cur->next重复，则删除所有值为cur->next->val的节点。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
        {
            return nullptr;
        }
        
        ListNode* realHead = new ListNode(-102);
        realHead->next = head;

        ListNode* cur = realHead;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val != cur->next->next->val) {
                cur = cur->next;
            }
            else {
                int temp = cur->next->val;
                while (cur->next && cur->next->val == temp)
                {
                    cur->next = cur->next->next;
                }
            }
        }

        return realHead->next;
    }
    void printList(ListNode* head) {
        ListNode* ph = head;
        while (ph)
        {
            cout << ph->val << " ";
            ph = ph -> next;
        }
        cout << endl;
    }
};

// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]

int main() {
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    ListNode* head = new ListNode(-1);
    ListNode* ph = head;
    istringstream output(input);
    string row;
    while (output >> row)
    {
        ph->next = new ListNode(atoi(row.c_str()));
        ph = ph->next;
    }
    Solution S;
    S.printList(head->next);
    S.printList(S.deleteDuplicates(head->next));

    return 0;
}