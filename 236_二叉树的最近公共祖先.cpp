
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 同左取左，同右取右，一左一右返回root

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !q || !p) {
            return root;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        bool p_left = hasVal(root->left, p->val);
        bool q_left = hasVal(root->left, q->val);

        if (p_left && !q_left || !p_left && q_left) {
            return root;
        }

        if (p_left && q_left) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return lowestCommonAncestor(root->right, p, q);

    }
    bool hasVal(TreeNode* root, int val) {
        if (!root) {
            return false;
        }
        if (root->val == val) {
            return true;
        }
        return hasVal(root->left, val) || hasVal(root->right, val);
    }
};