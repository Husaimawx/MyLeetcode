/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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

class Solution {
    TreeNode* myroot;
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * node = root;
        while (node)
        {
            if (node->val < val && node->right)
            {
                node = node -> right;
            }
            else if (node->val > val && node->left)
            {
                node = node -> left;
            }
            else break;
        }
        if (!node)
        {
            return new TreeNode(val);
        }
        if (node->val < val)
        {
            node->right = new TreeNode(val);
        }
        else if (node->val > val)
        {
            node ->left = new TreeNode(val);
        }
        return root;
    }
    TreeNode * addNode(int pos){
        TreeNode*  new_node  = new TreeNode(atoi(nums[pos].c_str()));
        if (pos*2+1<nums.size())
        {
            new_node->left = addNode(pos*2+1);
        }
        if (pos*2+2<nums.size())
        {
            new_node->right = addNode(pos*2+2);
        }
        return new_node;
    }
    void createTree() {
        this->myroot = addNode(0);
    }
    void Display(TreeNode* node){
        if (node)
        {
            cout << node->val << endl;
            Display(node->left);
            Display(node->right);
        }
        
    }
    TreeNode &getroot(){
        return *this->myroot;
    }
};

int main(){
    string input;
    int num;

    cin >> input;
    cin >> num;

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
        else{
            temp.push_back(input[i]);
        }   
    }
    nums.push_back(temp);
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << endl;
    // }
    Solution S;
    S.createTree();
    S.Display(S.insertIntoBST(&S.getroot(),num));
    
    return 0;
}