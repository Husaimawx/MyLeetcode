#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    string* stdin_to_string(){
        string stdin;
        getline(cin,stdin);
        //cout << "stdin: " << stdin  << " size: " << stdin.size() << endl;

        int pos = stdin.find('+');
        // cout << pos  << endl;
        string str1 = stdin.substr(1, pos-3);
        string str2 = stdin.substr(pos+3, stdin.size()-pos-4);
        // cout << str1 << " size: " << str1.size() << endl;
        // cout << str2 << " size: " << str1.size() << endl;
        
        string* strs = new string[2];
        strs[0] = str1;
        strs[1] = str2;
        return strs;
    }

    ListNode* string_to_list(string str){
        ListNode *head;
        head = new ListNode(-1);
        ListNode* p;
        p = head;
        for (int i = 0; i < str.length(); i++)
        {
            //cout << i << ":" << endl;
            if (str[i] < '0' || str[i] > '9'){
                i += 3;
                //cout << "jump " << endl;
            }
            else {
                //cout << "catch " << str[i] << endl;
                p->next = new ListNode((int)(str[i])-(int)('0'));
                p = p->next;
            }
        }
        return head;
    }
    void list_to_stdout(ListNode* list){
        ListNode* p;
        p = list;
        while(p){
            cout << p->val;
            if(p->next){
                cout << " -> ";
                p = p->next;
            }
            else break;
        }
    }
    void showList(ListNode* listnode){
        ListNode* p;
        p = listnode;
        //cout << " show " << endl;
        while(p){
            cout << p->val << endl;
            if(p->next)p = p->next;
            else break;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        int bit = 0;
        int overflow = 0;
        ListNode* p1 = l1->next;
        ListNode* p2 = l2->next;
        ListNode* pans = ans;
        while(p1&&p2){
            //cout << " sub " << p1->val  <<  " " <<  p2->val  << endl;
            bit = p1->val + p2->val + overflow;
            if (bit > 9) {
                overflow = 1;
                bit = bit - 10;
            }
            else {
                overflow = 0;
            }
            //cout << " bit " << bit << endl;
            pans -> next = new ListNode(bit);
            pans = pans -> next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1){
            bit = p1->val + overflow;
            if (bit > 9) {
                overflow = 1;
                bit = bit - 10;
            }
            else {
                overflow = 0;
            }
            pans -> next = new ListNode(bit);
            pans = pans -> next;
            p1 = p1->next;
        }
        while (p2){
            bit = p2->val + overflow;
            if (bit > 9) {
                overflow = 1;
                bit = bit - 10;
            }
            else {
                overflow = 0;
            }
            pans -> next = new ListNode(bit);
            pans = pans -> next;
            p2 = p2->next;
        }
        if (!p1&&!p2&&overflow)
        {
            pans -> next = new ListNode(overflow);
            pans = pans -> next;
        }
        return ans -> next;
    }
};


int main(){
    Solution s;
    string* strs = s.stdin_to_string();
    s.list_to_stdout(s.addTwoNumbers(s.string_to_list(strs[0]),s.string_to_list(strs[1])));
    return 0;
}