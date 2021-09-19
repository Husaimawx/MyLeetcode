#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* l, TreeNode* r) : val(val), left(l), right(r){}
};

// 用unordered_map作dp，后序遍历
// dp1[root] = dp2[root->left] + dp2[root->right] + root->val;
// dp2[root] = max(dp1[root->left], dp2[root->left]) + max(dp1[root->right], dp2[root->right]);

class Solution {
public:
    unordered_map<TreeNode*, int> dp1, dp2;
    int rob(TreeNode* root) {
        dfs(root);
        return max(dp1[root], dp2[root]);
    }
    void dfs(TreeNode* root) {
        if (!root) {
            return ;
        }
        dfs(root->left);
        dfs(root->right);
        dp1[root] = dp2[root->left] + dp2[root->right] + root->val;
        dp2[root] = max(dp1[root->left], dp2[root->left]) + max(dp1[root->right], dp2[root->right]);
    }
    void printTree(TreeNode* root) {
        if (!root) {
            return;
        }
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
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
    
    while (!q.empty() && index < v.size() - 1)
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp)
        {
            temp->left = v[index];
            temp->right = v[index+1];
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
    cout << S.rob(root) << endl;
    return 0;
}