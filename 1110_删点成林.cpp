
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> nums;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 递归 后序遍历

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        
        root = digui(root, to_delete, ans);
        if (root != nullptr) {
            ans.push_back(root);
        }
        return ans;
    }
    TreeNode* digui(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>& ans) {
        if (!root) {
            return nullptr;
        }
        root->left = digui(root->left, to_delete, ans);
        root->right = digui(root->right, to_delete, ans);
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            root = nullptr;    
        }
        return root;
    }
};