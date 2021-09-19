#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 复习了一下二叉树的层级遍历，小问题又一些，不过算是今天通过比较快的题目了
// 思路就是bfs，用一个queue来存节点，然后在每一轮的中把当前queue中的节点串联起来

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;
        
        queue< Node* > que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            Node* last_node = NULL;
            for (int i = 0; i < n; i++)
            {
                Node * front = que.front();
                que.pop();
                if (front->left)
                {
                    que.push(front->left);
                }
                if (front->right)
                {
                    que.push(front->right);
                }   
                if (i)
                {
                    last_node->next = front;
                }
                last_node = front;
            }
        }
        return root;
    }
};

int main () {

    return 0;
}