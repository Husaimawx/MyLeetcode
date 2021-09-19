#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 这道题思路其实也很简单，关键在于怎么找一段链表的中位数，刚开始想着计算链表长度，但是没有利用到链表的特性。其实链表中找指定位置的元素都可以用快慢指针，在这道题里让快指针的速度是慢指针的两倍即可。
// 找到了中位数，每次就用这个数建立根节点，然后递归建造左子树和右子树：
//      node->left = buildTree(left, mid);
//      node->right = buildTree(mid->next, right);
// 在边界处理上卡了很久，由于 [-10]的中位数还是 -10，会导致无限次递归，所以应该判断当left == right 时终止，返回nullptr

class Solution {
public:
    ListNode* getMiddle(ListNode* left, ListNode* right){
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* buildTree(ListNode* left, ListNode* right){
        if (left == right)
        {
            return nullptr;
        }
        
        ListNode* mid = getMiddle(left, right);
        cout << mid->val << endl;
        TreeNode* node = new TreeNode(mid->val);
        
        node->left = buildTree(left, mid);
        node->right = buildTree(mid->next, right);

        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    void printList(ListNode * head) {
        ListNode* ph =head;
        while (ph)
        {
            cout << ph->val << " ";
            ph = ph ->next;
        }
        cout << endl;   
    }
    void printTree(TreeNode* root) {
        if (root)
        {
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
        
    }
};

int main () {
    string input;
    input = "-10,-3,0,5,9";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            input[i] = ' ';
        }
    }
    ListNode* head = new ListNode(-1);
    ListNode* ph = head;
    istringstream output(input);
    string temp;
    while (output >> temp)
    {
        ph->next = new ListNode(atoi(temp.c_str()));
        ph = ph->next;
    }
    
    Solution S;
    S.printList(head->next);
    S.printTree(S.sortedListToBST(head->next));
    cout << endl;
    return 0;
}