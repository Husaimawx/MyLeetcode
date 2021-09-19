/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> storeNodes;
        while (head)
        {
            // cout << head->val<< endl;
            for (int i = 0; i < storeNodes.size(); i++)
            {
                if (storeNodes[i] == head) {
                    return true;
                }
            }
            storeNodes.push_back(head);
            head = head->next;
        }
        return false;
    }
};

ListNode* list;
int main(){
    string input;
    int pos;
    cin >> input >> pos;
    input = input.substr(1);
    input = input.erase(input.length()-1);
    list = new ListNode(-1);
    ListNode* plist = list;
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            plist->next = new ListNode(atoi(temp.c_str()));
            plist = plist->next;
            temp = "";
        }
        else {
            temp.push_back(input[i]);
        }
    }
    plist->next = new ListNode(atoi(temp.c_str()));
    plist = plist->next;
    
    Solution S;
    cout << S.hasCycle(list->next) << endl;
    
    
    
    return 0;
}



/*
    链表中如果存在环路，以为着只要无限循环下去就一定能遇到某种情况
    所以让两个指针一快一慢地走，总会相遇
*/
// bool hasCycle(ListNode* head){
//     return true;*/
//     if(!head||!head->next) return false;
//     ListNode*slow = head;
//     ListNode*fast = head;
//     while(fast&&fast->next){
//         slow = slow->next;
//         fast = fast->next->next;
//         if(fast==slow) return true;
//     }
//     return false;
// }