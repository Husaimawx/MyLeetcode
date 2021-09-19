#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isEqual(root, subRoot)) {
            return true;
        }
        return root->left && isSubtree(root->left, subRoot) || root->right && isSubtree(root->right, subRoot);
    }
    bool isEqual(TreeNode* a, TreeNode* b) {
        if (!a && !b) {
            return true; 
        }
        if (!a || !b) return false;
        
        if (a->val == b->val) {
            return isEqual(a->left, b->left) && isEqual(a->right, b->right);
        }

        return false;
    }
};