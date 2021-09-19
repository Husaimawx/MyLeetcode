#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 后序遍历，没有孩子返回nullptr，有一个孩子就返回这个孩子，有两个孩子则在右孩子中找到最小后继，替换后在右孩子中递归删除最小后继。

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (!root->left && root->right) {
                root = root->right;
                return root;
            }
            if (root->left && !root->right) {
                root = root->left;
                return root;
            }
            if (root->left && root->right) {
                TreeNode* temp = getSuccesser(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            }
        }
        return root;
    }
    TreeNode* getSuccesser(TreeNode* root) {
        while (root->left) {
            root = root ->left;
        }
        return root;
    }
};