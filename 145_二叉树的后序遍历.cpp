/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
class Solution {
private:
    TreeNode* root;
    vector<int> ans;
public:
    void digui(TreeNode* root){
        if (root)
        {
            digui(root->left);
            digui(root->right);
            cout << root->val << endl;
            this->ans.push_back(root->val);
            return;   
        }
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        digui(root);
        return this->ans;
    }
    void create_tree(){
        if (nums.size())
        {
            if (nums[0] == "null")
            {
                this->root = NULL;
                return ;
            }
            int val = atoi(nums[0].c_str());
            int pos = 0;
            TreeNode* node = new TreeNode(val);
            queue <TreeNode* > que;
            que.push(node);
            while(!que.empty()){
                TreeNode* front = que.front();
                pos++;
                if (pos >= nums.size())
                {
                    front->left = NULL;
                    front->right = NULL;
                    que.pop();
                    break;
                }
                if (nums[pos] != "null")
                {
                    front->left = new TreeNode(atoi(nums[pos].c_str()));
                    que.push(front->left);
                }
                else 
                    front->left = NULL;

                pos++;
                if (pos >= nums.size())
                {
                    front->right = NULL;
                    que.pop();
                    break;
                }
                if (nums[pos] != "null")
                {
                    front->right = new TreeNode(atoi(nums[pos].c_str()));
                    que.push(front->right);
                }
                else 
                    front->right = NULL;
                que.pop();
            }
            this->root = node;
            return;
        }
        this->root = NULL;
        return ;
    }
    void display_tree(TreeNode* node){
        if (node)
        {
            cout << node->val << endl;
            display_tree(node->left);
            display_tree(node->right);
        }
    }
    TreeNode* getTree(){
        return this->root;
    }
};

int main(){
    string input;
    cin >> input;
    input = input.substr(1);
    input = input.erase(input.length() - 1);
    string temp;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            nums.push_back(temp);
            temp = "";           
        }
        else {
            temp.push_back(input[i]);
        }
    }
    nums.push_back(temp);

    Solution S;
    S.create_tree();
    // S.display_tree(S.getTree());
    S.postorderTraversal(S.getTree());
    return 0;
}


// vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> ans;
//     if(root==nullptr)return ans;
//     stack<TreeNode*> st;
//     st.push(root);
//     while(!st.empty()){
//         TreeNode* node=st.top();
//         st.pop();
//         ans.push_back(node->val);//访问根
//         if(node->left){//后访问左
//             st.push(node->left);
//         }
//         if(node->right){//先访问右
//             st.push(node->right);
//         }
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }