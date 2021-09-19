/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 同大取左，同小取右，一大一小返回root。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> tree_nodes;
int num;
TreeNode* root;
int p, q;

class Solution {
private:
    bool get_p = false;
    bool get_q = false;
public:
    void input(){
        string tree_str;
        cin >> tree_str;
        cin >> p >> q;
        int len = tree_str.length();
        string new_tree_str = tree_str.substr(1);
        new_tree_str = new_tree_str.erase(len - 2);
        len = new_tree_str.length();
        string s = "";
        for (int i = 0; i < len; i++)
        {
            if (new_tree_str[i] != ',')
            {
                s.push_back(new_tree_str[i]);
            }
            else {
                tree_nodes.push_back(s);
                s = "";
            }
        }
        tree_nodes.push_back(s);
        num = tree_nodes.size();
    }
    TreeNode* addNode(int pos){
        TreeNode* new_node;
        string s = tree_nodes[pos];
        
        if (s == "null")
        {
            new_node = NULL;    
            // cout << "null" << endl;
        }
        else{
            new_node = new TreeNode(atoi(s.c_str()));
            // cout << s << endl;
        }

        int next_pos;
        next_pos = pos * 2 + 1;
        if (next_pos < num)
        {
            new_node->left = addNode(next_pos);
        }
        next_pos = pos * 2 + 2;
        if (next_pos < num)
        {
            new_node->right = addNode(next_pos);
        }
        return new_node;
    }
    void display(TreeNode * node){
        if (node)
        {
            cout << node->val << endl;
            display(node->left);
            display(node->right);
        }
    }
    void createTree(){
        if (tree_nodes.size())
        {
            root = addNode(0);   
        }
    }
    TreeNode* func(TreeNode * node, int p, int q, TreeNode* nearest_parent){
        if (node)
        {
            if (node->val == p)
            {
                get_p = true;
            }
            if (node->val == q)
            {
                get_q = true;
            }
            
            if (get_p && get_q)
            {
                return nearest_parent;
            }
            TreeNode * ans;
            if (!get_p && !get_q)
            {
                nearest_parent = node;
            }
            
            if (node->left)
            {
                ans = func(node->left, p, q, nearest_parent);
                if (ans != NULL)
                {
                    return ans;
                }    
            }
            if (node->right)
            {
                ans = func(node->right, p, q, nearest_parent);
                if (ans != NULL)
                {
                    return ans;
                }   
            }
            return NULL;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
        return func(root, p->val, q->val, root);
    }
};

int main(){
    Solution S;
    S.input();
    S.createTree();
    // S.display(root);
    TreeNode * node_p = new TreeNode(p);
    TreeNode * node_q = new TreeNode(q);
    cout << S.lowestCommonAncestor(root, node_p, node_q)->val << endl;;
    return 0;
}



// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         TreeNode* ancestor = root;
//         while (true) {
//             if (p->val < ancestor->val && q->val < ancestor->val) {
//                 ancestor = ancestor->left;
//             }
//             else if (p->val > ancestor->val && q->val > ancestor->val) {
//                 ancestor = ancestor->right;
//             }
//             else {
//                 break;
//             }
//         }
//         return ancestor;
//     }
// };