#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <string.h>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 题意很清楚，就是普通的搜索
// 用来复习一下bfs和dfs
// dfs比较简单，直接套用模版就行
// bfs就相对比较复杂了，首先需要用两个队列，一个存结点值，一个存和，二者一起push一起pop。其次是当达到目标状态之后需要获取路径，看了解析是用一个map存所有节点的父亲节点，然后一路从叶子结点走上去，最后reverse就是路径。

class Solution {
public:
    vector<vector<int> > ans;
    map<TreeNode*, TreeNode*> parent;
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int curSum = 0;
        // dfs(root, targetSum, path, curSum);
        bfs(root,targetSum);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum, vector<int> path, int curSum) {
        if (!root)
        {
            return;
        }
        
        if (!root->left && !root->right && curSum + root->val == targetSum)
        {
            cout << "get one " << endl;
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }
        path.push_back(root->val);
        curSum += root->val;
        if (root->left)
        {
            dfs(root->left, targetSum, path, curSum);
        }
        if (root->right)
        {
            dfs(root->right, targetSum, path, curSum);
        }
    }

    void getPath(TreeNode* node) {
        vector<int> tmp;
        while (node != nullptr) {
            tmp.push_back(node->val);
            node = parent[node];
        }
        reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }

    void bfs(TreeNode* root, int targetSum) {
        if (!root)
        {
            return;
        }
        queue<TreeNode*> q;
        queue<int> q_sum;

        q.push(root);
        q_sum.push(0);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            int cur = q_sum.front() + node->val;
            q_sum.pop();

            if (node->left == nullptr && node->right == nullptr) {
                if (cur == targetSum) {
                    getPath(node);
                }
            } 
            else {
                if (node->left != nullptr) {
                    parent[node->left] = node;
                    q.push(node->left);
                    q_sum.push(cur);
                }
                if (node->right != nullptr) {
                    parent[node->right] = node;
                    q.push(node->right);
                    q_sum.push(cur);
                }
            }
        }
        
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

// void dfs()//参数用来表示状态  
// {  
//     if(到达终点状态)  
//     {  
//         ...//根据题意添加  
//         return;  
//     }  
//     if(越界或者是不合法状态)  
//         return;  
//     if(特殊状态)//剪枝
//         return ;
//     for(扩展方式)  
//     {  
//         if(扩展方式所达到状态合法)  
//         {  
//             修改操作;//根据题意来添加  
//             标记；  
//             dfs（）；  
//             (还原标记)；  
//             //是否还原标记根据题意  
//             //如果加上（还原标记）就是 回溯法  
//         }  
 
//     }  
// }

//void bfs()
//{
//    queue q;
//    q.push(root);
//    visited[root] = true;
//    while (!q.empty())
//    {
//        cur = q.front();
//        q.pop();
//        if (cur == 目标状态)
//        {
//         ...//根据题意添加  
//        }
//        所有与cur相邻且未被访问的点进入队列
//        visited[cur] = true;        
//     }
// }

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

    int targetSum;
    cin >> targetSum;
    Solution S;
    S.printTree(root);
    vector<vector<int> > ans = S.pathSum(root, targetSum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}