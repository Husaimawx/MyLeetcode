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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        convertBST (root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }

    TreeNode* digui(TreeNode* root, int preSum) {
        if (!root) {
            return nullptr;
        }

        TreeNode* newTree = new TreeNode(root->val + getSum(root->right) + preSum);
        newTree->left = digui(root->left, newTree->val);
        newTree->right = digui(root->right, preSum);
        return newTree;
    }

    int getSum(TreeNode * root) {
        if (!root) {
            return 0;
        }
        return root->val + getSum(root->left) + getSum(root->right);
    }
};