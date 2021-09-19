#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0),next(nullptr) {}
    ListNode(int val) :val(val),next(nullptr) {}
    ListNode(int val, ListNode* next) :val(val),next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);
        ListNode* pl = left;
        ListNode* pr = right;
        ListNode* ph = head;
        while (ph)
        {
            if (ph->val < x)
            {
                pl->next = new ListNode (ph->val);
                pl = pl->next; 
            }
            else {
                pr->next = new ListNode (ph->val);
                pr = pr->next;
            }
            ph = ph->next;
        }

        // printList(left);
        // printList(right);
        pl->next = right->next;
        // printList(left);
        return left->next;
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

int main () {
    string input;
    cin >> input;
    int x;
    cin >> x;

    input =input.substr(1, input.length() - 2);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    
    ListNode* head = new ListNode(-1);
    ListNode* ph = head;
    istringstream output(input);;
    string row;
    while (output >> row)
    {
        ph->next = new ListNode(atoi(row.c_str()));
        ph = ph ->next;
    }
    
    Solution S;
    S.partition(head->next, x);
    
    return 0;
}