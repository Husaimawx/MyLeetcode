#include <vector>
#include <iostream>
using namespace std;

// 中序遍历

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderList;
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        for (int i = 0; i < inorderList.size() - 1; i ++) {
            ans = min(ans, abs(inorderList[i] - inorderList[i + 1]));
        }
        return ans;
    }

    void inorder(TreeNode * root) {
        if (!root) {
            return ;
        }
        inorder(root->left);
        inorderList.push_back(root->val);
        inorder(root->right);
    }
};