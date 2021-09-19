/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
        {
            return NULL;
        }
        ListNode* fastnode = head;
        ListNode* slownode = head;
        while (fastnode && fastnode->next)
        {
            fastnode = fastnode -> next -> next;
            slownode = slownode  -> next;
            if (fastnode == slownode)
            {
                ListNode *ptr = head;
                while (ptr != slownode) {
                    ptr = ptr->next;
                    slownode = slownode->next;
                }
                return ptr;
            }   
        }
        return NULL;
    }
};
// 根据题意，任意时刻，\textit{fast}fast 指针走过的距离都为 \textit{slow}slow 指针的 22 倍。因此，我们有

// a+(n+1)b+nc=2(a+b) \implies a=c+(n-1)(b+c)
// a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)

// 有了 a=c+(n-1)(b+c)a=c+(n−1)(b+c) 的等量关系，我们会发现：从相遇点到入环点的距离加上 n-1n−1 圈的环长，恰好等于从链表头部到入环点的距离。

// 因此，当发现 \textit{slow}slow 与 \textit{fast}fast 相遇时，我们再额外使用一个指针 \textit{ptr}ptr。起始，它指向链表头部；随后，它和 \textit{slow}slow 每次向后移动一个位置。最终，它们会在入环点相遇。



int main(){
    string input;
    cin >> input ;
    input = input.substr(1);
    input = input.erase(input.length() - 1);
    string temp;
    ListNode* list = new ListNode(-1);
    ListNode* plist = list;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ',')
        {
            list->next = new ListNode(atoi(temp.c_str()));
            list = list->next;
            temp = "";
        }
        else
        {
            temp.push_back(input[i]);
        }
    }
    list->next = new ListNode(atoi(temp.c_str()));
    Solution S;
    cout << S.detectCycle(plist->next)->val << endl;
    return 0;
}