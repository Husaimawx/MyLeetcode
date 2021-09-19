#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


// 一波三折
// 看到这个题，竟然还想着用回溯做。。。花了二十分钟写了个回溯，结果只过了20个点，剩下的超时。
// 想到了动态规划，但是不知道怎么规划
// 看了题解才恍然大悟，设 f_i 表示字符串 s 的前 i 个字符 s[1..i] 的解码方法数，这样只需要分两种情况，判断最后一个字符和最后两个字符
// 结果写的时候搞错了下标，调了半天bug

class Solution {
public:
    int* dp;

    int numDecodings(string s) {
        int n = s.length();
        dp = new int[n+1];
        memset(dp, 0, sizeof(int) * (n+1));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i-1] != '0')
            {
                dp[i] += dp[i-1];
            }
            if (i > 1)
            {
                string temp;
                temp.push_back(s[i-2]);
                temp.push_back(s[i-1]);
                if (s[i-2] != '0' && temp <= "26")
                {
                    dp[i] += dp[i-2];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
        
        return dp[n];
    }
    
};

int main() {
    string s;
    cin >> s;
    Solution S;
    cout << S.numDecodings(s) << endl;
    return 0;
}