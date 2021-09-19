#include <iostream>
#include <string.h>
#include <sstream>
#include <queue>
using namespace std;

// 3+3
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 想了半天还是没想出来，最后看的题解，发现秘诀在中序遍历
// 二叉搜索树的特点在于，中序遍历是递增数列，更换顺序后递增数列会出现不递增的点，
// 然后找规律发现不递增点分两种情况，分别交换即可

class Solution {
public:
    vector<int> inorderList;
    void recoverTree(TreeNode* root) {
        inorder(root);
        pair<int,int> swapped= findTwoSwapped(inorderList);
        recover(root, 2, swapped.first, swapped.second);
    }
    pair<int,int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                }
                else break;
            }
        }
        return pair<int,int>(x, y);
    }
    void recover(TreeNode* r, int count, int x, int y) {
        if (r != nullptr) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
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
    void inorder(TreeNode* root) {
        if (root)
        {
            inorder(root->left);
            inorderList.push_back(root->val);
            inorder(root->right);
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
    
    while (!q.empty() && index < v.size())
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp)
        {
            temp->left = v[index];
            if (index+1 < v.size())
            {
                temp->right = v[index+1];
            }
            else {
                temp->right = nullptr;
            }
            
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
    S.recoverTree(root);
    return 0;
}