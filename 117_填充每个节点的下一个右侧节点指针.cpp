/*
// Definition for a Node.
*/

#include <iostream>
#include <string>
#include <vector>
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

vector <string> nums;

class Solution {
public:
    void init(){
        string input;
        cin >> input;
        input = input.substr(1).erase(input.length() - 2);
        cout << input << endl;
        string num;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == ',')
            {
                nums.push_back(num);
                num = "";
            }
            else {
                num.push_back(input[i]);
            }
        }
        nums.push_back(num);

    }
    Node * add_node(int pos) {
        string s = nums[pos];
        Node* new_node;
        if (s == "null")
        {
            new_node = NULL;    
        }
        else{
            new_node = new Node(atoi(s.c_str()));
        }

        int next_pos;
        next_pos = pos * 2 + 1;
        if (next_pos < nums.size())
        {
            new_node->left = add_node(next_pos);
        }
        next_pos = pos * 2 + 2;
        if (next_pos < nums.size())
        {
            new_node->right = add_node(next_pos);
        }
        return new_node;
    }
    Node * create_tree(){
        if (nums.size())
        {
            return add_node(0);
        }
        return NULL;
    }
    void display(Node* root) {
        if (root)
        {
            cout << root->val;
            Node* next_son = root;
            while(next_son->next) {
                next_son = next_son->next;
                cout << next_son->val;
            }
            cout << "#";
            display(root->left);
        }
    }
    void level_display(Node* root){
        if (!root)
        {
            return ;
        }
        
        queue< Node* > que;
        que.push(root);
        Node* last_node;
        while(!que.empty()) {
            Node * front = que.front();
            cout << front->val << endl;
            if (last_node)
            {
                last_node->next = front;
            }
            last_node = front;
            que.pop();

            if (front->left)
            {
                que.push(front->left);
            }
            if (front->right)
            {
                que.push(front->right);
            }
        }
    }
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

int main(){
    Solution s;
    s.init();
    Node * root = s.create_tree();
    s.display(s.connect(root));
    return 0;
}