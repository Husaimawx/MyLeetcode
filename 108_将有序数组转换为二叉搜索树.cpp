#include <iostream>
#include <vector>
using namespace std;



struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 class Solution {
public:
    TreeNode* dfs(vector<int>& nums,int p_left,int p_right)
    {
        if(p_left >= p_right)
            return NULL;
        int mid = (p_right + p_left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, p_left, mid);
        root->right = dfs(nums, mid + 1, p_right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return dfs(nums,0,len);
    }
};