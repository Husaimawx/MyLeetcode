#include <vector>
#include <string>
using namespace std;

// 类似构建二叉树，精髓在于递归函数返回 vector<int> ，后序遍历

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // 存储中间值
        vector<int> count;
        for(int i = 0; i < expression.size(); i ++) {
            char c = expression[i];
            // 找到运算符
            if(c == '+' || c == '-' || c == '*') {
                // 运算符左边的运算结果
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                // 运算符右边的运算结果
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                // 左右两边继续运算
                for(int l = 0; l < left.size(); l++) {
                    for(int r = 0; r < right.size(); r++) {
                        switch(c) {
                            case '+':
                                count.push_back(left[l] + right[r]);
                                break;
                            case '-':
                                count.push_back(left[l] - right[r]);
                                break;
                            case '*':
                                count.push_back(left[l] * right[r]);    
                                break;
                        }
                    }
                }
            }
        }
        // count为空说明当前无运算符，只是单独的数字，直接放入count中
        if(count.size() == 0) {
            count.push_back(stoi(expression));
        }
        return count;
    }
};