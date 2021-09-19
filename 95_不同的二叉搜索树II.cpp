#include <iostream>
#include <vector>
using namespace std;

// buildTree函数返回 vector<TreeNode*>
// 后序遍历

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTree(1, n);
    }
    vector<TreeNode*> buildTree(int s, int e) {
        if (s > e) {
            return vector<TreeNode*>(1, nullptr);
        }
        vector<TreeNode*> ans;
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> left =  buildTree(s, i - 1);
            vector<TreeNode*> right = buildTree(i + 1, e);
            
            for (int l = 0; l < left.size(); l++) 
                for (int r = 0; r < right.size(); r++)  {
                    TreeNode * root = new TreeNode(i);
                    root->left = left[l];
                    root->right = right[r];
                    ans.push_back(root);
                }
        }
        return ans;
    }
 
 };