#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        digui(root);
        return ans;
    }
    // 以root为起点的最大路径长度，后序遍历
    int digui(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, digui(root->left));
        int right = max(0, digui(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }
};