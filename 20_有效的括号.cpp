#include <iostream>
#include <string.h> 
#include <vector>
#include <stack>
using namespace std;

class Solution {
    stack<char> stack;
public:
    bool isMatched(char pre, char back) {
        if (pre == '(' && back == ')')
        {
            return true;
        }
        if (pre == '[' && back == ']')
        {
            return true;
        }
        if (pre == '{' && back == '}')
        {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        char c;
        char top;
        for (int i = 0; i < s.length(); i++)
        {
            c = s[i];
            if (c == '[' || c == '{' || c == '(')
            {
                cout << "push: " << c << endl;
                stack.push(c);
            }
            else {
                if (stack.empty())
                {
                    return false;
                }
                
                top = stack.top();
                if (isMatched(top, c))
                {
                    cout << "pop: " << top << endl;
                    stack.pop();
                }
                else 
                    return false;
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};

int main() {
    string input;
    cin >> input;
    Solution s;
    cout << s.isValid(input) << endl;
    return 0;
}