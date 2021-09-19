#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// 2+3
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode *n) : val(v), next(n) {}
};

// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]

// 闭合成环，然后断开

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }

        int l = getLength(head);
        int real_k = k % l;

        ListNode* ph = head;
        while (ph->next)
        {
            ph = ph->next;
        }
        ph->next = head;
        
        int cut_l = l + l - real_k;
        int pre_l = l - real_k + 1;
        int cnt = 1;
        ph = head;
        ListNode* start = nullptr;
        while (ph)
        {
            if (cnt == cut_l)
            {
                ph->next = nullptr;
                break;
            }
            if (cnt == pre_l) start = ph;
            ph = ph->next;
            cnt ++;
        }
        return start;
    }

    int getLength(ListNode* head) {
        int cnt = 0;
        ListNode* ph = head;
        while (ph)
        {
         cnt ++;   
         ph = ph->next;
        }
        return cnt;
    }

    void printList(ListNode* head) {
        ListNode* ph = head;
        int cnt = 0;
        while (ph)
        {
            cnt ++;
            if (cnt > 10)
            {
                return;
            }
            
            cout << ph->val << " ";
            ph = ph->next;
        }
        
    }
};

// 输入：head = [1,2,3,4,5], k = 2
// 输出：[4,5,1,2,3]

int main() {
    string input;
    int k;
    cin >> input >> k;

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
    S.printList(S.rotateRight(head->next, k));
    // S.rotateRight(head->next, k);
    return 0;
}