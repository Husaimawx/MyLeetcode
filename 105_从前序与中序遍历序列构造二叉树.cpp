#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// 很经典的一道题，刚好拿来复习
// 没看题解一遍过，但是写了一个小时。。。
// 思路很简单：每次从preordr里拿第一个节点作为根节点，然后用它去划分inorder，再根据inorder划分的size去划分preorder，两次划分得到四段数组，用这四段数组去递归构造根节点的左子树和右子树。

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() < 1)
        {
            return nullptr;
        }
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        pair<vector<int>, vector<int> > inorder_pairs = splitInOrder(rootVal, inorder);
        vector<int> pre = inorder_pairs.first;
        vector<int> after = inorder_pairs.second;
        pair<vector<int>, vector<int> > preorder_pairs = splitPreOrder(pre.size(), preorder);
        // for (int i = 0; i < pre.size(); i++)
        // {
        //     cout << pre[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < after.size(); i++)
        // {
        //     cout << after[i] << " ";
        // }
        // cout << endl;
        
        // for (int i = 0; i < preorder_pairs.first.size(); i++)
        // {
        //     cout << preorder_pairs.first[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < preorder_pairs.second.size(); i++)
        // {
        //     cout << preorder_pairs.second[i] << " ";
        // }
        // cout << endl;
        // cout << endl;
        root->left = buildTree(preorder_pairs.first, pre);
        root->right = buildTree(preorder_pairs.second, after);
        return root;
    }
    pair<vector<int>, vector<int> > splitInOrder(int val, vector<int>& inorder) {
        vector<int> pre;
        vector<int> after;
        bool flag = false;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == val)
            {
                flag = true;
                continue;
            }
            
            if (!flag)
            {
                pre.push_back(inorder[i]);
            }
            if (flag)
            {
                after.push_back(inorder[i]);
            }
        }
        return pair<vector<int>, vector<int> >(pre, after);
    }

    pair<vector<int>, vector<int> > splitPreOrder(int leftSize, vector<int>& preorder) {
        vector<int> pre;
        vector<int> after;
        int cnt = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            if (cnt < leftSize)
            {
                pre.push_back(preorder[i]);
            }
            if (cnt >= leftSize)
            {
                after.push_back(preorder[i]);
            }
            cnt ++;
        }
        return pair<vector<int>, vector<int> >(pre, after);
    }

    void test(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++)
        {
            cout << preorder[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < inorder.size(); i++)
        {
            cout << inorder[i] << " ";
        }
        cout << endl;
    }
    void printTree(TreeNode* root) {
        if (root)
        {
            cout << root->val << " ";
            printTree(root->left);
            printTree(root->right);
        }
        
    }
};

int main () {
    string input1, input2;
    // cin >> input1 >> input2;
    input1 = "[3,9,20,15,7]";
    input2 = "[9,3,15,20,7]";

    vector<int> preorder;
    vector<int> inorder;
    string temp;

    input1 = input1.substr(1, input1.length() - 2);
    for (int i = 0; i < input1.size(); i++)
    {
        if (input1[i] == ',')
        {
            input1[i] = ' ';
        }
    }
    istringstream output1(input1);
    while (output1 >> temp)
    {
        preorder.push_back(atoi(temp.c_str()));
    }


    input2 = input2.substr(1, input2.length() - 2);
    for (int i = 0; i < input2.size(); i++)
    {
        if (input2[i] == ',')
        {
            input2[i] = ' ';
        }
    }
    istringstream output2(input2);
    while (output2 >> temp)
    {
        inorder.push_back(atoi(temp.c_str()));
    }

    Solution S;
    S.printTree(S.buildTree(preorder, inorder));
    return 0;
}