#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

//考虑用数组代替字符串

class Solution {
public:
    // 多位数乘一位数
    string multiplyMS(string num1, char c) {
        if (c == '0' || num1 == "0")
        {
            return "0";
        }

        reverse(num1.begin(), num1.end());
        
        string res = "";

        int buffer = 0;
        for (int i = 0; i < num1.size(); i++)
        {
            int a = num1[i] - '0';
            int b = c - '0';
            int ans = a * b + buffer;
            buffer = ans / 10;
            res = res + (to_string(ans % 10));
        }
        if (buffer > 0)
        {
            res = res + to_string(buffer);
        }

        while (res[res.size() - 1] == '0')
        {
            res.pop_back();
        }

        reverse(res.begin(), res.end());
        return res;
    }

    // 多位数加多位数
    string addMM(string num1, string num2) {
        if (num1 == "0")
        {
            return num2;
        }
        if (num2 == "0")
        {
            return num1;
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res = "";
        int buffer = 0;
        int ml = min(num1.size(), num2.size());
        for (int i = 0; i < ml; i++)
        {
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            int ans = a + b + buffer;
            buffer = ans / 10;
            res = res + to_string(ans % 10); 
        }
        for (int i = ml; i < num1.size(); i++)
        {
            int a = num1[i] - '0';
            int ans = a + buffer;
            buffer = ans / 10;
            res = res + to_string(ans % 10); 
        }
        for (int i = ml; i < num2.size(); i++)
        {
            int a = num2[i] - '0';
            int ans = a + buffer;
            buffer = ans / 10;
            res = res + to_string(ans % 10); 
        }
        if (buffer > 0)
        {
            res = res + to_string(buffer);
        }
        if (res[res.size() - 1] == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    // 竖式乘法
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
               
        string res = "0";
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            // 每一位相乘
            char c = num2[i];
            string ms = multiplyMS(num1, c);
            // 乘完补0
            if (ms != "0")
            {
                for (int j = 0; j < num2.size() - i - 1; j++)
                {
                    ms += "0";
                }
            }
            
            res = addMM(res, ms);
        }
        
        return res;
    }
};

int main() {
    string a;
    string b;
    cin >> a >> b;

    Solution S;
    cout << S.multiply(a,b) << endl;;
    return 0;
}