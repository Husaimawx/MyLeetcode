#include <iostream>
#include <string.h>
#include <sstream>
#include <queue>
using namespace std;

// 判断二叉搜索树是否合法，很简单，只需要判断左节点 < 当前节点 < 右节点，然后递归。
// 做这道题是因为好久没写树了，回忆一下树的构造、遍历
// 结果这道题坑了好久，提交了十几次，原因就在没考虑到要用Long Long。。。

// 3+3
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool flag = true;
    bool isValidBST(TreeNode* root) {
        checkNode(root, LONG_MIN, LONG_MAX);
        return flag;
    }
    void checkNode(TreeNode* node, long long min, long long max) {
        if (!flag)
        {
            return;
        }
        
        if (node)
        {
            if (node->val >= max || node->val <= min)
            {
                flag = false;
                return;
            }
            
            if (node->left)
            {
                if (node->left->val >= node->val) {
                    flag = false;
                    return;
                }
                checkNode(node->left, min, node->val);
            }
            if (node->right)
            {
                cout << node->val << " " << node->right->val << endl;
                if (node->val >= node->right->val)
                {
                    flag = false;
                    return;
                }
                checkNode(node->right, node->val, max);
            }
            
            
        }
        
    }
    void printTree(TreeNode* root) {
        if (root)
        {
            cout << root->val;
            printTree(root->left);
            printTree(root->right);
        }
    }
};

int main () {
    queue<TreeNode*> q;
    vector<TreeNode*> v;
    
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
    string temp;
    while (output>> temp)
    {
        if (temp == "null")
        {
            v.push_back(nullptr);
        }
        else
            v.push_back(new TreeNode(atoi(temp.c_str())));
    }
    
    TreeNode* root = v[0];
    int index = 1;
    q.push(root);
    
    while (!q.empty() && index < v.size() - 1)
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp)
        {
            temp->left = v[index];
            temp->right = v[index+1];
            index += 2;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    Solution S;
    S.printTree(root);
    cout << endl;
    cout << S.isValidBST(root) << endl;;
    
    return 0;
}