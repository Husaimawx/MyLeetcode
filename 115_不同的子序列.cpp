#include <iostream>
#include <string.h>
using namespace std;

// 又是一道一看题目就知道是动态规划的题，也是一道没看题解做出来的dp
// 花了两个小时，虽然知道是dp但是就是找不到转移方程，最后终于通过手写dp矩阵，找规律做出来了：
//  如果s[i] == t[j]
//      则dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//  否则
//      dp[i][j] = dp[i-1][j];
// 中间还遇到了个小插曲，爆了int之后我换成long和long long还是不对，结果最后用unsigned就过了。

class Solution {
public:
    unsigned ** dp;
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (m < n)
        {
            return 0;
        }
        
        if (s == t)
        {
            return 1;
        }
        
        dp = new unsigned* [m+1];
        for (int i = 0; i < m+1; i++)
        {
            dp[i] = new unsigned[n+1];
            memset(dp[i], 0, sizeof(int) * (n+1));
        }
        
        dp[0][0] = 1;
        for (int i = 1; i < m+1; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n+1; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                if (i < j)
                {
                    continue;
                }
                
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    // cout << i << " " << j << " " << dp[i][j] << endl;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }

        // for (int i = 1; i < m+1; i++)
        // {
        //     for (int j = 1; j < n+1; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        
        return dp[m][n];

    }
};


int main() {
    string s, t;
    s = "rabbbit";
    t = "rabbit";
    Solution S;
    cout << S.numDistinct(s, t) << endl;
    return 0;
}