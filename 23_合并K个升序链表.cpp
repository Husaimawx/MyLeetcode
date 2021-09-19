#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// 处理输入：把 '],[' 替换成 '] [' 用两次istringstream
// 定义结构体：
// struct Name {
//     int val;
//     Name(int v) {
//         val = v;
//     }
// }
// 重构函数：
//  bool operator < (const Name & n) { return val > n.val; }
// 优先级队列：
//  priority_queue<> q; #include <queue>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 
class Solution {
    // 封装链表队首值与链表指针
    struct pair
    {
        int val;
        ListNode * ptr;
        pair(int v, ListNode* p) {
            val = v;
            ptr = p;
        }
        bool operator < (const pair& p) const {
            return val > p.val;
        }
    };

    priority_queue<pair> pq;
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode * node = lists[i];
            if (node)
            {
                cout << node->val << endl;
                pq.push(pair(node->val, node->next));
            }
        }
        
        ListNode * head = new ListNode(-1);
        ListNode * ph = head;
        while (!pq.empty())
        {
            pair top = pq.top();
            cout << "top" << top.val << endl;
            pq.pop();
            head->next = new ListNode(top.val);
            head = head->next;
            if(top.ptr)pq.push(pair(top.ptr->val, top.ptr->next));
        }
        return ph->next;
    }
};

// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]

ListNode* stringToList(string s) {
    s = s.substr(1,s.length() - 2);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            s[i] = ' ';
        }
        
    }
    ListNode * head = new ListNode(-1);
    ListNode * ph = head;
    string v;
    istringstream out(s);
    while (out >> v)
    {
        head->next = new ListNode(atoi(v.c_str()));
        head = head->next;
    }
    return ph;
}

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
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == ']' && input[i + 1] == ',' && input[i + 2] == '[' )
        {
            input[i] = ']';
            input[i + 1] = ' ';
            input[i + 2] = '[';
        }
    }
    vector<ListNode*> lists;

    istringstream ouput(input);
    string s;
    while(ouput >> s) {
        lists.push_back(stringToList(s));
    }
    
    for (int i = 0; i < lists.size(); i++)
    {
        // cout << "List " << i << endl;
        printList(lists[i]);
    }
    
    Solution S;
    printList(S.mergeKLists(lists));

    return 0;
}